
#include "Record.h"

void saveRecord(int score) {

	ofstream file("record.txt");
	if (file.is_open()) {
		
		file << score;
		file.close();
	}
}


int loadRecord() {

	int recordScore = 0;
	ifstream file("record.txt");
	
	if (file.is_open()) {

		file >> recordScore;
		file.close();
	}

	return recordScore;
}
