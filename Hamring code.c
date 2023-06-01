#include <stdio.h>
#include <stdlib.h>

int hammingParityBit(int *data, int length) {
    int parityBit = 0;
    for (int i = 0; i < length; i++) {
        parityBit ^= data[i];
    }
    return parityBit;
}

void hammingCode(int *data, int length, int *encodedData, int encodedLength) {
    int parityBitPosition = 1;
    int dataIndex = 0;
    
    for (int i = 1; i <= encodedLength; i++) {
        if (i == parityBitPosition) {
            encodedData[i - 1] = hammingParityBit(data, length);
            parityBitPosition *= 2;
        } else {
            encodedData[i - 1] = data[dataIndex++];
        }
    }
}

int main() {
    int data[] = {1, 0, 1, 1}; // Input data bits
    int dataLength = sizeof(data) / sizeof(data[0]);
    
    int encodedLength = dataLength + 2; // Number of bits after encoding
    int *encodedData = (int *)malloc(encodedLength * sizeof(int));
    
    hammingCode(data, dataLength, encodedData, encodedLength);
    
    printf("Hamming encoded data: ");
    for (int i = 0; i < encodedLength; i++) {
        printf("%d ", encodedData[i]);
    }
    printf("\n");
    
    free(encodedData);
    return 0;
}
