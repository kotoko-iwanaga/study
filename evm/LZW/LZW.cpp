#include <iostream>
#include <string>
#include <unordered_map>
#include <locale>

std::unordered_map<std::string, int> dictionary;

void compress(std::string input) {
    std::string current = "";
    std::string compressed = "";

    for (int i = 0; i < input.length(); i++) {
        current += input[i];
        if (dictionary.find(current) == dictionary.end()) {
            dictionary[current] = dictionary.size();
            compressed += std::to_string(dictionary[current.substr(0, current.length() - 1)]);
            compressed += current[current.length() - 1];
            current = "";
        }
    }

    // Handling the last substring
    if (!current.empty()) {
        compressed += std::to_string(dictionary[current]);
    }

    std::cout << "Compressed string: " << compressed << std::endl;
}

void decompress(std::string input) {
    std::unordered_map<int, std::string> reverseDictionary;

    for (auto& entry : dictionary) {
        reverseDictionary[entry.second] = entry.first;
    }

    std::string decompressed = "";
    int currentIndex = 0;

    while (currentIndex < input.length()) {
        int code = input[currentIndex] - '0';
        currentIndex++;

        if (currentIndex < input.length()) {
            char nextChar = input[currentIndex];
            currentIndex++;

            std::string entry = reverseDictionary[code];
            dictionary[entry + nextChar] = dictionary.size();
            decompressed += entry + nextChar;
        }
        else {
            decompressed += reverseDictionary[code];
        }
    }

    std::cout << "Decompressed string: " << decompressed << std::endl;
}

int main() {
    setlocale(0, "");
    std::string input = "Artigey Artigey";

    // Compress the input string
    compress(input);

    // Decompress the compressed string
    decompress("012301230123");

    return 0;
}