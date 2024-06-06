#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Initialisieren der Vektoren fuer Start, Stop Codons und ORFs
vector<string> findORF(const string& sequence) {
    vector<string> stopCodons = {"UAG", "UGA", "UAA"};
    vector<string> startCodons = {"AUG"};
    vector<string> ORFs;
    
    bool frameOpened = false;
    int startPos = -1;

    // Diesen Abschnitt musste ich recherchieren, da ich nicht auf die frameOpened Idee selber draufkam...
    for (unsigned int i = 0; i <= sequence.size() - 3; i++) {
        string triplet = sequence.substr(i, 3);

        // Check fuer Start codon
        if (!frameOpened && find(startCodons.begin(), startCodons.end(), triplet) != startCodons.end()) {
            frameOpened = true;
            startPos = i;
        }

        // Check fuer Stop codon
        if (frameOpened && find(stopCodons.begin(), stopCodons.end(), triplet) != stopCodons.end()) {
            int stopPos = i + 3;
            ORFs.push_back(sequence.substr(startPos, stopPos - startPos));
            frameOpened = false; // hier wird das Tracking des aktuellen Frames fuer den naechsten ORF resetted.
        }
    }

    return ORFs;
}

int main() {
    string sequence_input;
    cout << "Gebe hier die Nucleotid Sequenz ein, die nach ORFs gesucht werden soll: " << endl;
    getline(cin, sequence_input);

    // Falls kein Input, Meldung ausgeben und Program schliessen:
    if (sequence_input.empty()) {
        cout << "Keine Sequenz eingegeben. Program schliesst." << endl;
        return 1;
    }
    
    // Vector fuer gefundenen ORFs initialisieren
    vector<string> foundORFs = findORF(sequence_input);
   
    if (!foundORFs.empty()) {
        cout << "\nGefundene ORFs: \n";
        for (const auto& orf : foundORFs) { //Ueber jeden ORF im vector iterieren
            cout << orf << endl;
        }
    } else {
        cout << "\nEs konnten keine ORFs in der eingegeben Sequenz gefunden werden." << endl;
    }

    return 0;
}
