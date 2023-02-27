#  PyAc2d - GPu accelerated library for 2D Visco-Acoustic wave propagation

PyAc2d is a python library with a set of objects and methods for performing
2D acoustic Wave propagation using the Finite-Difference method.
The stress-velocity Finite-Difference formulation is used, with visco-acoustic
stress-strain relation and dynamic (time-dependent) effective density.
This formulation allows boundary conditions to be created by tapering
the Q-model at the edges, with no special code at the boundaries.
The boundary conditions are shown to be equivalent to the 
Perfectly-Matched-Layer (PML) method.

The core function are written in a Domain Specific Language (DSL) 
called Eps.
Eps is capable of automatic GPU acceleration,
and the same source code can then be used for both CPUs and GPUs.

## Installation
Clone the repo to a local directory.
To compile the code and run the tests clone also the 
[Eps](https://github.com/barntsen/Eps.git) repo and the python
[Utils](https://github.com/barntsen/Utils.git) repo.

## Directories

 - Ac2d       -Eps source code for the core library
 - Python-cpu -Python-bindings for running
                simulations on single core pu.
 - Python-cuda -Python-bindings for running
                simulations on a single nvidia gpu.
 - Python-cuda -Python-bindings for running
                simulations on multicore cpu using OpenMP.
 - Tests       -Example scripts for running simulations
                on single and multicore cpus and nvidia gpu.
 - Doc         -Documentation of the finite-difference method
                and code.
