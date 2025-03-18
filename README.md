**Install MPI**

sudo apt update
sudo apt install openmpi-bin libopenmpi-dev


**Compile Mpi**

mpicc hello.c -o hello


**Check number of cores available cpu**

nproc

or

lscpu

top or htop



**Run MPI**

mpirun -np 4 ./hello



**Compile and run pi.c**

gcc  pi.c -o pi
./pi



**Compile and run parallel_pi.c**


mpicc -o parallel_pi parallel_pi.c
mpirun -np 4 ./parallel_pi


