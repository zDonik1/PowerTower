#include "SuperLong.h"

//SuperLong contructor
SuperLong::SuperLong()
{
    m_number.emplace_back(0);
}

SuperLong::SuperLong(int l_num)
{
    FromInt(l_num);
}

SuperLong::SuperLong(const std::vector<int> &l_num)
{
	m_number = l_num;
}

//Adds two SuperLong numbers and gives the answer to the object
void SuperLong::Add(SuperLong l_num1, SuperLong l_num2)
{
    auto maxSize = std::max(l_num1.m_number.size(), l_num2.m_number.size());

	if (l_num1.m_number.size() > l_num2.m_number.size()) {
		l_num2.FillZero(l_num1.m_number.size() - l_num2.m_number.size());
	}
	else if (l_num2.m_number.size() > l_num1.m_number.size()) {
		l_num1.FillZero(l_num2.m_number.size() - l_num1.m_number.size());
	}

    m_number.clear(); // IMPORTANT!

    int carry = 0;
    for (std::size_t i = 0; i < maxSize; ++i) {
        int tempAnswer = l_num1.m_number[i] + l_num2.m_number[i] + carry;
		carry = 0;
		if (tempAnswer > 9) {
			carry = 1;
            tempAnswer -= 10;
		} 
        m_number.emplace_back(tempAnswer);
	}

    if (carry == 1) {
        // say adding 8 + 7 = 15, so we just carry 1 and m_number will longer than maxSize
        m_number.emplace_back(carry);
    }
}

//Multiplies two SuperLong numbers and gives the answer to the object
void SuperLong::Multiply(SuperLong l_num1, SuperLong l_num2)
{
    m_number.clear(); // IMPORTANT!

    int shift = 0;
    for (auto digit2 : l_num2.m_number) {
        SuperLong tmpAnswer;
        tmpAnswer.m_number.clear();
        for (int i = 0; i < shift; ++i) {
            tmpAnswer.m_number.emplace_back(0);
        }
        int carry = 0;

        for (auto digit1 : l_num1.m_number) {
            int temp = digit1 * digit2 + carry;
            carry = temp / 10;
            int newDigit = temp % 10;
            tmpAnswer.m_number.emplace_back(newDigit);
        }

        if (carry > 0) {
            tmpAnswer.m_number.emplace_back(carry);
        }

        Add(*this, tmpAnswer);
        ++shift;
    }
}

//Finds the power of a base and gives the answer to the object
void SuperLong::Power(SuperLong l_base, SuperLong l_power)
{
	m_number.clear();
	if (l_power.m_number.size() == 1 && l_power.m_number.back() == 0) {
        (*this).FromInt(1);
        return;
	}

	SuperLong temp;
	SuperLong halfTmp = l_power;
    int remainder = halfTmp.half();
	temp.Power(l_base, halfTmp.m_number);

    if (remainder == 0) {
		(*this).Multiply(l_base, l_base);
	}
	else {
		temp.Multiply(temp, temp);
		(*this).Multiply(temp, l_base);
	}
}

//Halves the number inside m_number
int SuperLong::half()
{
	std::vector<int> temp = m_number;
	m_number.clear();
	int remainder = 0;
	for (auto digit = temp.rbegin(); digit != temp.rend(); ++digit) {
		int dividend = *digit + remainder * 10;
		m_number.emplace_back(dividend / 2);
		remainder = dividend % 2;
	}
	std::reverse(m_number.begin(), m_number.end());
	while (m_number.size() > 1 && m_number.back() == 0) {
		m_number.pop_back();
	}

    return remainder;
}

//Fills up zeroes into the vector by the number of places mentioned
void SuperLong::FillZero(std::size_t numberOfPlaces)
{
    for (std::size_t i = 0; i < numberOfPlaces; ++i) {
		m_number.emplace_back(0);
	}
}

void SuperLong::FromInt(int l_num)
{
    m_number.clear(); // Important!

    int remainder;
    while (l_num != 0) {
        remainder = l_num % 10;
        l_num /= 10;
        m_number.emplace_back(remainder);
    }
}


//Converts the object vector number and returns a string
std::string SuperLong::ToString()
{
	std::string answer = "";
    for (auto digit : m_number) {
        answer = std::to_string(digit) + answer;    // Next digit is in front of answer
	}
	return answer;
}

//Return the vector number
std::vector<int> SuperLong::GetVecNumber()
{
	return m_number;
}
