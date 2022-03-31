cdef extern from "./cexample.h":
    int send_(int rank) nogil
    int recieve(int rank, int size) nogil
