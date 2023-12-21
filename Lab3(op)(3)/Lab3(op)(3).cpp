#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    cout << "Input string: ";
    string text;
    getline(cin, text);

    // Завдання 1: Підрахунок кількості слів з непарною довжиною
    int oddLengthWordCount = 0;
    bool inWord = false;

    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            if (!inWord) {
                inWord = true;
                int wordLength = 1; // Починаємо з першої букви слова
                while (isalpha(text[i + wordLength])) {
                    wordLength++;
                }
                if (wordLength % 2 != 0) {
                    oddLengthWordCount++;
                }
            }
        }
        else {
            inWord = false;
        }
    }

    cout << "The number of words with an odd length: " << oddLengthWordCount << endl;

    // Завдання 2: Частота входження кожної літери
    map<char, int> letterFrequency;

    for (char ch : text) {
        if (isalpha(ch)) {
            ch = tolower(ch); // перетворення на нижній регістр
            letterFrequency[ch]++;
        }
    }

    cout << "Frequency of occurrence of each letter:" << endl;
    for (const auto& pair : letterFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Завдання 3: Видалення тексту, що знаходиться в круглих дужках
    size_t start = text.find('(');
    size_t end = text.find(')');

    while (start != string::npos && end != string::npos && start < end) {
        text.erase(start, end - start + 1);
        start = text.find('(');
        end = text.find(')');
    }

    cout << "The line where the text in brackets has been deleted:" << endl << text << endl;
}
