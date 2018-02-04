#include "mpi.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	const int iCartDim[3] = {1,1,4};
	const int iCartPeriods[3] = {1, 1, 0};
	const int reorder = 1;
	
	MPI_Init( &argc , &argv );
	MPI_Comm cartcomm;
	MPI_Cart_create( MPI_COMM_WORLD , 3 , iCartDim , iCartPeriods , reorder , &cartcomm);

	int src;
	int dst;
	int rank;

	MPI_Comm_rank(cartcomm, &rank);
	MPI_Cart_shift(cartcomm, 2, +1, &src, &dst);
	printf("src : %2d -> %2d -> dst : %2d\n", src, rank, dst);
	MPI_Finalize();
}
