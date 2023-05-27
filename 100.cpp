#include <iostream>
#include <fstream> // Include the necessary header for file operations
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

void generate(char* arr, int i, string s, int len, bool verbose, ofstream& outputFile)
{
    if (i == 0) {
        if (verbose)
            cout << s << endl;

        // Write to the output file if it is open
        if (outputFile.is_open())
            outputFile << s << endl;

        return;
    }

    for (int j = 0; j < len; j++) {

        string appended = s + arr[j];
        generate(arr, i - 1, appended, len, verbose, outputFile);
    }

    return;
}

void crack(char* arr, int len, bool verbose, ofstream& outputFile) {
    for (int i = 1; i <= len; i++) {
        generate(arr, i, "", len, verbose, outputFile);
    }
}

int main(int argc, char* argv[]) {
    chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();

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
    string greek = "αβγδεζηθικλμνξοπρστυφχψω";
    string charset;

    ofstream outputFile; // Declare the output file stream

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
	    } else if (string(argv[i]) == "-g" || string(argv[i]) == "--greek") {
	        charset += greek;
        } else if (string(argv[i]) == "-v" || string(argv[i]) == "--verbose") {
            verbose = true;
        } else if (string(argv[i]) == "-o" || string(argv[i]) == "--output") {
            if (i + 1 < argc) {
                string outputFilename = argv[i + 1];
                outputFile.open(outputFilename);

                if (!outputFile.is_open()) {
                    cerr << "Error: Unable to open the output file." << endl;
                    return 1;
                }

                i++; // Skip the next argument
            } else {
                cerr << "Error: Missing filename for the output file." << endl;
                return 1;
            }
        }
    }

    char arr[charset.length() + 1];
    strcpy(arr, charset.c_str());

    int len = strlen(arr);
    crack(arr, len, verbose, outputFile);

    // Close the output file if it was opened
    if (outputFile.is_open()) {
        outputFile.close();
    }

    chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();
    chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);
    cout << "Execution time: " << duration.count() << " ms" << endl;

    return 0;
}
