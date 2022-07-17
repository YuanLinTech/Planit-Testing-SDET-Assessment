#include <iostream>
using namespace std;

int main()
{
	char char_n[3];
	cout << "n = ";
	cin >> char_n; // Ask the user to enter the value of integer n (of type int) with a maximum value of 99.

	int n = 0;
	n = atoi(char_n); // Convert the string entered by the user to integer n.
	int i = 0;
	long long int Fib[100]; // Create an integer array to store the values of Fib[0] to Fib[99]
	Fib[0] = 0;
	Fib[1] = 1;

	// Get the nth number in the Fibonacci sequence given n
	for (i = 2; i < n + 1; i++)
	{
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	}

	switch (n) {
	case 1:
		cout << "The first number in the Fibonacci sequence is " << Fib[n] << endl;
		break;
	case 2:
		cout << "The second number in the Fibonacci sequence is " << Fib[n] << endl;
		break;
	case 3:
		cout << "The third number in the Fibonacci sequence is " << Fib[n] << endl;
		break;
	default:
		cout << "The " << n << "th number in the Fibonacci sequence is " << Fib[n] << endl;
	}

	/* Given a number F, print out whether it's a Fibonacci number
	and what the closest index n in the Fibonacci sequence is.*/

	char char_F[20];
	cout << "F = ";
	cin >> char_F; // Ask the user to enter the value of integer F (of type long long int) with a maximum value of 10^19-1 (19 "9"s)
	long long int F = 0;
	F = atoll(char_F); // Convert the string entered by the user to an integer.

	// Filling the rest of the 100 elements of the array Fib[100]
	for (i = 2; i < 100; i++) // Use "i=2" rather than "i=n+1" to avoid invalid read from Fib[-1].
	{
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	}

	// Check whether the number F is a Fibonacci number.
	n = 0;

	while (Fib[n] < F)
	{
		n++;
	}

	if (Fib[n] == F)
	{
		cout << "F = " << F << " is a Fibonacci number " << "with index n = " << n << endl;
	}
	else if (Fib[n] - F >= F - Fib[n - 1])
	{
		cout << "F = " << F << " is not a Fibonacci number." << endl;
		cout << "The closest index n in the Fibonacci sequence is " << n - 1 << endl;
	}
	else
	{
		cout << "F = " << F << " is not a Fibonacci number." << endl;
		cout << "The closest index n in the Fibonacci sequence is " << n << endl;
	}

	return 0;
}