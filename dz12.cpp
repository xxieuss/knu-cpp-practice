#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// 2.
bool starts_with_error(const char *str) {
    const char prefix[] = "ERROR";
    const size_t len = 5;

    if (!str) return false;
    if (strnlen(str, len) < len) return false;

    for (size_t i = 0; i < len; ++i) {
        if (toupper((unsigned char)str[i]) != prefix[i])
            return false;
    }
    return true;
}

// 8.d
const char* find_last_longest_word(const char *str) {
    if (!str || !*str) return nullptr;

    const char *best_start = nullptr;
    size_t best_len = 0;
    const char *p = str;

    while (*p) {
        while (*p && (isspace((unsigned char)*p) || 
                      strchr(".,;:!?", *p))) {
            ++p;
        }
        if (!*p) break;

        const char *word_start = p;
        while (*p && !isspace((unsigned char)*p) && 
               !strchr(".,;:!?", *p)) {
            ++p;
        }

        size_t len = p - word_start;
        if (len > best_len) {
            best_len = len;
            best_start = word_start;
        }
    }
    return best_start;
}

// 11.
static int char_to_digit(char ch) {
    ch = (char)toupper((unsigned char)ch);

    if (ch == 'L' || ch == 'I' || ch == 'J') return 1;
    if (ch == 'U' || ch == 'W') return 2;
    if (ch == 'E') return 3;
    if (ch == 'C' || ch == 'H') return 4;
    if (ch == 'S' || ch == 'V') return 5;
    if (ch == 'B' || ch == 'G' || ch == 'D') return 6;
    if (ch == 'T' || ch == 'F') return 7;
    if (ch == '8' || ch == 'B') return 8;  // 'B' = 8
    if (ch == 'G' || ch == 'Q' || ch == 'g') return 9;  // 'g', 'q', 'G' = 9
    if (ch == 'O' || ch == 'Z' || ch == 'D') return 0;  // 'o', 'O', 'Z', 'D' = 0

    return -1;
}
bool decode_message(const char *msg, long long *result) {
    if (!msg || !result) return false;

    char number[16] = {0};
    size_t pos = 0;

    for (const char *p = msg; *p && pos < 15; ++p) {
        int d = char_to_digit(*p);
        if (d != -1) {
            number[pos++] = '0' + d;
        }
    }

    if (pos == 0) {
        *result = 0;
        return false;
    }

    number[pos] = '\0';
    char *endptr;
    *result = strtoll(number, &endptr, 10);
    return (*endptr == '\0' || *endptr == '\n');
}

int main(){
    // 2.
    const char *test_str1 = "error: file not found";
    cout << (starts_with_error(test_str1) ? "Starts with ERROR" : "Does not start with ERROR") << endl;
    // 8.d
    const char *test_str2 = "This is a test sentence, with some longwords!";
    const char *longest_word = find_last_longest_word(test_str2);
    if (longest_word) {
        cout << "Last longest word starts with: " << longest_word << endl;
    } else {
        cout << "No words found." << endl;
    }
    // 11.
    const char *test_str3 = "Hello World! G9QZ";
    long long decoded_number;
    if (decode_message(test_str3, &decoded_number)) {
        cout << "Decoded number: " << decoded_number << endl;
    } else {
        cout << "No valid digits found." << endl;
    }
    return 0;
}