#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Calculator
{
public:
	double add(double a, double b)
	{
		return a + b;
	}

	double subtract(double a, double b)
	{
		return a - b;
	}

	double divide(double a, double b)
	{
		if (b == 0)
		{
			cerr << "Error division not possible...";
			return -1;
		}

		return a / b;
	}

	double multiply(double a, double b)
	{
		return a * b;
	}
};

class ScientificCalculator : public Calculator
{
private:
	/**
	 * In C++ math trigonometric functions such as sin(), cos(), tan() uses radians.
	 * We use this function converts degrees to radians
	 *
	 */
	double toRadians(double degrees)
	{
		return degrees * M_PI / 180.0;
	}

public:
	double power(double base, double exponent)
	{
		return pow(base, exponent);
	}

	double logarithm(double value)
	{
		if (value <= 0)
		{
			cout << "Error: Required positive integers for logarithm";
			return -1;
		}

		return log(value);
	}

	double sine(double angle)
	{
		return sin(toRadians(angle));
	}

	double cosine(double angle)
	{
		return cos(toRadians(angle));
	}

	double tangent(double angle)
	{
		return tan(toRadians(angle));
	}

	void display()
	{
		int ch;
		int a, b;
		double base, exponent, valueL, angle;

		do
		{
			cout << "\n\n*** CALCULATOR ***\n";
			cout << "1. Add\n";
			cout << "2. Subtract\n";
			cout << "3. Divide\n";
			cout << "4. Multiply\n";
			cout << "5. Power\n";
			cout << "6. Logarithm\n";
			cout << "7. Sine (in degrees)\n";
			cout << "8. Cosine (in degrees)\n";
			cout << "9. Tangent (in degrees)\n";
			cout << "0. Exit\n";
			cout << "Enter your choice: ";
			cin >> ch;

			switch (ch)
			{
			case 1:
				cout << "Enter the first number: ";
				cin >> a;
				cout << "Enter the second number: ";
				cin >> b;
				cout << "The sum is: " << add(a, b) << "\n";
				break;
			case 2:
				cout << "Enter the first number: ";
				cin >> a;
				cout << "Enter the second number: ";
				cin >> b;
				cout << "The difference is: " << subtract(a, b) << "\n";
				break;
			case 3:
				cout << "Enter the first number: ";
				cin >> a;
				cout << "Enter the second number: ";
				cin >> b;
				cout << "The division result is: " << divide(a, b) << "\n";
				break;
			case 4:
				cout << "Enter the first number: ";
				cin >> a;
				cout << "Enter the second number: ";
				cin >> b;
				cout << "The multiplication result is: " << multiply(a, b) << "\n";
				break;
			case 5:
				cout << "Enter the base: ";
				cin >> base;
				cout << "Enter the exponent: ";
				cin >> exponent;
				cout << "The power result is: " << power(base, exponent) << "\n";
				break;
			case 6:
				cout << "Enter the value for logarithm: ";
				cin >> valueL;
				cout << "The logarithm is: " << logarithm(valueL) << "\n";
				break;
			case 7:
				cout << "Enter the angle in degrees: ";
				cin >> angle;
				cout << "The sine of the angle is: " << sine(angle) << "\n";
				break;
			case 8:
				cout << "Enter the angle in degrees: ";
				cin >> angle;
				cout << "The cosine of the angle is: " << cosine(angle) << "\n";
				break;
			case 9:
				cout << "Enter the angle in degrees: ";
				cin >> angle;
				cout << "The tangent of the angle is: " << tangent(angle) << "\n";
				break;
			case 0:
				cout << "Exiting the calculator...\n";
				break;
			default:
				cerr << "Error: Invalid choice. Please try again...\n";
			}
		} while (ch != 0);
	} // display
}; // class

int main()
{
	ScientificCalculator calc;
	calc.display();
}
