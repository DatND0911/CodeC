#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FILENAME "UartXproduction.hex"
#define MAXLENGTH 300

unsigned char buff[65536];
int ReadHexfile(char *strline);
void ParseHexLine(unsigned char *strLine, int nLength);
void checkSum(unsigned char *hexarr);
void Hex_to_ASCII(unsigned char arr[], int str_len);
int line_count = 0;

int main(int argc, char *argv[]) {
    FILE *fptr;
    char strLogFile[MAXLENGTH] = FILENAME;
    unsigned char strLine1[MAXLENGTH];
    if (argc > 1) strcpy(strLogFile, argv[1]);
    char *dot = strrchr(FILENAME, '.');
    if (dot && strcmp(dot, ".hex")) {
        printf("The file is not a hex file");
        exit(1);
    }
    fptr = fopen(strLogFile, "r");
    if (fptr == NULL) {
        printf("Can't open the file: %s", strLogFile);
        exit(1);
    }
    
    while (fgets(strLine1, MAXLENGTH, fptr) != NULL) { // read a line from pointer fptr and store it into str
        line_count++;
        checkSum(strLine1);
        int nHexLength = ReadHexfile(strLine1);
        ParseHexLine(buff, nHexLength);
        printf("\n");
        // print 25 lines
        if (line_count % 25 == 1 && line_count > 1) {
            printf("\nDo you want to continue printing?(y/n)\n");
            int input = getch();
            while (input != 121) {
                if (input == 110) {
                    exit(1);
                } else if (input != 121) {
                    printf("Please enter your option again\n");
                    input = getch();
                }
            }
            system("cls");
        }
    }
    /* check EOF or Error why.... */
    if (feof(fptr)) {
        printf("\nRead to the end of file : %s", strLogFile);
    } else {
        /* Error */
        printf("\nThe line is too long in File : %s", strLogFile);
    }
    fclose(fptr);
    return 0;
}

int getVal(char c, int cnt) {
    int rtVal = 0;
    if (c >= '0' && c <= '9') {
        rtVal = c - '0';
    } else if (c >= 'a' && c <= 'f') {
        rtVal = c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
        rtVal = (c - 'A' + 10);
    }
    return rtVal;
}

int ReadHexfile(char *a) {
    int nLength, cnt;
    nLength = strlen(a);
    unsigned char c1, c2, sum;

    if (a[0] != ':')
        cnt++; // mark the first character at line to read hex.file

    int i = 1, j = 0;
    while (i < nLength - 1) {
        c1 = getVal(a[i++], cnt); // return value in interger of c1
        c2 = getVal(a[i++], cnt); // return value in interger of c2
        sum = c1 << 4 | c2;
        buff[j++] = sum;
    }
    return j;
}

void checkSum(unsigned char *hexarr) {
    int cnt = 0;
    int c1 = 0, c2 = 0;
    int i = 1, index = 0, sum; // index of each 2 bytes

    while (i < strlen(hexarr) - 2) {
        c1 = getVal(hexarr[i++], cnt); // return value in interger of c1
        c2 = getVal(hexarr[i++], cnt); // return value in interger of c2
        sum = c1 << 4 | c2;
        index = (i / 2) - 1;
        buff[index] = sum;
    }
    int checksum = 0;
    for (int j = 0; j <= index; j++) {
        checksum = checksum + buff[j]; // caluclate sum of arr[i]
    }
    if (checksum % 256 != 0) {
        printf("__________Error check sum at line %d!!!__________\n",line_count);
        exit(1);
    }
}

// Format again line of Hexfile
struct Format {
    unsigned char nData[16];
    unsigned char nByteCount;
    unsigned char nHighAddress;
    unsigned char nLowAddress;
    unsigned char nRecordType;
    unsigned char nCheckSum;
} Format;

// Parse data in format and save it to str
void ParseHexLine(unsigned char *str, int nLenght) {
    Format.nByteCount = str[0];
    Format.nHighAddress = str[1];
    Format.nLowAddress = str[2];
    Format.nRecordType = str[3];
    Format.nCheckSum = str[nLenght - 1];
    int data_index = 0;
    for (int i = 4; i < nLenght - 1; i++) {
        Format.nData[data_index++] = str[i];
    }

    if (Format.nByteCount != 0) {
        if (Format.nRecordType == 00 || Format.nRecordType == 01) { // read data if recodetype of hex line are 00 or 01
            printf("0000");
            printf("%02x", Format.nHighAddress);
            printf("%02x", Format.nLowAddress);
            printf("    ");
            // print data hexfile
            for (int k = 0; k < 16; k++) {
                printf(" %02x", Format.nData[k]);
            }
            printf("    ");
            Hex_to_ASCII(Format.nData, data_index); // print ascii character
        } else if (Format.nRecordType == 01) {
            exit(0);
        }
    }
}

// conver format to decimal
int Hex_to_dec(unsigned char arr) {
    int d = arr - 32;
    if (d <= 0)
        return 46;
    else
        return arr;
}

// convert decimal type to ascci
void Hex_to_ASCII(unsigned char arr[], int leng_arr) {
    int dec[leng_arr];
    for (int i = 0; i < leng_arr; i++) {
        dec[i] = Hex_to_dec(arr[i]);
    }
    for (int j = 0; j < leng_arr; j++) {
        printf("%c", dec[j]);
    }
}
