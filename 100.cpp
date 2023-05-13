#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void generate(char* arr, int i, string s, int len, bool verbose)
{
    if (i == 0) {
        if (verbose)
            cout << s << endl;

        if (s == "azb") {
            cout << "MATCH!: " << s << endl;
            exit(0);
        }
        return;
    }

    for (int j = 0; j < len; j++) {

        string appended = s + arr[j];
        generate(arr, i - 1, appended, len, verbose);
    }

    return;
}

void crack(char* arr, int len, bool verbose) {
    for (int i = 1; i <= len; i++) {
        generate(arr, i, "", len, verbose);
    }
}

int main(int argc, char* argv[]) {
    chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();

    /*char arr[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
        '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^',
        '_', '`', '{', '|', '}', '~'
    };*/

    bool verbose = false;
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string specials = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    string japanese = "あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをん";
    string russian = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    string arabic = "اأإآبتثجحخدذرزسشصضطظعغفقكلمنهوي";
    string chinese = "你好世界";
    string korean = "ㄱㄴㄷㄹㅁㅂㅅㅇㅈㅊㅋㅌㅍㅎㅏㅑㅓㅕㅗㅛㅜㅠㅡㅣㄲㄸㅃㅆㅉㄳㄵㄶㄺㄻㄼㄽㄾㄿㅀㅄ";
    string hindi = "अआइईउऊऋएऐओऔकखगघचछजझटठडढणतथदधनपफबभमयरलवशषसह";
    string charset;

    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-l" || string(argv[i]) == "--lowercase") {
            charset += lowercase;
        } else if (string(argv[i]) == "-u" || string(argv[i]) == "--uppercase") {
            charset += uppercase;
        } else if (string(argv[i]) == "-n" || string(argv[i]) == "--numbers") {
            charset += numbers;
        } else if (string(argv[i]) == "-s" || string(argv[i]) == "--special") {
            charset += specials;
        } else if (string(argv[i]) == "-j" || string(argv[i]) == "--japanese") {
            charset += japanese;
        } else if (string(argv[i]) == "-r" || string(argv[i]) == "--russian") {
            charset += russian;
        } else if (string(argv[i]) == "-c" || string(argv[i]) == "--chinese") {
            charset += chinese;
        } else if (string(argv[i]) == "-a" || string(argv[i]) == "--arabic") {
            charset += arabic;
        } else if (string(argv[i]) == "-k" || string(argv[i]) == "--korean") {
            charset += korean;
        } else if (string(argv[i]) == "-h" || string(argv[i]) == "--hindi") {
            charset += hindi;
        } else if (string(argv[i]) == "-v" || string(argv[i]) == "--verbose") {
            verbose = true;
        }
    }


    char arr[charset.length() + 1];
    strcpy(arr, charset.c_str());

    int len = strlen(arr);
    crack(arr, len, verbose);

    chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    cout << "Execution time: " << duration.count() << " ms" << endl;

    return 0;
}
