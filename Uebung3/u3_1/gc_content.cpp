#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

struct GCContentResult {
    int gc_content;
    int gc_count;
    int total_bases;
};

GCContentResult calculate_gc_content(const std::string &sequence) {
    int gc_count = 0;
    for (char base : sequence) {
        if (base == 'g' || base == 'c') {
            gc_count++;
        }
    }
    int total_bases = sequence.length();
    int gc_content = 0;
    if (total_bases > 0) {
        double gc_percentage = (static_cast<double>(gc_count) / total_bases) * 100;
        gc_content = static_cast<int>(std::round(gc_percentage));
    }
    return {gc_content, gc_count, total_bases};
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 1;
    }

    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
        return 1;
    }

    std::ofstream output_file(argv[2]);
    if (!output_file.is_open()) {
        std::cerr << "Error: Could not open output file " << argv[2] << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        GCContentResult result = calculate_gc_content(line);
        output_file << "Input Sequence: " << line << std::endl;
        output_file << "GC Content: " << result.gc_content << "%" << std::endl;
        output_file << "Details: " << result.gc_count << " G/C out of " << result.total_bases << " bases" << std::endl;
        output_file << std::endl;
    }

    input_file.close();
    output_file.close();

    return 0;
}
