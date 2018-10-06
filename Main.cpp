#include "SuperLong.h"
#include <iostream>
#include <string>

int main()
{
    // test adding
    {
        SuperLong a(125);
        SuperLong b(2590);
        SuperLong c;
        c.Add(a, b);
        std::cout << c.ToString() << std::endl;
        system("pause");
    }

    // test multiply
    {
        SuperLong a(1212359);
        SuperLong b(2566);
        SuperLong c;
        c.Multiply(a, b);
        std::cout << c.ToString() << std::endl;

        a.FromInt(2);
        b.FromInt(2);
        a.Multiply(b, a);
        std::cout << a.ToString() << std::endl;
        system("pause");
    }

    // test half
    {
        SuperLong a(145);
        int remainder = a.half();
        std::cout << a.ToString() << " " << remainder << std::endl;
        a.FromInt(56);
        remainder = a.half();
        std::cout << a.ToString() << " " << remainder << std::endl;
        system("pause");
    }

    // test power
    {
        SuperLong a(2);
        SuperLong b(3);
        SuperLong c;
        c.Power(a, b);
        std::cout << c.ToString() << std::endl;
        system("pause");
    }


    SuperLong answer;
	std::vector<int> powers;  //For saving the powers entered
	char enteredCharacter;
	int integer;

	//Prompting the user for power numbers
	std::cout << "Enter all numbers for the power-tower (finish by entering a !)" << std::endl;

	//Entering and emplacing all the numbers into a vector object 
	while (true) {
		std::cin >> enteredCharacter;
		if (enteredCharacter == '!') {
			break;
		}
		integer = enteredCharacter - 48;  //Converting character to integer
		powers.emplace_back(integer);
	} 

	//Calculate the power of another power :)
    answer.FromInt(powers.back());
    for (auto itr = powers.rbegin(); itr != powers.rend(); ++itr) {
        SuperLong base(*itr);
        answer.Power(base, answer);
		std::cout << "Debug: answer.ToString() = " << answer.ToString() << std::endl;
	}

	//Output the final value
	std::string outputString = answer.ToString();
	std::cout << outputString << std::endl;

	//End of program
	system("pause");

    return 0;
}
