#include "Headers.h"
using namespace std;


void parse(vector<vector<int>>& vec, string str)
{
    stringstream iss(str);
    int number;
    vector<int> v;
    while (iss >> number) {
        v.push_back(number);
    }
    vec.push_back(v);
}

void findMidthTerm(vector<int> vec, int NumOfLines,int i, vector<int>& MidTerms) {
    int midthTerm;
    midthTerm = (vec.size()/2);
    MidTerms.push_back(vec[midthTerm]);
}


int getIndex(vector<int> v, int K)
{
    int index;
    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end())
    {

        // calculating the index
        // of K
        index = it - v.begin();
    }
    else 
    {
        // If the element is not
        // present in the vector
        cout << "-1" << endl;
    }
    return index;
}




int main()
{
    // Initializing some variables
    string line[100], temp;
    int count = 0, number_of_lines = 0, max = 0, min = 0, maxIndex, minIndex, tmp;
    vector<vector<int>> vec;
    vector<int> ArrOfMidTerms;

    ifstream myfile("homework.txt");
    while (getline(myfile, temp))
    {
        count++;
    }
    number_of_lines = count;
    myfile.clear();
    myfile.seekg(0, ios::beg);
    for (int i = 0; i < number_of_lines; i++) // For example, Line[0] is equal to first line, and line[1] is equal to the second etc.
    {
        getline(myfile, line[i], '\n');
        parse(vec, line[i]);
        findMidthTerm(vec[i], number_of_lines, i,ArrOfMidTerms);
    }
    min = *min_element(ArrOfMidTerms.begin(), ArrOfMidTerms.end());
    max = *max_element(ArrOfMidTerms.begin(), ArrOfMidTerms.end());
    maxIndex = getIndex(ArrOfMidTerms, max);
    minIndex = getIndex(ArrOfMidTerms, min);
    reverse(vec[maxIndex].begin(), vec[maxIndex].end());
    reverse(vec[minIndex].begin(), vec[minIndex].end());
    cout << "En Buyuk Liste Orta Dugum Adres : " << &vec[maxIndex][(vec[maxIndex].size()/2)] << endl;
    tmp = vec[minIndex][(vec[minIndex].size() / 2)];
    vec[minIndex][(vec[minIndex].size() / 2)] = vec[maxIndex][(vec[maxIndex].size() / 2)];
    cout << "En Buyuk Liste Degerler:" << endl;
    for (int i = 0; i < vec[minIndex].size(); i++)
    {
        cout << vec[minIndex][i] << " ";
    }
    cout << endl << "------------------------------------------------------------------------" << endl ;
    cout << "En Kucuk Liste Orta Dugum Adres : " << &vec[minIndex][(vec[minIndex].size() / 2)] << endl;
    cout << "En Kucuk Liste Degerler:" << endl;
    vec[maxIndex][(vec[maxIndex].size() / 2)] = tmp;
    for (int i = 0; i < vec[maxIndex].size(); i++)
    {
        cout << vec[maxIndex][i] << " ";
    }
    return 0;
}

// Not required now, but might be used later on.

/*
int findLarge(vector<int> myVector)
{
    int max = myVector[0];

    for (int i = 1; i < myVector.size(); i++)
        if (myVector[i] > max)
            max = myVector[i];

    return max;
}

int findMin(vector<int> myVector)
{
    int min = myVector[0];
    for (int i = 1; i < myVector.size(); i++)
        if (myVector[i] < min)
            min = myVector[i];

    return min;
}
*/
