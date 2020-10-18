/* 
Sharon Omenda
C++ Fall 2020
Due Oct 19 2020 11:59pm
Lab 4 Temperature Output
Description: Design a program that inputs a series of hourly temperature from a file, and outputs a barchart (using stars) of the temperatures.
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <filesystem>

using namespace std;
int main()
{
	const int minusRange = 30; // the least temperature in minus
	const int graphRange = 3; // 1 star will represent 3 degrees


	ifstream inputFile;
	//Uncomment any line to change data set file
	inputFile.open("TemperatureData.txt"); // reading directory
	//inputFile.open("TemperatureData2.txt");
	//inputFile.open("TemperatureData3.txt");
	string myText;

	getline(inputFile, myText); // to ignore first line
	string time, temperatureString;
	int valuetemp;
	cout << "Temperatures for 24 hours:\n";
	cout << "Time       Temperature         Graph\n"; // for headings

	while (getline(inputFile, time)) 
	{
		// this loop will read the file line by line
		temperatureString = time.substr(16, 3); // to get temperature after 16 characters in text file , 3 is max temp length
		cout << time << setw(2);

		valuetemp = stoi(temperatureString);
		int starCount = (valuetemp + minusRange) / graphRange; // finding star count as range is -30 to 120 and 3 degrees is equal to 1 star
		for (int i = 0; i < starCount; i++) // loop for printing stars
		{
			cout << "*";
		}
		cout << endl;
	}
	inputFile.close();
	system("pause");
	return 0;
}