#ifndef MOSTVALUABLEKNAPSACK_H
#define MOSTVALUABLEKNAPSACK_H
#include <fstream>
#include <vector>
#include "libFiles.h"
#include <iostream>
#include <string>

/*
Funkcja 

*/
void computeAndShowData();

/*
Funkcja pomocnicza sprawdzajaca czy napis jest liczba
@param str przysylany napis do sprawdzenia
@return true jesli jest liczba, false w przeciwnym wypadku
*/
bool isStringANumber(std::string str);

void fillVectorsWithDataFromFile(std::fstream &inFile, std::vector <int> &massOfItems, std::vector <int> &priceOfItems);

void fillVectorByGreedyAlgorithm(int maxMass, std::vector <int> &massOfItems, std::vector <int> &numberOfItems);

#endif // !MOSTVALUABLEKNAPSACK_H

