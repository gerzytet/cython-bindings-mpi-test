#include <mpi.h>
#include <stdio.h>

int send_(int rank) {
    if (rank > 0) {
        int data = rank * 2;
        puts("not skipping send");
        int err = MPI_Send(&data, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD);
        printf("rank %d sending %d\n", rank, data);
        return err;
    } else {
        puts("skipping send");
    }
    return 0;
}

int recieve(int rank, int size) {
    if (rank < size-1) {
        int data;
        MPI_Status status;
        puts("not skipping recieve");
        int err = MPI_Recv(&data, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD, &status);
        printf("rank %d recieved %d\n", rank, data);
        return err;
    } else {
        puts("skipping recieve");
    }
    return 0;
}
/*
int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    send(rank);
    recieve(rank, size);

    MPI_Finalize();
}
*/