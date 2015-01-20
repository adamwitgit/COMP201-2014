#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{

	ifstream inf; ofstream outf; string filename; int x; int sum = 0;
	filename = string(argv[1]);

	inf.open(filename);
	if (inf.fail())
	{
		cout << "You did not enter in a valid file name. Sorry! " << endl;
		return 1;
	}

	cout << "x\tx^2\tCurrent Sum\n=\t===\t===========\n";

	while (inf >> x)
	{
		sum = sum + x;
		cout << x << "\t" << x*x << "\t" << sum << endl;
	}

	return 0;
}