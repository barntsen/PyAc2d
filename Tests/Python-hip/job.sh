#!/bin/bash -l
#SBATCH --job-name=gpuport   # Job name
#SBATCH --output=log.txt     # Name of stdout output file
#SBATCH --error=log.txt      # Name of stderr error file
#SBATCH --partition=small-g  # Partition (queue) name
#SBATCH --nodes=1            # Total number of nodes 
#SBATCH --ntasks-per-node=1  # tasks per node
#SBATCH --gpus-per-node=1    # Allocate one gpu per MPI rank
#SBATCH --time=00:30:00      # Run time (d-hh:mm:ss)
#SBATCH --account=project_465000260  # Project for billing
###SBATCH --mail-user=username@domain.com
###SBATCH --mail-type=all    # Send email at begin and end of job

#Run the job

export HSA_XNACK=0
./mk.sh
