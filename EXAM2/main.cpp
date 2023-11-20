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


//General functions
void getSmallestAndLargestSorted(vector<double> vData, string figure);
void getSmallestAndLargestUnsorted(vector<double> vData, string figure);
double getAverage(vector<double>& vData);

//Circle
double getCircumference(double radius);
double getRadius(double area);
double getDiameter(double radius);
void displayHeaderTableCirles();
void displayEndOfTableCirles(double average);
void readDataFileStoreIntoCircleArray(vector<double>& vData);
void displayCircles(vector<double>& vData, bool sortOption);
void displayCircleMenuOption(vector<double>& vData);

// Equilateral Triangle
double getSideLengthTriangle(double Area);
double getPerimeterTriangle(double sideLength);
void displayHeaderTableTriangles();
void displayEndOfTableTriangles(double average);
void readInputDataFileStoreIntoTriangleArray(vector<double>& vData);
void displayTriangleData(vector<double> vData, bool sortOption);
void displayTriangleMenuOption(vector<double>& vData);

//header for pentagons and squares
void displayHeaderTableSquareAndPentagon();

//Square
double getSideLengthSquare(double Area);
double getPerimeterSquare(double sideLength);
double getDiagonalLengthSquare(double sideLength);
void displayEndOfTableSquare(double average);
void readInputDataFileStoreIntoSquareArray(vector<double>& vData);
void displaySquareData(vector<double>& vData, bool sortOption);
void displaySquareMenuOption(vector<double>& vData);

//Pentagon
double getSideLengthPentagon(double Area);
double getPerimeterPentagon(double sideLength);
double getDiagonalLengthPentagon(double sideLength);
void readInputDataFileStoreIntoPentagonArray(vector<double>& vData);
void displayPentagonData(vector<double> vData, bool sortOption);
void displayPentagonMenuOption(vector<double>& vData);


//Hexagon
double getSideLengthHexagon(double Area);
double getPerimeterHexagon(double sideLength);
void displayHeaderTableHexagon();
void displayEndOfTableHexagon(double average);
void readInputDataFileStoreIntoHexagonArray(vector<double>& vData);
void displayHexagonData(vector<double> vData, bool sortOption);
void displayHexagonMenuOption(vector<double>& vData);

//======================MAIN=====================
int main()
{

	cout << setprecision(5) << fixed << showpoint;

	do
	{//CHANGE NAMES WHEN SUMBMITTING
		vector<double> vData;
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
			displayCircleMenuOption(vData);
			break;
		case 'B': // trinangle
			displayTriangleMenuOption(vData);
			break;
		case 'C': // squares
			displaySquareMenuOption(vData);
			break;
		case 'D': // pentagons
			displayPentagonMenuOption(vData);
			break;
		case 'E': // hexagons
			displayHexagonMenuOption(vData);
			break;
		case 'X': exit(0);
		}
		system("pause");
	} while (true);
	cout << "\n";

	return EXIT_SUCCESS;

}

void displayHeaderTableCirles()
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

	cout << "\n\t* Smallest " + figure +" found at index " << 0;
	cout << "\n\t**Largest " + figure + " found at index " << vData.size()-1;
	cout << '\n';
	cout << '\n';

	return;
}

void getSmallestAndLargestUnsorted(vector<double> vData, string figure)
{
	int smallest = 0;
	int largest = vData.size()-1;

	//iterate the array to find the index of the smallest and largest area 
	for (int i = 0; i < vData.size(); i++)
	{
		smallest = (vData.at(smallest) < vData.at(i) ? smallest : i); //compare the actual minimun valuse with the current valuse and update
		largest = (vData.at(largest) > vData.at(i) ? largest : i); //compare the actual maximun valuse with the current valuse and update
	}

	//display the results
	cout << "\n\t*  Smallest " + figure + " found at index " << smallest;
	cout << "\n\t** Largest " + figure + " found at index " << largest;
	cout << '\n';
	cout << '\n';

	return;
}

double getAverage(vector<double>& vData)
{
	double sum = 0;

	//sum of every element in the array
	for (auto& data : vData)
		sum += data;

	//return the sum over the size to get the average
	return (sum) / vData.size();
}

//Circles
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

void displayEndOfTableCirles(double average)
{
	//diplay lines
	cout << setw(13) << string(5, char(196))
		<< setw(18) << string(16, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196)) << '\n';
	//display the values
	cout << setw(13) << right << "Average"
		<< setw(19) << right << average
		<< setw(19) << right << getCircumference(getRadius(average))
		<< setw(19) << right << getDiameter(getRadius(average))
		<< setw(19) << right << getRadius(average) << '\n';
	return;
}

void readDataFileStoreIntoCircleArray(vector<double>& vData)
{
	system("cls");
	vData = inputFileDouble(inputString("\n\t\tEnter the name of the file (Circles.txt): ", false)); // input the file
	cout << "\t\t";
	return;
}

void displayCircles(vector<double>& vData, bool sortOption)
{
	//check if the data of the array is empty
	if (vData.empty())
	{
		cout << "\n\tERROR: empty array\n";
		return;
	}

	//sort the array
	if (sortOption)
	{
		sort(vData.begin(), vData.end());
		cout << "\n\t\tSorted array of Circles";
	}else
		cout << "\n\t\tUnsorted array of Circles";

	//output
	cout << "\n\n";
	displayHeaderTableCirles();

	//output data
	for (int i = 0; i < vData.size(); i++)
	{
		cout << "\t" 
			<< setw(5) << right << i 
			<< setw(20) << right << vData.at(i) 
			<< setw(20) << right << getCircumference(getRadius(vData.at(i))) 
			<< setw(20) << right << getDiameter(getRadius(vData.at(i))) 
			<< setw(20) << right << getRadius(vData.at(i)) << '\n';
	}

	double average = getAverage(vData);

	//display the last part of the table
	displayEndOfTableCirles(average);

	//get the smallest and largest in the sorted array
	if(sortOption)
		getSmallestAndLargestSorted(vData, "circles");
	else
		getSmallestAndLargestUnsorted(vData, "circles");

	cout << "\t\t";
	return;
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
		case 0: cout << "\t\t\n"; return;
		case 1: readDataFileStoreIntoCircleArray(vData); break;
		case 2: displayCircles(vData,false); break;
		case 3: displayCircles(vData,true); break;
		}

		//wait for the user
		system("pause");
	} while (true);

	cout << "\t\t\n";
	return;
}

//Equilateral triangle
void displayHeaderTableTriangles()
{
	cout << setw(13) << right << "index"
		<< setw(20) << right << "Area"
		<< setw(20) << right << "Perimeter"
		<< setw(20) << right << "Side Length"
		<< '\n';

	cout << setw(13) << string(5, char(196))
		<< setw(20) << string(16, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196))
		<< '\n';

	return;
}

void displayEndOfTableTriangles(double average)
{
	double area = average;
	double side = getSideLengthTriangle(area);
	double perimeter = getPerimeterTriangle(side);

	cout << setw(13) << string(5, char(196))
		<< setw(20) << string(16, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196))
		<< '\n';

	cout << setw(13) << right << "Average"
		<< setw(20) << right << average
		<< setw(20) << right << perimeter
		<< setw(20) << right << side
		<< '\n';
	return;
}

double getSideLengthTriangle(double Area)
{
	return (2.f / 3.f) * pow(3, (3.f / 4.f)) * sqrt(Area);
}

double getPerimeterTriangle(double sideLength)
{
	return 3 * sideLength;
}

void readInputDataFileStoreIntoTriangleArray(vector<double>& vData)
{
	system("cls");
	vData = inputFileDouble(inputString("\n\t\tEnter the name of the file (Triangles.txt): ", false));
	cout << "\t\t";
	return;
}

void displayTriangleData(vector<double> vData, bool sortOption)
{
	//check if the data of the array is empty
	if (vData.empty())
	{
		cout << "\n\tERROR: empty array\n";
		return;
	}

	//sort the array
	if (sortOption)
	{
		sort(vData.begin(), vData.end());
		cout << "\n\t\tSorted array of Triangles";
	}
	else
		cout << "\n\t\tUnsorted array of Triangles";

	//output
	cout << "\n\n";
	displayHeaderTableTriangles();

	double area = 0;
	double side = 0;
	double perimeter = 0;

	//output data
	for (int i = 0; i < vData.size(); i++)
	{
		area = vData.at(i);
		side = getSideLengthTriangle(area);
		perimeter = getPerimeterTriangle(side);

		cout << "\t"
			<< setw(5) << right << i
			<< setw(20) << right << area
			<< setw(20) << right << perimeter
			<< setw(20) << right << side << '\n';
	}

	double average = getAverage(vData);

	//display the last part of the table
	displayEndOfTableTriangles(average);

	//get the smallest and largest in the sorted array
	if (sortOption)
		getSmallestAndLargestSorted(vData, "triangles");
	else
		getSmallestAndLargestUnsorted(vData, "triangles");

	cout << "\t\t";
	return;

}

void displayTriangleMenuOption(vector<double>& vData)
{
	do
	{
		system("cls");
		cout << "\n\t\tAn quilateral triangle is a 2D triangle shape whose all three sides are of equal length.\n";

		cout << "\n\t\tArray of Triangles Menu";
		cout << "\n\t\t" + string(80, char(205));
		cout << "\n\t\t 1. Read data file";
		cout << "\n\t\t 2. Display unsorted data";
		cout << "\n\t\t 3. Display sorted data in ascending order";
		cout << "\n\t\t" + string(80, char(196));
		cout << "\n\t\t 0. return";
		cout << "\n\t\t" + string(80, char(205));

		switch (inputInteger("\n\t\t Option: ", 0, 3))
		{
		case 0: cout << "\t\t\n"; return;
		case 1: readInputDataFileStoreIntoTriangleArray(vData); break;
		case 2: displayTriangleData(vData,false); break;
		case 3: displayTriangleData(vData,true); break;
		}

		//wait for the user
		system("pause");
	} while (true);

	cout << "\t\t\n";
	return;
}

//square
double getSideLengthSquare(double Area)
{
	return sqrt(Area);
}

double getPerimeterSquare(double sideLength)
{
	return sideLength * 4;
}

double getDiagonalLengthSquare(double sideLength)
{
	return sqrt(2.f)* sideLength;
}

void displayHeaderTableSquareAndPentagon()
{
	cout << setw(13) << right << "index"
		<< setw(20) << right << "Area"
		<< setw(20) << right << "Perimeter"
		<< setw(20) << right << "Diagonal"
		<< setw(20) << right << "Side Length"
		<< '\n';

	cout << setw(13) << string(5, char(196))
		<< setw(20) << string(16, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196))
		<< '\n';
}

void displayEndOfTableSquare(double average)
{
	double area = average;
	double side = getSideLengthSquare(area);
	double perimeter = getPerimeterSquare(side);
	double diagonal = getDiagonalLengthSquare(side);

	cout << setw(13) << string(5, char(196))
		<< setw(20) << string(16, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196))
		<< '\n';

	cout << setw(13) << right << "Average"
		<< setw(20) << right << average
		<< setw(20) << right << perimeter
		<< setw(20) << right << diagonal
		<< setw(20) << right << side
		<< '\n';
	return;
}

void readInputDataFileStoreIntoSquareArray(vector<double>& vData)
{
	system("cls");
	vData = inputFileDouble(inputString("\n\t\tEnter the name of the file (Squares.txt): ", false));
	cout << "\t\t";
	return;
}

void displaySquareData(vector<double>& vData, bool sortOption)
{
	//check if the data of the array is empty
	if (vData.empty())
	{
		cout << "\n\tERROR: empty array\n";
		return;
	}

	//sort the array
	if (sortOption)
	{
		sort(vData.begin(), vData.end());
		cout << "\n\t\tSorted array of Square";
	}
	else
		cout << "\n\t\tUnsorted array of Square";

	//output
	cout << "\n\n";
	displayHeaderTableSquareAndPentagon();

	double area = 0;
	double side = 0;
	double perimeter = 0;
	double diagonal = 0;

	//output data
	for (int i = 0; i < vData.size(); i++)
	{
		area = vData.at(i);
		double side = getSideLengthSquare(area);
		double perimeter = getPerimeterSquare(side);
		double diagonal = getDiagonalLengthSquare(side);

		cout << "\t"
			<< setw(5) << right << i
			<< setw(20) << right << area
			<< setw(20) << right << perimeter
			<< setw(20) << right << diagonal
			<< setw(20) << right << side << '\n';
	}

	double average = getAverage(vData);

	//display the last part of the table
	displayEndOfTableSquare(average);

	//get the smallest and largest in the sorted array
	if (sortOption)
		getSmallestAndLargestSorted(vData, "square");
	else
		getSmallestAndLargestUnsorted(vData, "square");

	cout << "\t\t";
	return;
}

void displaySquareMenuOption(vector<double>& vData)
{
	do
	{
		system("cls");
		cout << "\n\t\tA square is a 2D shape with four equal sides and four equal right angles.\n";

		cout << "\n\t\tArray of Squares Menu";
		cout << "\n\t\t" + string(80, char(205));
		cout << "\n\t\t 1. Read data file";
		cout << "\n\t\t 2. Display unsorted data";
		cout << "\n\t\t 3. Display sorted data in ascending order";
		cout << "\n\t\t" + string(80, char(196));
		cout << "\n\t\t 0. return";
		cout << "\n\t\t" + string(80, char(205));

		switch (inputInteger("\n\t\t Option: ", 0, 3))
		{
		case 0: cout << "\t\t\n"; return;
		case 1: readInputDataFileStoreIntoSquareArray(vData); break;
		case 2: displaySquareData(vData, false); break;
		case 3: displaySquareData(vData, true); break;
		}

		//wait for the user
		system("pause");
	} while (true);

	cout << "\t\t\n";
	return;
}

//Pentagon
double getSideLengthPentagon(double Area)
{
	return 2 * pow(5, (3.f / 4.f)) * (sqrt(Area) / (5 * (pow((sqrt(20) + 5), (1.f / 4.f)))));
}

double getPerimeterPentagon(double sideLength)
{
	return 5 * sideLength;
}

double getDiagonalLengthPentagon(double sideLength)
{
	return ((1 + sqrt(5)) / 2) * sideLength;
}

void readInputDataFileStoreIntoPentagonArray(vector<double>& vData)
{
	system("cls");
	vData = inputFileDouble(inputString("\n\t\tEnter the name of the file (Pentagons.txt): ", false));
	cout << "\t\t";
	return;
}

void displayPentagonData(vector<double> vData, bool sortOption)
{
	//check if the data of the array is empty
	if (vData.empty())
	{
		cout << "\n\tERROR: empty array\n";
		return;
	}

	//sort the array
	if (sortOption)
	{
		sort(vData.begin(), vData.end());
		cout << "\n\t\tSorted array of Pentagons";
	}
	else
		cout << "\n\t\tUnsorted array of Pentagons";

	//output
	cout << "\n\n";
	displayHeaderTableSquareAndPentagon();

	double area = 0;
	double side = 0;
	double perimeter = 0;
	double diagonal = 0;

	//output data
	for (int i = 0; i < vData.size(); i++)
	{
		area = vData.at(i);
		double side = getSideLengthPentagon(area);
		double perimeter = getPerimeterPentagon(side);
		double diagonal = getDiagonalLengthPentagon(side);

		cout << "\t"
			<< setw(5) << right << i
			<< setw(20) << right << area
			<< setw(20) << right << perimeter
			<< setw(20) << right << diagonal
			<< setw(20) << right << side << '\n';
	}

	double average = getAverage(vData);

	//display the last part of the table
	displayEndOfTableSquare(average);

	//get the smallest and largest in the sorted array
	if (sortOption)
		getSmallestAndLargestSorted(vData, "pentagon");
	else
		getSmallestAndLargestUnsorted(vData, "pentagon");

	cout << "\t\t";
	return;
}

void displayPentagonMenuOption(vector<double>& vData)
{
	do
	{
		system("cls");
		cout << "\n\t\t A regular pentagon is a closed 2D polygon shape made up of five straight equal sides.\n";

		cout << "\n\t\tArray of Pentagons Menu";
		cout << "\n\t\t" + string(80, char(205));
		cout << "\n\t\t 1. Read data file";
		cout << "\n\t\t 2. Display unsorted data";
		cout << "\n\t\t 3. Display sorted data in ascending order";
		cout << "\n\t\t" + string(80, char(196));
		cout << "\n\t\t 0. return";
		cout << "\n\t\t" + string(80, char(205));

		switch (inputInteger("\n\t\t Option: ", 0, 3))
		{
		case 0: cout << "\t\t\n"; return;
		case 1: readInputDataFileStoreIntoPentagonArray(vData); break;
		case 2: displayPentagonData(vData, false); break;
		case 3: displayPentagonData(vData, true); break;
		}

		//wait for the user
		system("pause");
	} while (true);

	cout << "\t\t\n";
	return;
}

//Hexagon
double getSideLengthHexagon(double Area)
{
	return pow(3, 1.f / 4.f) * sqrt(2 * (Area / 9.f));
}

double getPerimeterHexagon(double sideLength)
{
	return 6 * sideLength;
}

void displayHeaderTableHexagon()
{
	cout << setw(13) << right << "index"
		<< setw(20) << right << "Area"
		<< setw(20) << right << "Perimeter"
		<< setw(20) << right << "Side Length"
		<< '\n';

	cout << setw(13) << string(5, char(196))
		<< setw(20) << string(16, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196))
		<< '\n';
}

void displayEndOfTableHexagon(double average)
{
	double area = average;
	double side = getSideLengthHexagon(area);
	double perimeter = getPerimeterHexagon(side);

	cout << setw(13) << string(5, char(196))
		<< setw(20) << string(16, char(196))
		<< setw(20) << string(18, char(196))
		<< setw(20) << string(18, char(196))
		<< '\n';

	cout << setw(13) << right << "Average"
		<< setw(20) << right << average
		<< setw(20) << right << perimeter
		<< setw(20) << right << side
		<< '\n';
	return;
}

void readInputDataFileStoreIntoHexagonArray(vector<double>& vData)
{
	system("cls");
	vData = inputFileDouble(inputString("\n\t\tEnter the name of the file (Hexagons.txt): ", false));
	cout << "\t\t";
	return;
}

void displayHexagonData(vector<double> vData, bool sortOption)
{
	//check if the data of the array is empty
	if (vData.empty())
	{
		cout << "\n\tERROR: empty array\n";
		return;
	}

	//sort the array
	if (sortOption)
	{
		sort(vData.begin(), vData.end());
		cout << "\n\t\tSorted array of Hexagons";
	}
	else
		cout << "\n\t\tUnsorted array of Hexagons";

	//output
	cout << "\n\n";
	displayHeaderTableHexagon();

	double area = 0;
	double side = 0;
	double perimeter = 0;

	//output data
	for (int i = 0; i < vData.size(); i++)
	{
		area = vData.at(i);
		double side = getSideLengthHexagon(area);
		double perimeter = getPerimeterHexagon(side);

		cout << "\t"
			<< setw(5) << right << i
			<< setw(20) << right << area
			<< setw(20) << right << perimeter
			<< setw(20) << right << side << '\n';
	}

	double average = getAverage(vData);

	//display the last part of the table
	displayEndOfTableHexagon(average);

	//get the smallest and largest in the sorted array
	if (sortOption)
		getSmallestAndLargestSorted(vData, "hexagon");
	else
		getSmallestAndLargestUnsorted(vData, "hexagon");

	cout << "\t\t";
	return;
}

void displayHexagonMenuOption(vector<double>& vData)
{

	do
	{
		system("cls");
		cout << "\n\t\tA regular hexagon is a closed 2D polygon shape made up of six straight equal sides.\n";

		cout << "\n\t\tArray of Hexagons Menu";
		cout << "\n\t\t" + string(80, char(205));
		cout << "\n\t\t 1. Read data file";
		cout << "\n\t\t 2. Display unsorted data";
		cout << "\n\t\t 3. Display sorted data in ascending order";
		cout << "\n\t\t" + string(80, char(196));
		cout << "\n\t\t 0. return";
		cout << "\n\t\t" + string(80, char(205));

		switch (inputInteger("\n\t\t Option: ", 0, 3))
		{
		case 0: cout << "\t\t\n"; return;
		case 1: readInputDataFileStoreIntoHexagonArray(vData); break;
		case 2: displayHexagonData(vData, false); break;
		case 3: displayHexagonData(vData, true); break;
		}

		//wait for the user
		system("pause");
	} while (true);

	cout << "\t\t\n";
	return;
}
