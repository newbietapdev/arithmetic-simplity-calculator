#include <iostream>
#include <limits> //for std::numeric_limits
bool operate(char); //function prototype
void calculationMath(double, double, char);
void input()
{
	std::cout << "=== Simple Calculator ===\n";
	std::cout << "Enter first number: ";
	double firstNum{};
	std::cin >> firstNum;
	char op{};
	while (true)
	{
		std::cout << "Enter operator (+, -, *, /): ";
		std::cin >> op;
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		if (operate(op))
			break;
		else
			continue;
	}
	std::cout << "Enter second number: ";
	double secondNum{};
	std::cin >> secondNum;
	//resolve situation divison by zero
	if (op == '/' && secondNum == 0.0)
	{
		std::cout << "Error, this number cann't evenly divided by zero.\n";
		return;
	}
	calculationMath(firstNum, secondNum, op);
	return;
}
bool operate(char op)
{
		switch (op)
		{
		case '+': //fallthrough if one of which case-statement is true
		case '-':
		case '*':
		case '/':
			return true;
		default:
			std::cout << "You just have entered operator invalid, please try again!\n";
		}
		return false;
}
bool calculateAgain()
{
	while (true)
	{
		std::cout << '\n';
		std::cout << "Would you like to calculate again (y/n)? ";
		char ans{};
		std::cin >> ans;
		if (ans == 'y')
			return true;
		else if (ans == 'n')
			return false;
		else
			continue; //this-statement unecessary but with purpose more readable for reader
	}//if you input some character differ with 'y' and 'n' this loop will be repeated until you correctly type.
}
void calculationMath(double x, double y, char op)
{
	switch (op)
	{
	case '+':
	{
		std::cout << "Result: " << x << " + " << y << " = " << x + y;
		break;
	}
	case '-':
		std::cout << "Result: " << x << " - " << y << " = " << x - y;
		break;
	case '*':
		std::cout << "Result: " << x << " * " << y << " = " << x * y;
		break;
	case '/':
		std::cout << "Result: " << x << " / " << y << " = " << x / y;
		break;
	}
	return;
}
int main()
{
	//more modularity you make, more your code will be maintainable in the future.
	do
	{
		input();
		std::cout << '\n';

	} while (calculateAgain()); //don't forget function call operator, it's will give you memory address of function if you without them
	std::cout << "Thanks you for use my calculation!\n";
	return 0;
}
