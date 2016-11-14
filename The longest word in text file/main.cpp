#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int MAX = 1024;
const char* FILE_TO_READ = "text.txt"; // path to your text file
const char* FILE_TO_WRITE = "word.txt"; // path to output file

void getMax(string &str){
	int maxCount = 1;
	string maxWord, temp;
	char charArray[MAX];
	strcpy(charArray, str.c_str());
	char *pch = strtok(charArray, " ,.-;:\n");
	while (true){
		pch = strtok(NULL, " ,.-;:\n");
		if (pch == NULL)
			break;
		temp = pch;
		if (maxCount < temp.length()){
			maxCount = temp.length();
			maxWord = temp;
		}
		else 
			continue;
	}
	cout << "Самое длинное слово: \"" << maxWord << "\", его длина равна " << maxCount << " символам." << endl;
	str = maxWord;
}

int main(int argc, char **argv){
	FILE *file;
	file = fopen(FILE_TO_READ, "r");
	if (file == NULL){
		fclose(file);
		printf("File not found\n");
	}
	else {
		char *buffer;
		fseek(file, 0, SEEK_END);
		int size = ftell(file);
		fseek(file, 0, SEEK_SET);
		buffer = (char*)malloc(size * sizeof(char));
		fread(buffer, 1, size , file);
		string str = buffer;
		getMax(str);
		fclose(file);
		file = fopen(FILE_TO_WRITE, "w");
		fprintf(file, "Самое длинное слово: %s, его длина равна %lu символам.\n", str.c_str(), str.length());
		fclose(file);
	}
	return 0;
}
