#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#define printContainer(mySet) for (string word : mySet) {cout << word << " ";} cout << endl;

using namespace std;


set<string> readFileSaveWords(string filename) {
    //use set to only get unique words, saves CPU, memory
    set<string> wordsSet;
    string word;

    // open file
    ifstream inputFile;
    inputFile.open(filename, ios::in);

    // read word for word
    while (inputFile.eof() == false)
    {
        inputFile >> word;
        wordsSet.insert(word);
    }

    // close file
    inputFile.close();
    return wordsSet;
}



int main() {

    string file1 = "testfile1.txt";
    string file2 = "testfile2.txt";

    // save file contents to string set
    set<string> wordSet1 = readFileSaveWords(file1);
    set<string> wordSet2 = readFileSaveWords(file2);

    cout << "Folgender Inhalt von " << file1 << " -> ";
    printContainer(wordSet1);
    cout << "wird mit " << file2 << " verglichen -> ";
    printContainer(wordSet2);
    cout << endl;


    vector<string> resultWordVector;
    //using for loops:
    for (string search_word : wordSet1) {
        for (string compare_word : wordSet2) {
            if (search_word == compare_word) {
                resultWordVector.push_back(search_word);
            }
        }
    }

    cout << "Folgende Woerter sind in beiden Files vorhanden -> ";
    printContainer(resultWordVector);

    //Atlernative: use <algorithm> set_intersection:



    return 0;
}