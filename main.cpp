#include "Components/OO-IO/MPXV7002.h"

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
}
