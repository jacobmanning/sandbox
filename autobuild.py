#!/usr/bin/env python

'''
autobuild.py

Helper python script to set up CMake
'''

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import os
import argparse
import subprocess

from build_utils.python.logging import LOG_INFO, LOG_ERROR

build_utils_dir = 'build_utils'
toolchain_dir = 'toolchains'

def build(project, arch, toolchain, pwd):
    os.chdir(project)

    build_dir = 'build-{}'.format(arch)
    if not os.path.exists(build_dir):
        os.mkdir(build_dir)
    os.chdir(build_dir)

    subprocess.run(['cmake', '..',
                    '-DCMAKE_TOOLCHAIN_FILE={}'.format(toolchain),
                    '-DCMAKE_INSTALL_PREFIX={}'.format('.')])

    subprocess.run(['make', 'install'])

    os.chdir(pwd)

def main(project, compiler, arch):
    pwd = os.getcwd()

    if not os.path.exists(os.path.join(pwd, project)):
        LOG_ERROR('Project: "{}" does not exist'.format(project))
        return

    LOG_INFO('Found project "{}"'.format(project))

    toolchain_path = os.path.join(pwd, build_utils_dir, toolchain_dir)
    toolchain_name = '{}-{}-toolchain.cmake'.format(arch, compiler)
    toolchain_file = os.path.join(toolchain_path, toolchain_name)

    if not os.path.exists(toolchain_file):
        LOG_ERROR('Toolchain file not found')
        LOG_ERROR('Compiler: {}, Architecture: {}'.format(compiler, arch))
        return

    LOG_INFO('Building...')

    # Make the magic happen
    build(project, arch, toolchain_file, pwd)

    LOG_INFO('Done!')

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('project', nargs=1, type=str,
                        action='store', help='The project directory to build')
    parser.add_argument('-c', '--compiler', type=str, action='store',
                        choices=['GNU', 'Clang'], default='Clang',
                        help='The compiler to use')
    parser.add_argument('-a', '--arch', type=str, action='store',
                        choices=['x86_64'], default='x86_64',
                        help='Architecture to build for')
    args = parser.parse_args()

    main(args.project[0], args.compiler.lower(), args.arch)
