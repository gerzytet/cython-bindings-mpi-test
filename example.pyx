cimport cexample
from mpi4py import MPI as mpi

comm = mpi.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()
print(f'rank={rank} size={size}')

def send():
    cdef int crank = rank
    cdef int rtn
    with nogil:
        rtn = cexample.send_(crank)
    return rtn

def recieve():
    cdef int crank = rank
    cdef int csize = size
    cdef int rtn
    with nogil:
        rtn = cexample.recieve(crank, csize)
    return rtn
