**Install MPI**

sudo apt update
sudo apt install openmpi-bin libopenmpi-dev



**Check number of cores available cpu**

nproc or lscpu

** Check current processes**

top or htop


**Compile and run script.c**

gcc  script.c -o script
./script



**Compile MPI and run script.c**


mpicc -o script script.c
mpirun -np 4 ./script


