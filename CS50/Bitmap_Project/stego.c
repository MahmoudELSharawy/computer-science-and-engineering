#include <stdio.h>
#include <stdlib.h>



// currently this just grabs the first 54bytes and throws them in header[]; this is the size of a 24bit bitmap
// header, the las do while was for testing and just prints each char on a newline with its index


int calculatePaddingBytes(long width) {
	int paddingFactor = 4 - ((width * 3) % 4);
	if (paddingFactor < 4) {
		return paddingFactor;
	}
	else {
		return 0;
	}
}	


int main (int argc, char *argv[]) {
	char header[54];
	int i = 0;
	int j = 0;
	long size = 0;
	char blue;
	char green;
	char red;
	FILE* inputF;
	inputF = fopen(argv[1], "r");



	fseek(inputF, 0L, SEEK_END);
	size = ftell(inputF);
	fseek(inputF, 0L, SEEK_SET);
	printf("File is %lu bytes long\n", size);




	
	if (inputF == NULL) {
		printf("Error");
	}
	else {
		do {
			fscanf(inputF, "%c", &header[i]);
			i ++;
		}
		while (i < 54);
	}

	/* The following loop will print the hex value for each byte of the header 
	 * numbered from first byte to fifty-fourth byte. It was usefull to see that
	 * I was consuming the entire header. It will also be useful to see the exact
	 * position of the line length marker with out having to look at my bitmap notes.
	 * 
	 */
	
	
	/*
		do {
			printf("%d %x\n", j+1, header[j] & 0xff );
			j++;
		} 
		while (j < 54);

	*/

	fscanf(inputF, "%c", &blue);
	fscanf(inputF, "%c", &green);
	fscanf(inputF, "%c", &red);
	printf("First Pixel Color Values:\nRed: %d Green: %d Blue: %d \n", red, green, blue);


	
	return 0;


	
}
