#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// Hier werden einzigartige Woerter aus einem File als set gespeichert
set<string> readFileUniqueWords(const string& filename) {
    set<string> wordsSet;
    string word;
    ifstream inputFile(filename);

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

// Mit argc und argv arbeiten. Falls weniger als 3 Argumente in Verwendung, Error ausgeben: 
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Fehler! Kontrolliere die Eingabe!" << endl;
        return 1;
    }

    string file1 = argv[1];
    string file2 = argv[2];

    // Speichern der File Inhalte als string sets
    set<string> wordSet1 = readFileUniqueWords(file1);
    set<string> wordSet2 = readFileUniqueWords(file2);

    cout << "Folgender Inhalt von " << file1 << " -> ";
    printContainer(wordSet1);
    cout << "wird mit " << file2 << " verglichen -> ";
    printContainer(wordSet2);
    cout << endl;

    // Mit <algorithm> und der Funktion set_intersection kann man gleiche Woerter finden
    vector<string> resultWords;
    set_intersection(wordSet1.begin(), wordSet1.end(), wordSet2.begin(), wordSet2.end(), back_inserter(resultWords));

    cout << "Folgende Woerter sind in beiden Files vorhanden -> ";
    printContainer(resultWords);

    return 0;
}
