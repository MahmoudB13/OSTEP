#include "types.h"
#include "user.h"

int main(int argc, char** argv)
{
	if(argc!=1)
		printf(1, "hello, my name is %s\n", argv[1]);
	else
		printf(1, "hello, my name is %s\n", argv[0]);
	exit();
}
