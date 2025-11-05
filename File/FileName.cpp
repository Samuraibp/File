#include <iostream>
using namespace std;

char caesar(char ch, int key) {

    if (ch >= 'a' && ch <= 'z')
        return char((ch - 'a' + key) % 26 + 'a');
    if (ch >= 'A' && ch <= 'Z')
        return char((ch - 'A' + key) % 26 + 'A');

    
    if (ch >= 'а' && ch <= 'я')
        return char((ch - 'а' + key) % 32 + 'а');
    if (ch >= 'А' && ch <= 'Я')
        return char((ch - 'А' + key) % 32 + 'А');

    return ch; 
}

int main() {
    setlocale(LC_ALL, "");

    FILE* out;
    fopen_s(&out, "output.txt", "w");  

    if (!out) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }

    const int key = 3;
    char text[256];

    cout << "Введите текст для шифрования: ";
    cin.getline(text, 256); 

    for (int i = 0; text[i] != '\0'; i++) {
        char encoded = caesar(text[i], key);
        fputc(encoded, out);
    }

    fclose(out);

    cout << "Текст успешно зашифрован и записан в файл output.txt" << endl;
}
