/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                 *
 *   Name: Chapter 7, Challenge 05: Monkey Business                                *
 *                                                                                 *
 *   Purpose:                                                                      *
 *   Receives 15 double numbers provided by the user from the console. Each one    *
 *   represents how many pounds of food eats each one of the 3 monkeys in a        *
 *   zoo during a typical week of 5 working days. The program stores them in a     *
 *   two-dimensional array. And then based on them, it calculates the average,     *
 *   the least, and the greatest amount of food eaten by the monkeys.              *
 *                                                                                 *
 *   More Details:                                                                 *
 *   https://github.com/reymillenium/20240626_1752_challenge0705_monkey_business   *
 *                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 **/

#include <iostream>
#include <string>  // for string, to_string, etc
#include <cmath> // for sqrt, sin, pow
#include <limits> // For SHRT_MAX, SHRT_MIN, etc
#include <iomanip> // for setprecision, setw, fixed
#include<array>  // for array
#include<random> // for random_device
#include <cstdlib> // For rand and srand
#include <ctime>   // For the time function
#include <sstream> // for stringstream (used in humanizeInteger, humanizeDouble, etc)
#include <vector> // to use vectors
#include <fstream> // For ifstream, ofstrea, fstream
#include <numeric> // For accumulate, transform_reduce, (in the vectors)
#include <algorithm> // For max_element, min_element, find, transform (to use in vectors), or for max()

using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;
using std::string;
using std::to_string;
using std::stringstream;
using std::accumulate;
using std::vector;
using std::find;

// Receives and validates a double number from the console
double getDouble(const string &, double, double, bool = false, const string & = "Invalid input. Please try again.");

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(unsigned long long int);

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(long double, int = 2);

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(long long int);

template<int N, int M>
double templateSumOfDoublesInTwoDimensionsArray(double (&)[N][M]);

template<int N, int M>
double templateAverageAmongDoublesInTwoDimensionsArray(double (&)[N][M]);

// Determines the lower number among a two-dimensional array of doubles
template<int N, int M>
double templateLowerDoubleInTwoDimensionsArray(double (&)[N][M]);

// Determines the higher number among a two-dimensional array of doubles
template<int N, int M>
double templateHigherDoubleInTwoDimensionsArray(double (&)[N][M]);

// CUSTOM FUNCTIONS

template<int N, int M>
void loadMonkeysFoodArray(const vector<string> &, double (&)[N][M]);

void displayResults(double, double, double);

// Main Function
int main() {
    constexpr int MONKEYS_AMOUNT = 3; // The amount of monkeys
    constexpr int NUMBER_OF_DAYS_THAT_MONKEYS_EAT = 5; // The number of days of the week that monkeys eat
    const vector<string> weekDays {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    double monkeysFood[MONKEYS_AMOUNT][NUMBER_OF_DAYS_THAT_MONKEYS_EAT]; //Two-dimensional array to store the feeding data per monkey (3 monkeys, 5 days of the week)

    // Loads all the monkey feeding data into the reference of the two-dimensional array
    loadMonkeysFoodArray(weekDays, monkeysFood);

    // Calculates the average, the least, and the greatest amount of food eaten by the monkeys
    const double averageAmountOfFood = templateAverageAmongDoublesInTwoDimensionsArray(monkeysFood);
    const double lowerAmountOfFood = templateLowerDoubleInTwoDimensionsArray(monkeysFood);
    const double higherAmountOfFood = templateHigherDoubleInTwoDimensionsArray(monkeysFood);

    // Displays the results on the console:
    displayResults(averageAmountOfFood, lowerAmountOfFood, higherAmountOfFood);

    return 0;
}

// Receives and validates a double number from the console
double getDouble(const string &message, const double minValue, const double maxValue, const bool showRange, const string &errorMessage) {
    double number = 0; // Number typed by the user
    bool invalidInput; // If the input is valid

    do {
        cout << message << (showRange ? (" (" + to_string(minValue) + " - " + to_string(maxValue) + ")") : "") << ": ";
        cin >> number;
        cin.ignore();

        invalidInput = number < minValue || maxValue < number;
        if (invalidInput) cout << errorMessage << endl;
    } while (invalidInput);

    return number;
}

// Formats a given positive int by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedInteger(const unsigned long long int integerValue) {
    string integerAsString = to_string(integerValue);
    const int initialIndex = (integerAsString.length() - 3);
    // We insert commas into the string every three digits, fromm right to left.
    for (int j = initialIndex; j > 0; j -= 3) {
        integerAsString.insert(j, ",");
    }
    return integerAsString;
}

// Formats a given positive double by inserting a comma every 3 digits of its equivalent string, to make it more readable, by US standards
string humanizeUnsignedDouble(const long double doubleValue, const int precision) {
    const auto integerValue = static_cast<unsigned long long int>(doubleValue);
    const long double decimals = doubleValue - integerValue;
    // Extracts into a string the decimal part, rounded to two significant digits
    stringstream stream;
    // Places the decimals into the stream, rounded to two significant digits (by default)
    stream << fixed << setprecision(precision) << decimals;
    // Extracts the decimals from the stream, as a string, still rounded to two significant digits (by default)
    const string decimalsAsString = stream.str(); // It still includeds the zero & the dot. Ex: 0.34 (the dot must be removed next)
    return humanizeUnsignedInteger(integerValue) + decimalsAsString.substr(1, precision + 1);
}

// Returns the string gramatic representation of an ordinal number, from a given int number
string ordinalFromNumber(const long long int number) {
    const long long int lastDigit = number % 10;
    string additive;

    switch (number) {
        case 11:
        case 12:
            additive = "th";
            break;
        default:
            switch (lastDigit) {
                case 1:
                    additive = "st";
                    break;
                case 2:
                    additive = "nd";
                    break;
                case 3:
                    additive = "rd";
                    break;
                default:
                    additive = "th";
                    break;
            }
            break;
    }

    return to_string(number) + additive;
}

// Calculates the sum of all the elements inside a two-dimensional array of doubles
template<int N, int M>
double templateSumOfDoublesInTwoDimensionsArray(double (&twoDimensionsDoublesArray)[N][M]) {
    double sum = 0.0;

    for (auto &row: twoDimensionsDoublesArray) {
        for (auto &number: row) {
            sum += number;
        }
    }

    return sum;
}

// Calculates the average among all the numbers inside an array of doubles
template<int N, int M>
double templateAverageAmongDoublesInTwoDimensionsArray(double (&doublesTwoDimensionalArray)[N][M]) {
    const int rows = sizeof(doublesTwoDimensionalArray) / sizeof(doublesTwoDimensionalArray[0]);
    const int columns = sizeof(doublesTwoDimensionalArray[0]) / sizeof(doublesTwoDimensionalArray[0][0]);

    return templateSumOfDoublesInTwoDimensionsArray(doublesTwoDimensionalArray) / (rows * columns);
}

// Determines the lower number among a two-dimensional array of doubles
template<int N, int M>
double templateLowerDoubleInTwoDimensionsArray(double (&twoDimensionsDoublesArray)[N][M]) {
    const int rows = sizeof(twoDimensionsDoublesArray) / sizeof(twoDimensionsDoublesArray[0]);
    const int columns = sizeof(twoDimensionsDoublesArray[0]) / sizeof(twoDimensionsDoublesArray[0][0]);
    double lower = twoDimensionsDoublesArray[0][0];

    for (int row = 0; row < rows; row++) {
        for (int col = (row == 0 ? 1 : 0); col < columns; col++) {
            if (const double number = twoDimensionsDoublesArray[row][col]; number < lower)
                lower = number;
        }
    }

    return lower;
}

// Determines the higher number among a two-dimensional array of doubles
template<int N, int M>
double templateHigherDoubleInTwoDimensionsArray(double (&twoDimensionsDoublesArray)[N][M]) {
    const int rows = sizeof(twoDimensionsDoublesArray) / sizeof(twoDimensionsDoublesArray[0]);
    const int columns = sizeof(twoDimensionsDoublesArray[0]) / sizeof(twoDimensionsDoublesArray[0][0]);
    double higher = twoDimensionsDoublesArray[0][0];

    for (int row = 0; row < rows; row++) {
        for (int col = (row == 0 ? 1 : 0); col < columns; col++) {
            if (const double number = twoDimensionsDoublesArray[row][col]; number > higher)
                higher = number;
        }
    }

    return higher;
}


// CUSTOM FUNCTIONS


template<int N, int M>
void loadMonkeysFoodArray(const vector<string> &weekDays, double (&monkeysFood)[N][M]) {
    const int rows = sizeof(monkeysFood) / sizeof(monkeysFood[0]);
    const int columns = sizeof(monkeysFood[0]) / sizeof(monkeysFood[0][0]);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            monkeysFood[row][col] = getDouble("Please type how many pounds of food the " + ordinalFromNumber(row + 1) + " monkey will eat on " + weekDays[col], 0, INT_MAX);
        }
    }
}

void displayResults(const double average, const double lowerAmount, const double higherAmount) {
    cout << endl;
    cout << "The average amount of food eaten per day by the whole family of monkeys is " << humanizeUnsignedDouble(average) << " lbs." << endl;
    cout << "The least amount of food eaten during the week by any one monkey is " << humanizeUnsignedDouble(lowerAmount) << " lbs." << endl;
    cout << "The greatest amount of food eaten during the week by any one monkey is " << humanizeUnsignedDouble(higherAmount) << " lbs." << endl;
}
