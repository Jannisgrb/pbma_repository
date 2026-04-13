#include <iostream>
#include "tausche.h"


void tausche(int *&eins, int *&zwei){
	int *temp;
	temp = eins;
	eins  = zwei;
	zwei = temp;

}