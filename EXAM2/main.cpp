/*
* Date: 11/7/2023
* Name: Armando Orozco
* Description:
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "input.h"

//costants
double const PI = 3.1415926535898;

//outputs
void outputHeaderTable();

//General functions
void getSmallestAndLargestSorted(vector<double> vData, string figure);
void getSmallestAndLargestUnsorted(vector<double> vData, string figure);

//Circle
double getCircumference(double radius);
double getRadius(double area);
double getDiameter(double radius);
double getAverageCircle(vector<double> vData);
void readDataFileStoreIntoCircleArray(vector<double>& vData);
void displayCircles(vector<double> vData);
void displaySortedCircles(vector<double> vData);
void displayCircleMenuOption(vector<double>& vData);

// Equilateral Triangle
double getSideLengthTriangle(double Area);
double getPerimeterTriangle(double sideLength);
double getHeightTriangle(double sideLength);
double getAverageTriangle(vector<double> vData);
void readInputDataFileStoreIntoTriangleArray(vector<double>& vData);
void displaySortedTriangleData(vector<double> vData, bool sortOption);
void displayTriangleData(vector<double> vData, bool sortOption);
void displayTriangleMenuOption(vector<double>& vData);

//Square
double getSideLengthSquare(double Area);
double getPerimeterSquare(double sideLength);
double getDiagonalLengthSquare(double sideLength);
double getAverageSquare(vector<double> vData);
void readInputDataFileStoreIntoSquareArray(vector<double>& vData);
void displaySquareData(vector<double> vData, bool sortOption);
void displaySortedSquareData(vector<double> vData, bool sortOption);
void displaySquareMenu(vector<double>& vData);

//Pentagon
double getSideLengthPentagon(double Area);
double getPerimeterPentagon(double sideLength);
double getDiagonalLengthPentagon(double sideLength);
double getAveragePentagon(vector<double> vData);
void displaySortPentagonData(vector<double> vData, bool sortOption);
void displayPentagonData(vector<double> vData, bool sortOption);
void readInputDataFileStoreIntoPentagonArray(vector<double>& vData);

//Hexagon
double getSideLengthHexagon(double Area);
double getPerimeterHexagon(double sideLength);
double getAverageHexagon(vector<double> vData);
void readInputDataFileStoreIntoHexagonArray(vector<double>& vData);
void displaySortedHexagonData(vector<double> vData, bool sortOption);
void displayHexagonData(vector<double> vData, bool sortOption);
void displayHexagonMenu(vector<double>& vData);

//======================MAIN=====================
int main()
{
	vector<double> vCircles;

	cout << setprecision(5) << fixed << showpoint;

	do
	{
		system("cls");
		cout << "\n\t\tIn geometry, A two-dimensional (2D) can be defined as a flat figure or shape that has\n"
			<< "\t\tonly two dimensions - length and width. 2D shapes do not have any thickness.\n";
		cout << "\n\t\tCMPR120 Exam#2 - 2D Geometry by Armando Orozco\n";
		cout << "\t\t" + string(80, char(205));
		cout << "\n\t\t  A. Circles";
		cout << "\n\t\t  B. Equilateral Triangles ";
		cout << "\n\t\t  C. Squares";
		cout << "\n\t\t  D. Regular Pentagons";
		cout << "\n\t\t  E. Regular Hexagons";
		cout << "\n\t\t" + string(80, char(196));
		cout << "\n\t\t  X. Exit";
		cout << "\n\t\t" + string(80, char(205));
		cout << "\n";

		switch (toupper(inputChar("\n\t\tOption: ",static_cast<string>("ABCDEX"))))
		{
		case 'A': // circle
			displayCircleMenuOption(vCircles);
			break;
		case 'X': exit(0);
		}
		system("pause");
	} while (true);
	cout << "\n";

	return EXIT_SUCCESS;

}

void outputHeaderTable()
{
	cout << setw(13) << right<<"index" 
		<< setw(18) << right <<"Area" 
		<< setw(20) << right <<"Circumference" 
		<< setw(20) << right <<"Diameter" 
		<< setw(20) << right <<"Radius" << '\n';

	cout << setw(13) << string(5, char(196))
		<< setw(18) << string(16, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196)) << '\n';

	return;
}

void getSmallestAndLargestSorted(vector<double> vData, string figure)
{
	cout << "\n\t\t*Smallest " + figure +" found at index " << 0;
	cout << "\n\t\t**Largest " + figure + " found at index " << vData.size()-1;
}

void getSmallestAndLargestUnsorted(vector<double> vData, string figure)
{
	double smallest = 0;
	double largest = vData.size()-1;

	for (int i = 0; i < vData.size(); i++)
	{
		smallest = (vData.at(smallest) < vData.at(i) ? smallest : i);
		largest = (vData.at(largest) > vData.at(i) ? largest : i);
	}

	cout << "\n\t\t*Smallest " + figure + " found at index " << smallest;
	cout << "\n\t\t**Largest " + figure + " found at index " << largest;
}

double getCircumference(double radius)
{
	return 2.f * (radius) * PI;
}

double getRadius(double area)
{
	return sqrt(area / PI);
}

double getDiameter(double radius)
{
	return radius * 2;
}

double getAverageCircle(vector<double> vData)
{
	double sum = 0;

	for (auto& data : vData)
		sum += data;

	return (sum) / vData.size();
}

void readDataFileStoreIntoCircleArray(vector<double>& vData)
{
	system("cls");
	vData = inputFileDouble(inputString("\n\t\tEnter the name of the file (Circles.txt): ", false));
	cout << '\t';
	return;
}

void displayCircles(vector<double> vData)
{
	if (vData.empty())
	{
		cout << "\n\t\tERROR: empty array\n";
		return;
	}

	cout << "\n\n";
	outputHeaderTable();

	for (int i = 0; i < vData.size(); i++)
	{
		cout << "\t" 
			<< setw(5) << right << i 
			<< setw(18) << right << vData.at(i) 
			<< setw(20) << right << getCircumference(getRadius(vData.at(i))) 
			<< setw(20) << right << getDiameter(getRadius(vData.at(i))) 
			<< setw(20) << right << getRadius(vData.at(i)) << '\n';
	}

	double average = getAverageCircle(vData);

	cout << '\n';
	cout << setw(13) << right<< "Average"
		<< setw(20) << right << average 
		<< setw(20) << right << getCircumference(getRadius(average)) 
		<< setw(20) << right << getDiameter(getRadius(average)) 
		<< setw(20) << right << getRadius(average) << '\n';

	getSmallestAndLargestUnsorted(vData, "circles");

}


void displaySortedCircles(vector<double> vData)
{
	if (vData.empty())
	{
		cout << "\n\tERROR: empty array\n";
		return;
	}

	sort(vData.begin(), vData.end());

	cout << "\n\n";
	outputHeaderTable();

	for (int i = 0; i < vData.size(); i++)
	{
		cout << "\t" 
			<< setw(5) << right << i 
			<< setw(20) << right << vData.at(i) 
			<< setw(20) << right << getCircumference(getRadius(vData.at(i))) 
			<< setw(20) << right << getDiameter(getRadius(vData.at(i))) 
			<< setw(20) << right << getRadius(vData.at(i)) << '\n';
	}

	double average = getAverageCircle(vData);

	cout << '\n';
	cout << "\n\tAverage" 
		<< setw(5) << right << average 
		<< setw(20) << right << getCircumference(getRadius(average)) 
		<< setw(20) << right << getDiameter(getRadius(average)) 
		<< setw(20) << right << getRadius(average) << '\n';

	getSmallestAndLargestSorted(vData, "circles");

}

void displayCircleMenuOption(vector<double>& vData)
{
	do
	{
		system("cls");
		cout << "\n\t\tA circle is a 2D shape that is made up of a curved line.It's round, and all points";
		cout << "\n\t\ton the curved line are an equal distance from the center point.";

		cout << "\n\t\tArray of Circles Menu";
		cout << "\n\t\t" + string(80, char(205));
		cout << "\n\t\t 1. Read data file";
		cout << "\n\t\t 2. Display unsorted data";
		cout << "\n\t\t 3. Display sorted data in ascending order";
		cout << "\n\t\t" + string(80, char(196));
		cout << "\n\t\t 0. return";
		cout << "\n\t\t" + string(80, char(205));

		switch (inputInteger("\n\t\t Option: ", 0, 3))
		{
		case 0: return;
		case 1: readDataFileStoreIntoCircleArray(vData); break;
		case 2: displayCircles(vData); break;
		case 3: displaySortedCircles(vData); break;
		}

		system("pause");
	} while (true);
}
