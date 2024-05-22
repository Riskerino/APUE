#include <iostream>
#include <vector>
#include <algorithm> // for std::find

using namespace std;

// Function to find ORFs in a given nucleotide sequence
vector<string> findORFs(const string& seq) {
    vector<string> stopCodons = {"UAG", "UGA", "UAA"};
    vector<string> startCodons = {"AUG"};
    vector<string> ORFs;
    
    bool frameOpened = false;
    int startPos = -1;

    for (unsigned int i = 0; i <= seq.size() - 3; i++) {
        string triplet = seq.substr(i, 3);

        // Check for start codon
        if (!frameOpened && find(startCodons.begin(), startCodons.end(), triplet) != startCodons.end()) {
            frameOpened = true;
            startPos = i;
        }

        // Check for stop codon
        if (frameOpened && find(stopCodons.begin(), stopCodons.end(), triplet) != stopCodons.end()) {
            int stopPos = i + 3;
            ORFs.push_back(seq.substr(startPos, stopPos - startPos));
            frameOpened = false; // Reset frame tracking for next ORF
        }
    }

    return ORFs;
}

int main() {
    string seq_input;
    cout << "Input a Nucleotide Sequence: " << endl;
    getline(cin, seq_input);

    // Check if the input is empty
    if (seq_input.empty()) {
        cout << "No input provided. Exiting program." << endl;
        return 1; // Return with a non-zero code to indicate an error
    }

    vector<string> ORFs = findORFs(seq_input);

    cout << "Initial Sequence:\n" << seq_input << endl;

    if (!ORFs.empty()) {
        cout << "\nFound ORFs: \n";
        for (const auto& orf : ORFs) {
            cout << orf << endl;
        }
    } else {
        cout << "\nNo valid ORFs found in the given sequence." << endl;
    }

    return 0;
}
