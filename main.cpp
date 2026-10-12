#include <iostream>
#include <string>

using namespace std;

// Sezar Åifreleme (TÃ¼rkÃ§e harf destekli ve gÃ¼venli)
string caesarCipher(string text, int shift, bool encrypt) {
    string result = "";
    string alphabet = "abcÃ§defgÄŸhÄ±ijklmnoÃ¶prsÅŸtuÃ¼vyz";
    string uppercase = "ABCÃ‡DEFGÄHIÄ°JKLMNOÃ–PRSÅTUÃœVYZ";
    int len = 29; // Tam TÃ¼rkÃ§e alfabe uzunluÄŸu

    if (!encrypt) {
        shift = (len - (shift % len)) % len;
    } else {
        shift = shift % len;
    }

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];
        bool matched = false;

        // KÃ¼Ã§Ã¼k harf kontrolÃ¼
        for (int j = 0; j < len; ++j) {
            if (alphabet[j] == c) {
                result += alphabet[(j + shift) % len];
                matched = true;
                break;
            }
        }

        if (matched) continue;

        // BÃ¼yÃ¼k harf kontrolÃ¼
        for (int j = 0; j < len; ++j) {
            if (uppercase[j] == c) {
                result += uppercase[(j + shift) % len];
                matched = true;
                break;
            }
        }

        // Alfabe dÄ±ÅŸÄ± karakterler (boÅŸluk, nokta, virgÃ¼l vb.) aynen kalÄ±r
        if (!matched) {
            result += c;
        }
    }

    return result;
}

int main() {
    string choiceInput;
    int choice, shift;
    string text;

    cout << "=== Turkce Destekli Sezar Sifreleme ===" << endl;
    cout << "1. Metin Sifrele" << endl;
    cout << "2. Sifreli Metni CÃ¶z" << endl;
    cout << "Seciminiz (1 veya 2): ";
    
    // SeÃ§imi metin olarak alÄ±yoruz ki nokta, virgÃ¼l veya harf girildiÄŸinde program Ã§Ã¶kmesin
    getline(cin, choiceInput);

    // Girdi sadece "1" veya "2" deÄŸilse geÃ§ersiz say
    if (choiceInput == "1") {
        choice = 1;
    } else if (choiceInput == "2") {
        choice = 2;
    } else {
        cout << "\nGecersiz secim! LÃ¼tfen sadece 1 veya 2 yazin." << endl;
        return 0;
    }

    cout << "Anahtar sayisini girin (Ã–rn: 3): ";
    cin >> shift;

    cin.ignore(); // ArabelleÄŸi temizle
    cout << "Metni girin: ";
    getline(cin, text);

    if (choice == 1) {
        cout << "\nSifreli Metin: " << caesarCipher(text, shift, true) << endl;
    } else if (choice == 2) {
        cout << "\nCÃ¶zÃ¼lmÃ¼s Metin: " << caesarCipher(text, shift, false) << endl;
    }

    return 0;
}
