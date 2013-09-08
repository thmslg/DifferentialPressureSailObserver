#include "Components/OO-IO/MPXV7002.h"

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class dummyADC : public SingleEndedADCInput{
public:
	dummyADC(unsigned int fullScaleValue,
			float fullScalleVoltage):
	SingleEndedADCInput(fullScaleValue,fullScalleVoltage)
	{

	}
};

int main()
{
	dummyADC pouet(1024,5);
	MPXV7002 dummySensor(pouet);

	int file;
	char *filename = "/dev/i2c-1";
	if ((file = open(filename, O_RDWR)) < 0) {
	    /* ERROR HANDLING: you can check errno to see what went wrong */
	    perror("Failed to open the i2c bus");
	    exit(1);
	}

	int addr = 0x68;          // The I2C address of the ADC
	if (ioctl(file, I2C_SLAVE, addr) < 0) {
	    printf("Failed to acquire bus access and/or talk to slave.\n");
	    /* ERROR HANDLING; you can check errno to see what went wrong */
	    exit(1);
	}

	//--------------------------------------------------------------------------------------------------------
	char buf[10] = {0};
	buf[0] = 0x9C;
	if (write(file,buf,1) != 1) {
	    /* ERROR HANDLING: i2c transaction failed */
	    printf("Failed to write to the i2c bus.\n");
	    printf("\n\n");
	}

	//--------------------------------------------------------------------------------------------------------

	float data;
	char channel;

	// Using I2C Read
	if (read(file,buf,2) != 2) {
		/* ERROR HANDLING: i2c transaction failed */
		printf("Failed to read from the i2c bus.\n");
	} else {
		printf("Read was successful");
	}
}
