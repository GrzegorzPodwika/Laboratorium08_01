#ifndef MOSTVALUABLEKNAPSACK_H
#define MOSTVALUABLEKNAPSACK_H
#include "libFiles.h"
#include "libExceptions.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

/*
Funkcja pokazujaca rezultaty obliczen na ekran.
Glowna funkcja zarzadzajaca innymi funkcjami
*/
void showResultsOnScreen();

/*
Funkcja pomocnicza sprawdzajaca czy napis jest liczba lub inaczej czy da sie skonwertowac na liczbe
@param str przysylany napis do sprawdzenia
@return true jesli jest liczba, false w przeciwnym wypadku
*/
bool isStringANumber(std::string str);

/*
Funkcja wypelniajace przyslane vectory wartosciami z pliku inFile, funkcja pomocnicza
@param inFile przysylany pli k z ktorego pobieramy wartosci
@param massOfItems vector do ktorego zostaje wpisywana masa danego przedmiotu
@param priceOfItems vector do ktorego zostaje wpisywana cena danego przedmiotu
*/
void fillVectorsWithDataFromFile(std::fstream &inFile, std::vector <int> &massOfItems, std::vector <int> &priceOfItems);

/*
Funkcja wypelniajace przyslany vector ilosci rzeczy (k) najlepszymi wartosciami za pomoca algorytmu zachlannego
@param maxMass maksymalna waga plecaka
@param massOfItems masa poszczegolnych rzeczy, ktore mozemy wlozyc do plecaka
@param amountOfItems ilosc poszczegolnych rzeczy (k), ktore mozemy zabrac ze soba, aby ich wartosc byla najwieksza 
*/
void fillVectorByGreedyAlgorithm(int maxMass, std::vector <int> &massOfItems, std::vector <int> &amountOfItems);

#endif // !MOSTVALUABLEKNAPSACK_H

