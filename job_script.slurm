#!/bin/bash

# Set job name
#SBATCH --job-name=matrix_mult_job       # Job name

# Redirect output and error
#SBATCH --output=matrix_mult_output.txt  # Output file
#SBATCH --error=matrix_mult_error.txt    # Error file

# Set Parameters
#SBATCH --time=0:10:00                   # Time Limit (hh:mm:ss)   
#SBATCH --ntasks=2                       # Number of tasks
#SBATCH --nodes=1                        # Number of nodes
#SBATCH --partition=g100_all_serial      # Partition to submit job

# -------------------------------------------------------------------------------------
# Core Work Of This Job File: Do matrix multiplication by using MPI (2 tasks).
# -------------------------------------------------------------------------------------


# Load Singularity module
export TMPDIR=/tmp
module load singularity/3.8.0

# Run the main program using MPI
singularity exec ~/seproject//matrix_mult.sif mpiexec -np 2 ~/seproject//main
