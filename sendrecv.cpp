#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	const int iCartDim[3] = {1,1,8};
	const int iCartPeriods[3] = {1, 1, 0};
	
	MPI_Init( &argc , &argv );
	MPI_Comm cartcomm;
	MPI_Cart_create( MPI_COMM_WORLD , 3 , iCartDim , iCartPeriods , 1 , &cartcomm);

	int src;
	int dst;
	int rank;

	MPI_Comm_rank(cartcomm, &rank);
	MPI_Cart_shift(cartcomm, 2, +1, &src, &dst);
	//printf("src : %2d -> %2d -> dst : %2d\n", src, rank, dst);

	int iSendBuf = 0;
	int iSendCount = 1;
	int iRecvBuf = 0;
	int iRecvCount = 1;
	MPI_Status Status;

	MPI_Sendrecv(&iSendBuf, iSendCount, MPI_INT, dst, 555,
				 &iRecvBuf, iRecvCount, MPI_INT, src, 555, 
				 cartcomm, &Status);

	std::cout << src << "  -> " << rank << " -> " << dst << " RecvData : " << iRecvBuf <<std::endl;
	MPI_Finalize();
}
