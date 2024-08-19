#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> decode(const string& message_file) {
    ifstream file(message_file);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << message_file << endl;
        return {};
    }

    unordered_map<int, string> num_2_word;

    string word;
    int num;
    while (file >> num >> word) {
        num_2_word[num] = word;
    }

    file.close();

    int max = 0;
    for (const auto& pair : num_2_word) {
        if (pair.first > max) {
            max = pair.first;
        }
    }

    vector<string> decoded_words;
    int current_num = 1;

    while (current_num <= max) {
        int next_num = current_num * (current_num + 1) / 2;

        auto it = num_2_word.find(next_num);
        if (it != num_2_word.end()) {
            decoded_words.push_back(it->second);
        } else {
            cerr << "Error: Missing word for pyramid number " << next_num << endl;
            break;
        }

        current_num++;
    }

    return decoded_words;
}

int main() {
    string message_file = "C:/Users/Dell/Desktop/Dev/CProgramming/WorkplaceVSC/encoded_message.txt";
    vector<string> decoded_string = decode(message_file);

    if (decoded_string.empty()) {
        cout << "No words found for the pyramid sequence in the file." << endl;
    } else {
        for (const string& word : decoded_string) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}