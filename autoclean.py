#!/usr/bin/env python

'''
autoclean.py

Helper python script to clean up CMake
'''

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import os
import shutil
import argparse

from build_utils.python.logging import LOG_INFO, LOG_ERROR

def clean(project, arch):
    build_dir = os.path.join(project, 'build-{}'.format(arch))

    if os.path.exists(build_dir):
        shutil.rmtree(build_dir)
    else:
        LOG_ERROR('Could not find "{}"'.format(build_dir))

def main(project, arch):
    pwd = os.getcwd()

    if not os.path.exists(os.path.join(pwd, project)):
        LOG_ERROR('Project: "{}" does not exist'.format(project))
        return

    LOG_INFO('Cleaning project "{}"'.format(project))

    # Make the magic happen
    clean(project, arch)

    LOG_INFO('Done!')

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('project', nargs=1, type=str,
                        action='store', help='The project directory to build')
    parser.add_argument('-a', '--arch', type=str, action='store',
                        choices=['x86_64'], default='x86_64',
                        help='Architecture to build for')
    args = parser.parse_args()

    main(args.project[0], args.arch)
