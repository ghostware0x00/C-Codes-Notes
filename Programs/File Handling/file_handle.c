#include<stdio.h>
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
	return 0;
}