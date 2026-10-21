#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <functional>
#include <limits>
#include <cctype>
using namespace std;

// Unit 4 Case Study: Dictionary using Hash Tables
// Collision resolution method: Separate Chaining

class Dictionary {
private:
    struct Entry {
        string word;
        string meaning;
    };

    vector<list<Entry>> table;
    size_t capacity;
    size_t hashWord(const string& word) const {
        string normalized = word;
        for (char& ch : normalized)
            ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
        return hash<string>{}(normalized) % capacity;
    }

    static string normalize(const string& word) {
        string result = word;
        for (char& ch : result)
            ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
        return result;
    }

public:
    explicit Dictionary(size_t size = 11) : table(size), capacity(size) {}

    void insertOrUpdate(const string& word, const string& meaning) {
        if (word.empty() || meaning.empty()) {
            cout << "Word and meaning cannot be empty.\\n";
            return;
        }

        size_t index = hashWord(word);
        for (Entry& entry : table[index]) {
            if (normalize(entry.word) == normalize(word)) {
                entry.meaning = meaning;
                cout << "Meaning updated successfully.\\n";
                return;
            }
        }

        table[index].push_back({word, meaning});
        cout << "Word added successfully. Hash index: " << index << '\\n';
    }

    void search(const string& word) const {
        size_t index = hashWord(word);
        for (const Entry& entry : table[index]) {
            if (normalize(entry.word) == normalize(word)) {
                cout << entry.word << " : " << entry.meaning << '\\n';
                return;
            }
        }
        cout << "Word not found in dictionary.\\n";
    }

    void remove(const string& word) {
        size_t index = hashWord(word);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (normalize(it->word) == normalize(word)) {
                chain.erase(it);
                cout << "Word deleted successfully.\\n";
                return;
            }
        }
        cout << "Word not found; nothing deleted.\\n";
    }

    void display() const {
        bool found = false;
        cout << "\\n--- Dictionary Entries ---\\n";
        for (size_t i = 0; i < capacity; ++i) {
            if (!table[i].empty()) {
                found = true;
                cout << "[" << i << "] ";
                for (const Entry& entry : table[i])
                    cout << "{" << entry.word << " : " << entry.meaning << "} -> ";
                cout << "NULL\\n";
            }
        }
        if (!found) cout << "Dictionary is empty.\\n";
    }
};

int main() {
    Dictionary dictionary;
    int choice;
    string word, meaning;

    do {
        cout << "\\n===== DICTIONARY USING HASH TABLES =====\\n";
        cout << "1. Add word / update meaning\\n";
        cout << "2. Search word\\n";
        cout << "3. Delete word\\n";
        cout << "4. Display dictionary and hash chains\\n";
        cout << "0. Exit\\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) return 0;
        cin.ignore(numeric_limits<streamsize>::max(), '\\n');

        switch (choice) {
            case 1:
                cout << "Enter word: ";
                getline(cin, word);
                cout << "Enter meaning: ";
                getline(cin, meaning);
                dictionary.insertOrUpdate(word, meaning);
                break;
            case 2:
                cout << "Enter word to search: ";
                getline(cin, word);
                dictionary.search(word);
                break;
            case 3:
                cout << "Enter word to delete: ";
                getline(cin, word);
                dictionary.remove(word);
                break;
            case 4:
                dictionary.display();
                break;
            case 0:
                cout << "Program ended.\\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\\n";
        }
    } while (choice != 0);

    return 0;
}
