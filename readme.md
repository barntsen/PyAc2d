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
Run the mk.sh in the top directory.
The script will compile the c/cuda/hip code and
install a simple script (ac2dmod) for running simulations.

## Directories

 - Ac2d        -Eps and Python source code for the library
 - Python-c    -C code for the wave propagation library.
 - Python-cuda -Cuda code for the wave propagation library.
 - Python-hip  -Hip code for the wave propagation library.
 - Python-omp  -C code with openmp for the wave propagation library.
 - Scripts     -Support scripts for plotting, model creation etc..
 - Examples    -Simulation examples
 - Tests       -Simple test cases
 - Doc         -Documentation of the finite-difference method
                and code.
 - Bin         -Python executable scripts
