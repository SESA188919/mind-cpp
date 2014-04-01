#include "mainComponent.hpp"

// -----------------------------------------------------------------------------
// Implementation of the primitive main.
// -----------------------------------------------------------------------------

int out::main(int argc, char **argv) {

	unsigned char zdata[5];
	unsigned char size=0;

	zigbeeitf.Init();

	cluster.Init();
	cluster.serialize(&size, zdata);

	zigbeeitf.DataRequest(zdata);

	return 0;
}
