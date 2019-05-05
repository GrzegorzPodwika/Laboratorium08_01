#include "MostValuableKnapsack.h"
using namespace std;
		
void showResultsOnScreen()
{
	//wczytanie pliku z dysku
	fstream inFile = createInputFile();

	//wczytanie najwiekszej masy z pliku
	int maxMass{};
	try
	{
		inFile >> maxMass;
		if (maxMass <= 0)
			throw EXCEPTION_CODE::notNaturalNumber;
	}
	catch (EXCEPTION_CODE error)
	{
		seeExceptions(error);
		exit(0);
	}

	//utworzenie pomocniczych wektorow + wstepna inicjalizacja zerowych indexow zerami
	vector <int> massOfItems(1);
	vector <int> priceOfItems(1);
	vector <int> amountOfItems(1);

	//wypelnianie vectorow pomocniczych wartosciami z pliku
	fillVectorsWithDataFromFile(inFile, massOfItems, priceOfItems);

	//wywolanie algorytmu zachlannego do problemu plecakowego
	fillVectorByGreedyAlgorithm(maxMass, massOfItems, amountOfItems);

	//obliczenie sumy wartosci rzeczy w plecaku
	long long maxSum{};

	for (unsigned int i = 1; i < amountOfItems.size(); i++)
	{
		maxSum += amountOfItems[i] * priceOfItems[i];
	}

	//pokazanie wektora wynikowych wartosci na ekran
	for (unsigned int i = 1; i < amountOfItems.size(); i++)
	{
		if (i == amountOfItems.size() - 1)
			cout << amountOfItems[i] << endl;
		else
			cout << amountOfItems[i] << ", ";
	}

	//pokazanie najwiekszej sumy na ekran
	cout << "Wartosc plecaka: " << maxSum << endl;

}

bool isStringANumber(string str)
{
	if (str != "")
	{
		if (str[0] >= '0' && str[0] <= '9')
			return true;
	}

	return false;
}

void fillVectorsWithDataFromFile(std::fstream & inFile, std::vector<int>& massOfItems, std::vector<int>& priceOfItems)
{
	string tmpMass{}, tmpPrice{}, tmpName{};
	while (!inFile.eof())
	{
		while (true)
		{
			inFile >> tmpName;
			if (isStringANumber(tmpName))
			{
				tmpMass = tmpName;
				break;
			}
		}

		inFile >> tmpPrice;
		if (isStringANumber(tmpPrice) == false)
		{
			cout << "Blad tresci w pliku!";
			exit(0);
		}

		massOfItems.push_back(stoi(tmpMass));
		priceOfItems.push_back(stoi(tmpPrice));
	}
}

void fillVectorByGreedyAlgorithm(int maxMass, std::vector<int>& massOfItems, std::vector<int>& amountOfItems)
{

	int i{};

	//algorytm zachlanny plecakowy
	for (unsigned int k = 1; k < massOfItems.size(); k++)
	{
		i = 1;
		if (maxMass > 0)
		{
			//inkrementujemy iterator i dopoki i*masa danego przedmiotu > maxMass, wtedy pushujemy o jeden mniejszy iterator do vektora liczby elementow k
			while (true)
			{
				if (i*massOfItems[k] > maxMass)
				{
					amountOfItems.push_back(i - 1);
					break;
				}
				i++;
			}
		}
		else
		{
			amountOfItems.push_back(0);
		}

		maxMass -= amountOfItems[k] * massOfItems[k];
	}

}
