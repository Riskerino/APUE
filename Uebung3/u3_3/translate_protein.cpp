#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>

std::unordered_map<char, std::string> load_amino_acid_map(const std::string &filename) {
    std::unordered_map<char, std::string> amino_acid_map;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Fehler: Konnte die Mapping-Datei nicht öffnen." << std::endl;
        exit(1);
    }

    std::string codon;
    char amino_acid;
    while (file >> codon >> amino_acid) {
        if (amino_acid_map.find(amino_acid) == amino_acid_map.end()) {
            amino_acid_map[amino_acid] = codon;  // Nur das erste Codon für jede Aminosäure speichern
        }
    }

    file.close();
    return amino_acid_map;
}

std::string translate_protein_to_dna(const std::string &protein, const std::unordered_map<char, std::string> &amino_acid_map) {
    std::string dna_sequence;
    for (char amino_acid : protein) {
        if (amino_acid_map.find(amino_acid) != amino_acid_map.end()) {
            dna_sequence += amino_acid_map.at(amino_acid);
        }
        // Unbekannte Aminosäuren werden übersprungen
    }
    return dna_sequence;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <mapping_file> <protein_sequence>" << std::endl;
        return 1;
    }

    std::string mapping_file = argv[1];
    std::string protein_sequence = argv[2];

    auto amino_acid_map = load_amino_acid_map(mapping_file);
    std::string dna_sequence = translate_protein_to_dna(protein_sequence, amino_acid_map);

    std::cout << dna_sequence << std::endl;

    return 0;
}
