#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>

using namespace std;

class Student
{
private:
	string fullname = "none";
	bool sex = true;
	int birth_year = 0;
	int start_year = 0;
	int number = 0;
	float score = 0;

public:
	Student() {
		setFullName("none");
		setSex(true);
		setBirthYear(0);
		setStartYear(2000);
		setNumber(0);
		setScore(0);
	}
	Student(string full_name, bool sex, int birth_year, int start_year, int number, float score) {
		setFullName(full_name);
		setSex(sex);
		setBirthYear(birth_year);
		setStartYear(start_year);
		setNumber(number);
		setScore(score);
	}

	void setFullName(std::string new_first_name) { fullname = new_first_name; }
	void setSex(bool new_sex) { sex = new_sex; }
	void setBirthYear(int new_birth_year) { birth_year = new_birth_year; }
	void setStartYear(int new_start_year) { start_year = new_start_year; }
	void setNumber(int new_number) { number = new_number; }
	void setScore(float new_score) { score = new_score; }

	string getFullName() { return fullname; }
	bool getSex() { return sex; }
	int getBirthYear() { return birth_year; }
	int getStartYear() { return start_year; }
	float getNumber() { return number; }
	float getScore() { return score; }

	void Serialize(const std::string& filename = "Database.txt") {
		std::string str;
		str += CreateParam("fullname", fullname);
		str += CreateParam("sex", sex);
		str += CreateParam("birth_year", birth_year);
		str += CreateParam("start_year", start_year);
		str += CreateParam("number", number);
		str += CreateParam("score", score, false);
		remove(filename.c_str());
		std::ofstream write;
		write.open(filename);
		if (write.is_open())
			write << str;
		write.close();
	}
	void Deserialize(const std::string& filename = "Database.txt") {
		string str;
		ifstream read(filename);
		read >> str;
		read.close();
		bool Last = false;
		while (true) {
			string paramName;
			string paramValue;

			paramName.assign(str, 0, str.find('=') - 1);
			paramValue.assign(str, str.find('=') + 1, (str.find(',', 1) == UINT_MAX ? str.length() : str.find(',')) - str.find('=') - 1);
			str.erase(0, str.find(',') == UINT_MAX ? str.length() - 1 : str.find(',') + 1);
			if (Last) break;
			if (str.find(',') == UINT_MAX)
				Last = true;
			if (paramName == "first_name") fullname = paramValue;
			else if (paramName == "number") istringstream(paramValue) >> std::boolalpha >> sex;
			else if (paramName == "price") birth_year = atoi(paramValue.c_str());
			else if (paramName == "year") start_year = atoi(paramValue.c_str());
			else if (paramName == "number") number = atoi(paramValue.c_str());
			else if (paramName == "score") score = atof(paramValue.c_str());
		}
	}

private:
	template <typename T>
	std::string CreateParam(std::string name, T value, bool coma = true) {
		ostringstream ss;
		ss << name << "=" << value << (coma == true ? "," : "");
		return ss.str();
	}
};

