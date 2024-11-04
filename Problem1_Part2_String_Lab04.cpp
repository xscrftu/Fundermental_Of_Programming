#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char str[]){
    int len = strlen(str);
    for (int i = 0; i < len/2; ++i)
    {
        swap(str[i], str[len - i - 1]);
    }
}

int isPalindromeString(char str[]) {
    for (int  i = 0; i < strlen(str)/2; ++i)
    {
        if (str[i] != str[strlen(str) - i - 1]){
            return 0;
        }
    }
    return 1;
}

int countOccurrencesChar(char str[], char c){
    int count = 0;
    for (int  i = 0; i < strlen(str); ++i)
    {
        if (str[i] == c){
            ++count;
        }
    }
    return count;
}

int findMostCommonChar(char str[], char &most_common_char) {
    int frequency[256] = {0};  // Mảng để đếm tần suất của từng ký tự ASCII
    int max_count = 0;

    // Đếm tần suất của từng ký tự
    for (int i = 0; str[i] != '\0'; i++) {
        frequency[(unsigned char)str[i]]++;

        // Cập nhật max_count và most_common_char nếu ký tự hiện tại có tần suất lớn hơn
        if (frequency[(unsigned char)str[i]] > max_count) {
            max_count = frequency[(unsigned char)str[i]];
            most_common_char = str[i];
        }
    }

    return max_count;
}

void insertCharAtPosition(char str[], char chr, int idx) {
    int len = strlen(str);  // Độ dài của chuỗi ban đầu

    // Kiểm tra nếu idx nằm ngoài độ dài của chuỗi ban đầu
    if (idx < 0 || idx > len) {
        cout << "Vị trí không hợp lệ!" << endl;
        return;
    }

    // Dịch chuyển các ký tự sang bên phải để chừa chỗ cho ký tự mới
    for (int i = len; i >= idx; i--) {
        str[i + 1] = str[i];
    }

    // Chèn ký tự vào vị trí idx
    str[idx] = chr;

    // Đảm bảo chuỗi có ký tự kết thúc '\0'
    str[len + 1] = '\0';
}

void formatNumberWithCommas (char str[]){
    int len = strlen(str);
    int comma_interval = 3 ;
    for (int i = len - comma_interval; i > 0; i -= comma_interval) {
        insertCharAtPosition(str, ',', i);
    }
}
int main(){
    char str[11] = "1234567890";
    formatNumberWithCommas(str);
    cout << str << endl;
    return 0;
}   