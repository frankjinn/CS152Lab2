#!/bin/bash

# Directory Paths (adjust these as needed)
TESTDIR="/scratch/cs152-aez/cs152-lab2-sp25/lab/directed"
SIMDIR="/scratch/cs152-aez/cs152-lab2-sp25/sims/verilator"
BINARY="${TESTDIR}/transpose.riscv"

# Block sizes to test
BLOCK_SIZES=(2 4 16 32 64)

# Compile and run for each block size
for B in "${BLOCK_SIZES[@]}"; do
    echo "Testing B = $B..."
    
    # Update the source file with the current block size
    sed -i "s/#define B [0-9]\+/#define B $B/" ${TESTDIR}/transpose.c
    
    # Compile the binary
    (cd ${TESTDIR} && make)

    # Run the simulation
    cd ${SIMDIR}
    make CONFIG=CS152RocketConfig run-binary-hex BINARY=$BINARY
done

echo "Experiments completed"
