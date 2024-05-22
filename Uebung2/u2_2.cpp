#include <iostream>
#include <algorithm> // for std::find
#include <vector>

using namespace std;

int main() {
    string seq_iCUCAUGCAUACAGUGUAAGCAGGAAGUAUGUAUUUUGUAUAGGCCnput;

    cout << "Input a Nucleotide Sequence: " << endl;
    getline(cin, seq_input);
    string& seq = seq_input;

    vector<string> stopCodons = {"UAG", "UGA", "UAA"};
    vector<string> startCodons = {"AUG"};

    vector<string> ORFs;
    int startPos = -1;
    int stopPos = -1;
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
            // Get the ORF
            int ORF_len = stopPos - startPos;
            string ORF = seq.substr(startPos, ORF_len);
            ORFs.push_back(ORF);

            // Reset frame tracking variables to look for the next ORF
            frameOpened = false;
            startPos = -1;
            stopPos = -1;

            // Move the index forward to continue searching beyond the stop codon
            i += 2; // Move forward to skip the current triplet
        }
    }

    cout << "Initial Sequence:\n" << seq << endl;

    if (!ORFs.empty()) {
        cout << "\nFound ORFs: \n";
        for (const auto& orf : ORFs) {
            cout << orf << "\n";
        }
    } else {
        cout << "\nNo valid ORFs found in the given sequence." << endl;
    }

    return 0;
}
