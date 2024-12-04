#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void readZip(const char *zipPath, char *names[], int &N) {
    ifstream zipFile(zipPath, ios::binary);
    if (!zipFile.is_open()){
        cerr << "Can not open file";
        return;
    }
    zipFile.seekg(-22, ifstream::end);
    char end_block[22]; // Phần tử cuối không nhất thiết phải là '\0' đối với binaryfile
    zipFile.read(end_block, 22);
    /*
        End block signature 0x06054b50 được lưu theo thứ tự byte little-endian
        ~~~ nghĩa là byte thấp nhất sẽ được lưu trữ trước
        Khi lưu vào mảng char thì end_block sẽ trông như sau
        end_block[0] = 0x50   Byte thấp nhất (LSB)
        end_block[1] = 0x4b
        end_block[2] = 0x05
        end_block[3] = 0x06   Byte cao nhất (MSB)
    */

    // Kiểm tra liệu end_block có đúng hay không
    if (end_block[0] != 0x50 || end_block[1] != 0x4b || end_block[2] != 0x05 || end_block[3] != 0x06){
        cerr << "End_block error";
        return;
    }
    /*
        end_block[10] và end_block[11] lưu giá trị total file entries
        end_block[10] là byte thấp nhất của total file entries (LSB)
        end_block[11] là byte cao nhất của total file entries (MSB)

    */
    unsigned short total_file_entry; // Ở đây dùng unsigned short bởi vì kích thước nó là 2 bytes = với giá trị total_file_entries
    
    total_file_entry = end_block[10] | (end_block[11] << 8); // Dịch trái 8 bit để gộp lại với end_block[10]
    int byte_offset_central_directory; // int kích thước 4 byte phù hợp với byte size của Byte offset of the central directory
    byte_offset_central_directory = end_block[16] | (end_block[17] << 8) | (end_block[18] << 16) | (end_block[19] << 24); // gộp bit tương tự total_file_entries

    zipFile.seekg(byte_offset_central_directory, ios::beg);

    for (int i = 0; i < total_file_entry; ++i)
    {
        char fileEntry[46]; // Cố định để đọc và tìm được M H K
        zipFile.read(fileEntry, 46);
        
        // Kiểm tra liệu fileEntry có lỗi không
        if (fileEntry[0] != 0x50 || fileEntry[0] != 0x4b || fileEntry[0] != 0x01 || fileEntry[0] != 0x02){
            cerr << "Invalid File entry signature";
            return;
        }

        // Tính giá trị M H K giống total_file_entry ở trên
        unsigned short file_name_length = fileEntry[28] | (fileEntry[29] << 8);
        unsigned short extra_field_length = fileEntry[30] | (fileEntry[31] << 8);
        unsigned short file_comment_length = fileEntry[32] | (fileEntry[33] << 8);
        unsigned int entrySize = 46 + file_name_length + extra_field_length + file_comment_length;
        
        char* fileName = new char[file_comment_length + 1]; // Cấp phát động cho fileName
        zipFile.read(fileName, file_name_length);
        fileName[file_comment_length] = '\0';

        zipFile.seekg(extra_field_length + file_comment_length, ios::cur);
        names[i] = fileName;
    }
    N = total_file_entry;
}
int main(){
    return 0;
}