#include <iostream>
int operation(int, int, char); //Function prototype
void input()
{
	std::cout << "=== Simple Calculator ===\n";
	std::cout << "Enter first number: ";
	int firstNum{};
	std::cin >> firstNum;
tryOperatorAgain:
	std::cout << "Enter operator (+, -, *, /): ";
	char op{};
	std::cin >> op;
	if (op != '+' && op != '-' && op != '*' && op != '/')
	{
		std::cout << "Invalid operator, please input operator valid!\n";
		goto tryOperatorAgain;
	}
	std::cout << "Enter second number: ";
	int secondNum{};
	std::cin >> secondNum;
	//resole situation divison by zero
	if (secondNum == 0 && op == '/')
	{
		std::cout << "Error: Division by zero is not allowed!";
		return;
	}
	std::cout << "Result: " << firstNum << ' ' << op << ' ' << secondNum << " = " << operation(firstNum, secondNum, op) << '\n';
}
int operation(int firstNum, int secondNum, char op)
{
	switch (op)
	{
	case '+':
		return firstNum + secondNum;
	case '-':
		return firstNum - secondNum;
	case '*':
		return firstNum - secondNum;
	case '/':
	{
		return firstNum / secondNum;
	}
	}
	return 0;
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