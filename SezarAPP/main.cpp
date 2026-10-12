#include <iostream>
#include <string>

using namespace std;

// Sezar Şifreleme (Türkçe harf destekli ve güvenli)
string caesarCipher(string text, int shift, bool encrypt) {
    string result = "";
    string alphabet = "abcçdefgğhıijklmnoöprsştuüvyz";
    string uppercase = "ABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ";
    int len = 29; // Tam Türkçe alfabe uzunluğu

    if (!encrypt) {
        shift = (len - (shift % len)) % len;
    } else {
        shift = shift % len;
    }

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];
        bool matched = false;

        // Küçük harf kontrolü
        for (int j = 0; j < len; ++j) {
            if (alphabet[j] == c) {
                result += alphabet[(j + shift) % len];
                matched = true;
                break;
            }
        }

        if (matched) continue;

        // Büyük harf kontrolü
        for (int j = 0; j < len; ++j) {
            if (uppercase[j] == c) {
                result += uppercase[(j + shift) % len];
                matched = true;
                break;
            }
        }

        // Alfabe dışı karakterler (boşluk, nokta, virgül vb.) aynen kalır
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
    cout << "2. Sifreli Metni Cöz" << endl;
    cout << "Seciminiz (1 veya 2): ";
    
    // Seçimi metin olarak alıyoruz ki nokta, virgül veya harf girildiğinde program çökmesin
    getline(cin, choiceInput);

    // Girdi sadece "1" veya "2" değilse geçersiz say
    if (choiceInput == "1") {
        choice = 1;
    } else if (choiceInput == "2") {
        choice = 2;
    } else {
        cout << "\nGecersiz secim! Lütfen sadece 1 veya 2 yazin." << endl;
        return 0;
    }

    cout << "Anahtar sayisini girin (Örn: 3): ";
    cin >> shift;

    cin.ignore(); // Arabelleği temizle
    cout << "Metni girin: ";
    getline(cin, text);

    if (choice == 1) {
        cout << "\nSifreli Metin: " << caesarCipher(text, shift, true) << endl;
    } else if (choice == 2) {
        cout << "\nCözülmüs Metin: " << caesarCipher(text, shift, false) << endl;
    }

    return 0;
}