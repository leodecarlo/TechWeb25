**Install MPI**

sudo apt update
sudo apt install openmpi-bin libopenmpi-dev



**Check number of cores available cpu**

nproc or lscpu

**Check current processes**

top or htop


**Compile and run script.c**

gcc  script.c -o script
./script



**Compile MPI and run script.c**


mpicc -o script script.c
mpirun -np 4 ./script


## Description of the Activity

By varying the number of points(10³,10⁵ and 10⁹), we will observe:

- That achieving a significant speed-up requires processing a sufficiently large amount of data; otherwise, the communication overhead outweighs the benefits of parallelization.
- How increasing the number of processes initially leads to a substantial speed-up, but eventually reaches a saturation point where additional processes no longer provide a performance advantage.