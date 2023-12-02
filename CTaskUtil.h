#pragma once
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<cmath>
#include<ctime>

//------------function prototypes------------//
inline void print();
inline void printl();
inline void newLine();
inline void newLine(int);
inline void prec(int);
template<typename T, typename... Args>
inline void print(const T&, const Args&...);
template<typename T, typename... Args>
inline void printl(const T&, const Args&...);
inline void hr(int);
inline void hr();
std::string input(std::string);
std::string strl(std::string);
std::string stru(std::string);
inline bool contains(std::string, std::string);
inline bool isInt(std::string);
inline bool isDouble(std::string);
inline bool isPos(std::string);
inline int randint(int, int);
inline double ex(double);
inline double ex(double, double);
inline double root(double);
inline double root(double, double);
int summat(int, int);
int fact(int);
long subfact(short);
int pexit(int);
int pexit(std::string);
int pexit();

//------------base case functions------------//
inline void print() {}

inline void printl() {
	std::cout << std::endl;
}

//------------output functions---------------//
inline void newLine() {
    std::cout << std::endl;
}

inline void newLine(int num) {
    for (int i = 0; i < num; i++)
        std::cout << std::endl;
}

inline void prec(int dec) {
    std::cout << std::fixed << std::setprecision(dec);
}

template<typename T, typename... Args>
inline void print(const T& arg, const Args&... args) { // This is a Python function! (simplified)
	std::cout << arg;
	print(args...);
}

template<typename T, typename... Args>
inline void printl(const T& arg, const Args&... args) {
    std::cout << arg;
	printl(args...);
}

inline void hr(int num) {
	for (int i = 0; i < num; i++)
		print("-");
}

inline void hr() {
	hr(25);
}

std::string input(std::string prompt) { // This is a Python function!
	std::string entry;
	std::cout << prompt;
	std::cin >> entry;
	return entry;
}

//------------string manipulation------------//
std::string strl(std::string str) {
    for (size_t i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
	return str;
}

std::string stru(std::string str) {
    for (size_t i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
	return str;
}

//------------string checks------------------//
inline bool contains(std::string s, std::string range) {
    return s.find_first_not_of(range) == std::string::npos;
}

inline bool isInt(std::string s) {
	return contains(s, "-0123456789");
}

inline bool isDouble(std::string s) {
	return contains(s, "-0123456789.") && \
		count(s.begin(), s.end(), '.') < 2 && \
		isdigit(s[s.length() - 1]);
}

inline bool isPos(std::string s) {
	return s.find_first_of("-") == std::string::npos && isDouble(s);
}

//------------number operations--------------//
inline int randint(int min, int max) { // This is a Python function!
	srand(static_cast<int>(time(0)));
	return min + rand() % (max - min + 1);
}

inline double ex(double num) {
	return pow(num, 2);
}

inline double ex(double num, double power) {
	return pow(num, power);
}

inline double root(double num) {
	return pow(num, 0.5);
}

inline double root(double num, double power) {
	return pow(num, 1.0 / power);
}

int summat(int n, int k) {
	if (k > n)
		return 0;
	return k + summat(n, k + 1);
}

int fact(int num) {
	if (num == 0)
		return 1;
	return num * fact(num - 1);
}

long subfact(short num) {
	double result, e = 2.71828182845904;
	result = static_cast<double>(fact(num)) / e;
	if (num == 0)
		result = 1;
	return long(round(result));
}

//------------program tasks------------------//
int pexit(int code) {
	if (code == -1)
		std::cout << "\nInvalid entry...";
	newLine(3);
	system("pause");
	return 0;
}

int pexit(std::string code) {
	newLine();
	print(code);
	return pexit(0);
}

int pexit() {
	return pexit(0);
}