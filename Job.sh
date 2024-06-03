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

# Set TMPDIR to a writable directory (We have mkdir ~/tmp in advance so no need to create it) 
export TMPDIR=~/tmp

# Set Open MPI environment variables to use the TMPDIR, which is a writable directory.
export OMPI_MCA_tmpdir_base=$TMPDIR
export OMPI_MCA_orte_tmpdir_base=$TMPDIR
export OMPI_MCA_plm_rsh_agent="ssh :rsh"

# Module Load for Singularity
module load singularity

# -----------------------------------------------------------------------------
# Core Work Of This Job File: Do matrix multiplication by using MPI (2 tasks).
# -----------------------------------------------------------------------------
srun singularity exec ~/seproject/matrix_mult.sif mpiexec -np 2 ~/seproject/main
