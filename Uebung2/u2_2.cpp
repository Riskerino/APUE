#include <iostream>
#include <algorithm> // for std::find
#include <vector>

using namespace std;

int main() {
    string bsp = "CUCAUGCAUACAGUGUAAGCAGGAAGUAUGUAUUUUGUAUAGGCCAUGCAUACAGUGUAAAUGUAUUUUGUAUAG";
    string seq_input;

    cout << "Input a Nucleotide Sequence: " << endl;
    getline(cin, seq_input);
    string& seq = seq_input;

    vector<string> stopCodons = {"UAG", "UGA", "UAA"};
    vector<string> startCodons = {"AUG"};

    int startPos = -1;
    int stopPos = -1;
    string ORF;
    
    bool frameOpened = false;

    for (unsigned int i = 0; i <= seq.size() - 3; i++) {
        string triplet = seq.substr(i, 3);

        // Check for start codon
        if (find(startCodons.begin(), startCodons.end(), triplet) != startCodons.end()) {
            if (!frameOpened) {
                frameOpened = true;
                startPos = i;
            }
        }

        // Check for stop codon (if a start codon has already been found)
        if (frameOpened && find(stopCodons.begin(), stopCodons.end(), triplet) != stopCodons.end()) {
            stopPos = i + 3;
            break; // Stop at the first encountered stop codon
        }
    }

    if (frameOpened && stopPos != -1) {
        // Get Open Reading Frame
        int ORF_len = stopPos - startPos;
        ORF = seq.substr(startPos, ORF_len);

        cout << "Initial Sequence:\n" << seq << endl;
        cout << "\nFINAL ORF: " << ORF << "\nSpans from Pos. " << startPos << " to Pos. " << stopPos << " with length of " << ORF_len << " Nucleotides" << endl;
    } else {
        cout << "No valid ORF found in the given sequence." << endl;
    }

    return 0;
}
