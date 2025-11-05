#include <iostream>
using namespace std;

int main()
{
	FILE* ptrOutFile;
	const char* path = "File.dat";

	const int N = 10;
	double arr[N];
	for (size_t i = 0; i < N; i++)
	{
		arr[i] = (rand() % 100) / 10.0;
		cout << arr[i] << " ";
	}
	cout << endl;


	fopen_s(&ptrOutFile, path, "wb+");

	if (ptrOutFile == NULL)
	{
		cout << "File can`t be created";
		return 1;
	}

	else
	{
		fwrite(arr, sizeof(double), N, ptrOutFile);
		fseek(ptrOutFile, 0, SEEK_SET);
		double s[N];
		fread(s, sizeof(double), N, ptrOutFile);
		for (size_t i = 0; i < N; i++)
		{
			cout << s[i] << " ";
		}
		fclose(ptrOutFile);
	}
}