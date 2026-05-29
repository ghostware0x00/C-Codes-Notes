#include<stdio.h>

struct threeSum{
	int n1, n2, n3, n4;
};

int main(){
	// to create a file open a file, read a file or write a file we need to declare a pointer named -> *FILE 
	// to open the file we use the fopen
	FILE *fileptr; // creating the file pointer
	fileptr = fopen("elf2", "w"); // "w" mode is to write inside a file. if the file doesnt exist the program will create it.
									// if you want to create a file to a specific folder just provide the absolute path.
									// problem with "w" mode is that it overwrites whatever content is inside the file with the new stuff you write using fprintf
	fprintf(fileptr, "lolbruh");// writing content inside the file.
	fclose(fileptr);// closing the file pointer is necessary
	FILE *fileptr2;
	fileptr2 = fopen("elf2", "a"); // opening file in "a" append mode 
									// this allows us to write inside the file without overwriting the content already present there.
	fprintf(fileptr2, "\nwhassup2\n");
	fclose(fileptr2);
	FILE *fileptr3;
	fileptr3 = fopen("elf2", "r");
	if(fileptr3 == NULL){	// good practice to check whether we were able to open file or not.
		printf("not able to open file");
	}
	char read_data[100];// 100 characters so 1 char = 1 byte hence 100 characters = 100 bytes.
	printf("fileptr3 reading content ----->\n");
	fgets(read_data, 100, fileptr3);	// fgets is used to read contents from a input or from a file.
	// better than gets() which causes buffer overflow because fgets prevents buffer overflow by specifying the max number of characters to read
	// problem with reading files like this is that if newline is encountered \n then only the first line will be stored.
	// fgets (<variable where file_content to store>, <max number of characters to read>, <file pointer variable>)
	printf("%s", read_data);
	fclose(fileptr3);
	FILE *fileptr4;
	fileptr4 = fopen("elf2", "r");
	if(fileptr3 == NULL){	// good practice to check whether we were able to open file or not.
		printf("not able to open file");
	}
	char read_data2[100];
	printf("fileptr4 reading content ----->\n");
	while(fgets(read_data2, 100, fileptr4)){ // reading files like these stores the file contents including new line contents.
		printf("%s", read_data2);
	}

	// check the geeksfogeeks for binary file handling in c [https://www.geeksforgeeks.org/c/basics-file-handling-c/]
	FILE *fileBinaryWrite;
	struct threeSum sum;
	fileBinaryWrite = fopen("hello.bin", "wb"); // "wb" means write binary file. 
	sum.n1 = 10;
	sum.n2 = 20;
	sum.n3 = 30;
	sum.n4 = sum.n1 + sum.n2 + sum.n3;
	int flag = 0;
	flag = fwrite(&sum, sizeof(struct threeSum), 1, fileBinaryWrite);
	// writing to a binary file using fwrite()
	// fwrite args -> fwrite(<pointer to data>, <size of one element>, <number of elements>, <file pointer>)
	/*
	args1 requires the address of the memory block whose data will be written to the binary file.
	args2 specifies the size of each data element in bytes.
	args3 specifies how many such elements to write.
	args4 is the file pointer representing the binary file stream.
	*/
	// so basically in the program above in fwrite
	// i am writing 16 bytes(cuz 4 integers in struct) to flag variable
	// since there is only 1 instance of struct i am writing so 1.
	//if i wanted to write multiple instances so i can specify the number accordingly. So if 3 instances total size written would be 16 x 3 = 48 bytes to flag variable.
	// the flag variable is basically for status checking whether binary write succesfully happened or not. if flag = 1 then ok else not ok.
	printf("binary file write -------->\n");
	if(flag){// if fwrite works then flag value will change to 1
		printf("Write operation was successful\n");
	}
	else{
		printf("Write operation was unsuccessful\n");
	}
	fclose(fileBinaryWrite);
	FILE *fileBinaryRead;
	fileBinaryRead = fopen("hello", "rb"); // "rb" means read binary "hello"
	//fread(<memory destination>, <size of each element>, <number of elements>, <file pointer>);
	/*
	args1 requires the address of the memory block whose data will be written to the binary file.
	args2 specifies the size of each data element in bytes.
	args3 specifes how many elements to read
	args4 specifies the binary file pointer variable 
	*/
	fread(&sum, sizeof(struct threeSum), 1, fileBinaryRead);
	// here struct is 16 bytes so fread will read the first 16 bytes from the "hello" into the struct threeSum
	// the data will be stored inside the struct data members n1, n2, n3, n4
	printf("Reading binary file and storing binary data in struct ------>\n");
	printf("n1 = 0x%x\tn2 = 0x%x\tn3 = 0x%x\tn4 = 0x%x\n",sum.n1, sum.n2, sum.n3, sum.n4);// using struct variable displaying the data
	// data stored 4 byte per variable of struct cuz int = 4 bytes and total data to read = 16 bytes
	rewind(fileBinaryRead);
	unsigned char store[16]; // unsigned char is used because it preserves raw byte values exactly from 0x00 to 0xFF (0–255) without signed interpretation issues.
	fread(&store, sizeof(store), 1, fileBinaryRead);
	printf("Reading binary file and storing binary data in character array------>\n");
	for(int i=0; i<16; i++){
		printf("0x%x\n",store[i]);
	}
	fclose(fileBinaryRead);
	return 0;
}