#include <iostream>
#include <limits> //for std::numeric_limits
template <typename T, typename U, typename V>
auto operation(T x, U y, V z)
{
	if (z == '+')
	{
		return x + y;
	}
	else if (z == '-')
	{
		return x - y;
	}
	else if (z == '*')
	{
		return x * y;
	}
	else
		return x / y;
}

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
bool hasUnextractedInput()
{
	return !std::cin.eof() && std::cin.peek() != '\n';
}
bool clearFailedExtracted()
{
	if (!std::cin)
	{
		std::cin.clear();
		ignoreLine();
		return true;
	}
	return false;
}

void input()
{
	std::cout << "=== Simple Calculator ===\n";
	double firstNum{};
	while (true)
	{
		std::cout << "Enter first number: ";
		std::cin >> firstNum;
		if (clearFailedExtracted())
			continue; //has failed extracted
		if (hasUnextractedInput())
		{
			ignoreLine();
			continue;
		}
		break;
	}
	char op{};
	while (true)
	{
		std::cout << "Enter operator (+, -, *, /): ";
		std::cin >> op;
		if (clearFailedExtracted())
			continue;
		if (hasUnextractedInput())
		{
			ignoreLine();
			continue;
		}
		else
		{
			if (op != '+' && op != '-' && op != '*' && op != '/')
				continue;
			else
				break;
		}
	}
	double secondNum{};
	while (true)
	{
		std::cout << "Enter second number: ";
		std::cin >> secondNum;
		if (clearFailedExtracted())
			continue; //has failed extracted
		if (hasUnextractedInput())
		{
			ignoreLine();
			continue;
		}
		else
		{
			if (secondNum == 0.0 && op == '/')
			{
				ignoreLine();
				continue;
			}
			break;
		}
	}
	std::cout << "Result: " << firstNum << " " << op << " " << secondNum << " = " << operation(firstNum, secondNum, op) << '\n';
}
bool calculateAgain()
{
	char ans{};
	while (true)
	{
		std::cout << '\n';
		std::cout << "Would you like to calculate again (y/n)? ";
		std::cin >> ans;
		if (clearFailedExtracted())
			continue;
		if (hasUnextractedInput())
		{
			ignoreLine();
			continue;
		}
		else
		{
			if (ans != 'y' && ans != 'n')
			{
				ignoreLine();
				continue;
			}
			else
			{
				if (ans == 'y')
					return true;
				else if (ans == 'n')
				{
					std::cout << "Thanks you for use my calculation!\n";
					return false;
				}
			}
		}
	}
}

int main()
{
	//more modularity you make, more your code will be maintainable in the future.
	do
	{
		input();
		std::cout << '\n';

	} while (calculateAgain()); //don't forget function call operator, it's will give you memory address of function if you without them

	return 0;
}


