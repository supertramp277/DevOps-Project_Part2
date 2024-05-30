Bootstrap: docker
From: ubuntu:20.04

%labels
    Author "Yanlong Wang"
    Version "1.0"

%files
    # Copy the entire project from the GitHub workspace into /opt/matrix_mult in the container
    . /opt/matrix_mult

%post
    # Install necessary dependencies
    apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
        mpich \
        libmpich-dev \
        cmake \
        build-essential \
        git \
        && rm -rf /var/lib/apt/lists/*

    # Set permissions for the project directory
    chmod -R 777 /opt/matrix_mult

    # Navigate to the project directory
    cd /opt/matrix_mult

    # Build the project
    mkdir build && cd build
    cmake ..
    make

%test
    # Set permissions for the testing directory
    chmod -R 777 /opt/matrix_mult/build/Testing

    cd /opt/matrix_mult/build
    ctest

%runscript
    exec /opt/matrix_mult/build/MatrixMultiplication
