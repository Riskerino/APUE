#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read unique words from a file and store them in a set
set<string> readFileSaveWords(const string& filename) {
    set<string> wordsSet;
    string word;
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return wordsSet;
    }

    // Read word by word from the file
    while (inputFile >> word) {
        wordsSet.insert(word);
    }

    inputFile.close();
    return wordsSet;
}

// Helper function to print the contents of a container
template <typename Container>
void printContainer(const Container& container) {
    for (const auto& elem : container) {
        cout << elem << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <file1> <file2>" << endl;
        return 1;
    }

    string file1 = argv[1];
    string file2 = argv[2];

    // Save file contents to string sets
    set<string> wordSet1 = readFileSaveWords(file1);
    set<string> wordSet2 = readFileSaveWords(file2);

    cout << "Folgender Inhalt von " << file1 << " -> ";
    printContainer(wordSet1);
    cout << "wird mit " << file2 << " verglichen -> ";
    printContainer(wordSet2);
    cout << endl;

    // Using <algorithm> set_intersection to find common words
    vector<string> resultWordVector;
    set_intersection(wordSet1.begin(), wordSet1.end(), wordSet2.begin(), wordSet2.end(), back_inserter(resultWordVector));

    cout << "Folgende Woerter sind in beiden Files vorhanden -> ";
    printContainer(resultWordVector);

    return 0;
}
