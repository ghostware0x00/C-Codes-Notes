#include<stdio.h>
#include<stdlib.h>
#define FAIL "\x1b[1;91m" // Failure messages (USE ANSII ESCAPE CODES) syntax => "\x1b[1;COLOR_CODEm" the 1; => to apply contrast bold effect
#define SUCCESS "\x1b[1;92m"// success messages
#define WARNING "\x1b[1;93m"// warning agesmess

void elf_corrupt(FILE *fileptr){// function to display msg when elf binary file bytes are corrupted
	printf(FAIL "[x]ELF file corrupted\n");
	fclose(fileptr);
	exit(0);
}

void arch_endian_version(unsigned char mag[], FILE *fileptr){ // check architecture, endiannes, version
	if((mag[4] != 0x1 && mag[4] != 0x2) || (mag[5] != 0x1 && mag[5] != 0x2) || (mag[6] != 0x1))
		elf_corrupt(fileptr);
	if(mag[4] == 0x1)// architecture(class) 0x1 = 32bit 0x2 = 64bit
		printf(SUCCESS "\tClass : ELF32\n");
	else
		printf(SUCCESS "\tClass : ELF64\n");
	if(mag[5] == 0x1)// data 0x1 = little 0x2 = big
		printf(SUCCESS "\tData : little endian\n");
	else
		printf(SUCCESS "\tData : big endian\n"); // mag[6]
	printf(SUCCESS "\tVersion : 0x1\n");
}

void os_abis_version(unsigned char mag[], FILE *fileptr){// function to find os_abis, abis_version
	//byte 7 -15 is os, abi, abi_version
	// based on the value the abi follows that os abi rules
	// os_abis indicate what operating system abi rules does this particular abi follow. so if 0x3 = Linux then, the abi follows linux abi rules
	if(mag[7] != 0x0 && mag[7] != 0x1 && mag[7] != 0x2 && mag[7] !=0x3 && mag[7] != 0x6 && mag[7] != 0x9)
		elf_corrupt(fileptr);
	if(mag[7] == 0x0)
		printf(SUCCESS "\tOS/ABI : UNIX - SYSTEM V\n");
	else if(mag[7] == 0x1)
		printf(SUCCESS "\tOS/ABI : HP-UX\n");
	else if(mag[7] == 0x2)
		printf(SUCCESS "\tOS/ABI : NetBSD\n");
	else if(mag[7] == 0x3)
		printf(SUCCESS "\tOS/ABI : Linux\n");
	else if(mag[7] == 0x6)
		printf(SUCCESS "\tOS/ABI : Solaris\n");
	else if(mag[7] == 0x9)
		printf(SUCCESS "\tOS/ABI : FreeBSD\n");
	printf(SUCCESS "\tABI Version : %d\n",mag[8]);// abi version
}

void elfHeader(char *filename){// here program accepts only 1 string and char * means the pointer starts from the first character of the string until it hits null terminator
	FILE *fileptr;
	fileptr = fopen(filename, "rb"); // reading binary file
	if(fileptr == NULL){
		perror(FAIL "[-]file open failed.\n");
		exit(0);
	}
	unsigned char mag[18];// 7 chars = 7 bytes for storing first 4 bytes(magic bytes) and the rest 3 bytes for architecture, endianness, version. unsigned to avoid sign bit interpretations
	fread(&mag, 1, sizeof(mag), fileptr); // reads total 4 bytes (1 byte each). args2 = 1 byte args3 = sizeof(mag) which is 4 so 1 x 4 = 4 bytes total
	// [7F 45 4C 46] magic bytes of an elf binary
	unsigned char magic_bytes[] = {0x7f, 0x45, 0x4c, 0x46}; // unsigned to avoid sign bit interpretations
	/*
	so raw byte is in 0s and 1s
	compiler sees hex value 0x
	converts it to its corresponding 0s and 1s
	compares the fread raw each bytes with the 0s and 1s of the hex value
	*/
	for(int i=0; i<4; i++){
		if(mag[i] != magic_bytes[i]){
			printf(FAIL "[x]Not ELF Binary\n");
			fclose(fileptr);
			exit(0);
		}
	}
	printf(SUCCESS "[*]ELF Binary\n");
	printf(SUCCESS "ELF Header :\n");
	arch_endian_version(mag, fileptr);
	os_abis_version(mag, fileptr);
	fclose(fileptr);
	return;
}

int main(int argc, char *argv[]){
	// c doesnt have a string variable
	// so we use (char *) to point to the first character of the string in memory
	// [] used to store multiple arguments. Without [] if there is any space for like different args so it will only store the first arg until space encountered
	if(argc < 2 || argc > 2){
		printf(WARNING "[-]incorrect/missing arguments");
		exit(0);
	}
	elfHeader(argv[1]);
	// isStatic_Dynamic_Linked(argv[1]);
	return 0;
}