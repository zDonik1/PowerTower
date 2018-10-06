#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class SuperLong
{
public:
    SuperLong();
    SuperLong(int l_num);
    SuperLong(const std::vector<int> &l_num);

	void Add(SuperLong l_num1, SuperLong l_num2);
	void Multiply(SuperLong l_num1, SuperLong l_num2);
	void Power(SuperLong l_base, SuperLong l_power);
	void half();
    void FillZero(std::size_t numberOfPlaces);

	void Save(int l_num);

    void FromInt(int l_num);
	std::string ToString();
	std::vector<int> GetVecNumber();

private:
	std::vector<int> m_number;
};

//Extra function identifiers
SuperLong IntToSL(int l_num);
