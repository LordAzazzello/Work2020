#pragma once
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Fraction
{
public:
	static int FractionCount;
	static int GetFractionCount() {
		return FractionCount;
	}

	Fraction(int newUp, int newDown) {
		Clear();
		up = newUp;
		down = newDown;
		Reduce();
		FractionCount++;
	}
	Fraction(double fract) {
		Clear();
		DoubleToFriction(fract);
		FractionCount++;
	}
	void Clear() {
		up = 0;
		down = 0;
	}

	double GetDouble() {
		if (up != 0) {
			return double(up) / down;
		}
		else return 0;
	}

	void Reduce() {
		int gcdValue = gcd(up, down);
		up /= gcdValue;
		down /= gcdValue;
	}

	static int gcd(int n, int m) {
		int absN = abs(n);
		int absM = abs(m);
		long nod = 1L;
		for (long i = absN > absM ? absM : absN; i > 0; i--) {
			if (absN % i == 0 && absM % i == 0) {
				nod = i;
				break;
			}
		}
		return nod;
	}

	static void PrintAsFraction(double fract) {
		int newUp = 0;
		int newDown = 1;
		ostringstream os_str;
		os_str << fract;
		string str = os_str.str();
		int point = str.find('.');
		if (point == -1) {
			newUp = atoi(str.c_str());
			newDown = 1;
		}
		else {
			str.erase(point, 1);
			newUp = atoi(str.c_str());
			for (size_t i = 0; i < str.length() - point; i++)
				newDown *= 10;
		}
		int gcdValue = gcd(newUp, newDown);
		newUp /= gcdValue;
		newDown /= gcdValue;
		if (newUp != 0) {
			cout << newUp << '/' << newDown;
		}
		else {
			cout << 0;
		}
	}
	static void PrintAsFraction(char* decimal_fraction) {
		PrintAsFraction(atof(decimal_fraction));
	}

	template <typename T>
	Fraction operator + (T value) {
		return Fraction(GetDouble() + value);
	}
	Fraction operator + (Fraction value) {
		return Fraction(GetDouble() + value.GetDouble());
	}
	template <typename T>
	Fraction operator - (T value) {
		return Fraction(GetDouble() - value);
	}
	Fraction operator - (Fraction value) {
		return Fraction(GetDouble() - value.GetDouble());
	}
	template <typename T>
	Fraction operator * (T value) {
		return Fraction(GetDouble() * value);
	}
	Fraction operator * (Fraction value) {
		return Fraction(GetDouble() * value.GetDouble());
	}
	template <typename T>
	Fraction operator / (T value) {
		return Fraction(GetDouble() / value);
	}
	Fraction operator / (Fraction value) {
		return Fraction(GetDouble() / value.GetDouble());
	}

	friend ostream& operator << (ostream& os, const Fraction& value) {
		if (value.up != 0) {
			os << value.up << '/' << value.down;
		}
		else {
			os << 0;
		}
		return os;
	}

private:
	int up = 0;
	int down = 0;

	void DoubleToFriction(double value) {
		int newUp = 0;
		int newDown = 1;
		ostringstream os_str;
		os_str << value;
		string str = os_str.str();
		int point = str.find('.');
		if (point == -1) {
			newUp = atoi(str.c_str());
			newDown = 1;
		}
		else {
			str.erase(point, 1);
			newUp = atoi(str.c_str());
			for (size_t i = 0; i < str.length() - point; i++)
				newDown *= 10;
		}
		up = newUp;
		down = newDown;
		Reduce();
	}
};

