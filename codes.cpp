


#include<iostream>
#include<fstream>
#include<cmath>
#include<thread>
#include<ctime>
using namespace std;

void writeRoots();
void writeSquares();

int main()
{
	clock_t start;
	clock_t end;

	cout << "main: startup\n\n";

	cout << "Waiting for file thread\n\n";

	start = clock();

	thread firstThread(writeRoots);
	thread secondThread(writeSquares);
	firstThread.join();
	secondThread.join();

	cout << "main: done\n\n";

	end = clock();

	cout << "Runtime with threads = " << (end - start) / CLK_TCK << " seconds.\n\n";


	system("pause");
	return 0;
}


void writeRoots()
{
	ofstream outfile;

	outfile.open("roots.txt");

	cout << "Writing 1,000,000 square roots to a file\n\n";

	for (int i = 1; i <= 1000000; i++)
	{
		outfile << sqrt(i) << endl;
	}

	outfile.close();

	cout << "The square roots are ready.\n\n";
}



void writeSquares()
{
	ofstream outfile;

	outfile.open("squares.txt");

	cout << "Squaring 1,000,000 numbers\n\n";

	for (int i = 1; i <= 1000000; i++)
	{
		outfile << i * i << endl;
	}

	outfile.close();

	cout << "The squraes are ready.\n\n";
}
