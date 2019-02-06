#!/usr/bin/env python

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import os
import sys
import shutil
import argparse
import subprocess

# Append to module search path
sys.path.append(os.getcwd())

from build_utils.python.logging import LOG_INFO, LOG_ERROR

# Configuration of build directories
config = {
    'build_utils_dir': 'build_utils',
    'toolchains_dir': 'toolchains'
}

def check_target(target):
    '''
    Checks if a target source file exists, else exits program
    '''
    if target is None:
        return

    if not os.path.exists(os.path.join(os.getcwd(), target)):
        LOG_ERROR('Target: "{}" does not exist'.format(target))
        sys.exit(1)
    LOG_INFO('Found target "{}"'.format(target))

def build(target, compiler, arch):
    toolchain_path = os.path.join(os.getcwd(), config['build_utils_dir'],
                                  config['toolchains_dir'])
    toolchain_name = '{}-{}-toolchain.cmake'.format(arch, compiler)
    toolchain_file = os.path.join(toolchain_path, toolchain_name)

    if not os.path.exists(toolchain_file):
        LOG_ERROR('Toolchain file not found')
        LOG_ERROR('Compiler: {}, Architecture: {}'.format(compiler, arch))
        return

    LOG_INFO('Building...')

    pwd = os.getcwd()
    os.chdir(target)

    build_dir = 'build-{}'.format(arch)
    if not os.path.exists(build_dir):
        os.mkdir(build_dir)
    os.chdir(build_dir)

    return_value = subprocess.run(['cmake', '..',
                                   '-DCMAKE_TOOLCHAIN_FILE={}'.format(toolchain_file),
                                   '-DCMAKE_INSTALL_PREFIX={}'.format('.')])
    if return_value.returncode != 0:
        return return_value.returncode

    return_value = subprocess.run(['make', 'install'])

    os.chdir(pwd)

    if return_value.returncode == 0:
        LOG_INFO('Done!')

def clean(target, arch):
    '''
    Cleans generated files
    '''
    if target is not None:
        shutil.rmtree(os.path.join(os.getcwd(),
                      os.path.join(target, 'build-{}'.format(arch))))
    LOG_INFO('Done!')

def main(command, target, compiler, arch):
    check_target(target)

    if command == 'build':
        build(target, compiler, arch)
    elif command == 'clean':
        LOG_INFO('Cleaning {}...'.format(target))
        clean(target, arch)
    else:
        LOG_ERROR('Command: "{}" is not supported yet!'.format(command))

if __name__ == "__main__":
    # Command line arguments
    parser = argparse.ArgumentParser()
    parser.add_argument('command', nargs=1, type=str,
                        action='store', help='The command to run',
                        choices=['build', 'clean', 'add'])
    parser.add_argument('target', nargs='?', type=str, action='store',
                        default=None,
                        help='The target path to build/clean')
    parser.add_argument('-c', '--compiler', type=str, action='store',
                        choices=['GNU', 'Clang'], default='Clang',
                        help='The compiler to use')
    parser.add_argument('-a', '--arch', type=str, action='store',
                        choices=['x86_64', 'aarch64', 'arm'], default='x86_64',
                        help='Architecture to build for')
    args = parser.parse_args()

    main(args.command[0], args.target, args.compiler.lower(), args.arch)
