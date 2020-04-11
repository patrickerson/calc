#include <stdio.h>
#include <math.h>


char hex[16] =  {
    '0', '1', '2', '3', '4', '5', '6', '7', 
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    };

char octal[8] = {
    '0', '1', '2', '3', '4', '5', '6', '7'
    };

char bin[2] =   {
    '0', '1'    
    };

int number_bits = 8;   int hex_digits = 2;   int octal_digits = 3;



void global_from_dec_conversor(
    int dec_value, 
    char* table, 
    int digits, 
    int size_table, 
    char* result){

    double acc = dec_value;
    for(int i=digits-1; i>=0;i--){
        int int_acc;
        acc = acc / size_table;
        int_acc = acc;
        int pos = (acc - int_acc) * size_table;
        result[i] = table[pos];
    }
}


int global_to_dec_conversor(char* array, int digits, char* table, int size_table){
    int acc = 0;
        for(int i=0; i<digits;i++){
            for(int pos = 0; pos<size_table;pos++){
                if(array[i] == table[pos]){
                    double value =  pos * pow(size_table, digits -1 -i);
                    acc += value;
                }
            }
        }
        return acc;
}

void dec_bin(int value, char* result){
    global_from_dec_conversor(value, bin, number_bits, 2, result);
}

int bin_dec(char* array){
    return global_to_dec_conversor(array, number_bits, bin, 2);
}

void dec_hex(int decimal, char* result){
    global_from_dec_conversor(decimal, hex, hex_digits, 16, result);
}


int hex_dec(char* array){
    return global_to_dec_conversor(array, hex_digits, hex, 16);
}


void dec_octal(int decimal, char* result){
    global_from_dec_conversor(decimal, octal, octal_digits, 8, result);
}


int octal_dec(char* array){
    return global_to_dec_conversor(array, octal_digits, octal, 8);
}


void main(){
    char array[number_bits];
    dec_bin(200, array);
    
    char hex_array[hex_digits];
    dec_hex(bin_dec(array), hex_array);
    hex_dec(hex_array);
    
    char octal_array[octal_digits];
    dec_octal(hex_dec(hex_array), octal_array);
    for(int i=0; i<number_bits; i++){
    printf("%c", array[i]);
    }
}
