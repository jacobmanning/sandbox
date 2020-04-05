# Sandbox

This repository is my sandbox to play around with nifty tools/libraries/etc.

## Build system
The repo uses a python-automated CMake build system.

#### Setting up the build system
The build system, `sandbox`, uses python to automate CMake. You can call commands as `python scripts/sandbox.py <arguments>` or set up an alias for `sandbox=python scripts/sandbox.py` via the shell script.
```bash
scripts/setup_paths.sh
```

#### Building a target
```
sandbox build <directory>
```
+ Can also specify a compiler or target architecture via flags

#### Cleaning a target
```
sandbox clean <directory>
```

#### Running a target
```
<directory>/build-<arch>/bin/<name>
```
+ **Note:** All CMake files go into `directory/build-<arch>`, it is up to CMake then to decide where the exectuables/libraries go
