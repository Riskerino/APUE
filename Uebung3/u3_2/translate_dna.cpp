#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, char> load_codon_map(const std::string &filename) {
    std::unordered_map<std::string, char> codon_map;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Fehler: Konnte die Mapping-Datei nicht öffnen." << std::endl;
        exit(1);
    }

    std::string codon;
    char amino_acid;
    while (file >> codon >> amino_acid) {
        codon_map[codon] = amino_acid;
    }

    file.close();
    return codon_map;
}

std::string translate_dna_to_protein(const std::string &dna, const std::unordered_map<std::string, char> &codon_map) {
    if (dna.length() % 3 != 0) {
        std::cerr << "Fehler: Länge der DNA-Kette muss durch 3 teilbar sein" << std::endl;
        exit(1);
    }

    std::string protein;
    for (size_t i = 0; i < dna.length(); i += 3) {
        std::string codon = dna.substr(i, 3);
        if (codon_map.find(codon) != codon_map.end()) {
            protein += codon_map.at(codon);
        }
        // Unbekannte Codons oder Stopp-Codons werden übersprungen
    }

    return protein;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <mapping_file> <dna_sequence>" << std::endl;
        return 1;
    }

    std::string mapping_file = argv[1];
    std::string dna_sequence = argv[2];

    auto codon_map = load_codon_map(mapping_file);
    std::string protein = translate_dna_to_protein(dna_sequence, codon_map);

    std::cout << protein << std::endl;

    return 0;
}
