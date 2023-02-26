#  Ac2d - 2D Acoustic Finite-Difference simulation of seismic waves

This directory contains the source files for the Ac2d simulation library.
The library is written in a smal Domain Specific Language (DSL)
and converted to either standard c, CUDA or c with OpenMP pragma's
using a source-to-source translator (transpiler). 
The transpiler is named eps and found in a separate github repo: 
[Eps](https://www.example.com)

## List of source files
- mk.sh   : Script for compiling the source code
- clean.sh: Clean script
- ac2d.e  : Solver object
- ac2d.i  : Public ac2d object members
- diff.e  : Differentiator object
- diff.i  : Public diff object members
- model.e : Model object
- model.i : Public model object members
- rec.e   : Receiver object
- rec.i   : Public receiver object members
- src.e   : Public source object members 
- src.i   : Public 
- ac2dmod.e : Example code to run the library


## Tests

The Test directory contains simple tests
and plotting routines for initial verification.


