#include <stdio.h>
#include <math.h>


char hex[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7', 
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

char octal[8] = {
    '0', '1', '2', '3', '4', '5', '6', '7'};

int number_bits  = 8;
int hex_digits   = 2;
int octal_digits = 3;

void dec_bin(int value, int* result){
    int pos = number_bits;
    
    for(int i=0;i<number_bits;i++){
        result[i] = 0;
    }
     printf("\n");
    while(value > 0){
        
        pos--;
        if((value % 2) == 0){
            result[pos] = 0;
        }else{
            result[pos] = 1;
        }
        value = value/2;
       
    }



}

int bin_dec(int value[number_bits]){
    double mult;
    double pos;
    int result;
    for(int i =0; i<number_bits;i++){
      int acc;
        if( value[i] == 1){
            pos = number_bits -i -1;
            mult = pow(2, pos);
            acc +=mult;
            
        }
     
      result = acc;
    }
    return result;

    
}

void dec_hex(int decimal, char* result){
    double acc = decimal;
    
    for(int i=hex_digits-1; i>=0;i--){
        int int_acc;
        acc = acc / 16;
        int_acc = acc;
        int pos = (acc - int_acc) * 16;
        result[i] = hex[pos];


    }

}


int hex_dec(char* array){
    int acc = 0;
    for(int i=0; i<hex_digits;i++){
        for(int pos_hex = 0; pos_hex<16;pos_hex++){
            
            if(array[i] == hex[pos_hex]){
                double value =  pos_hex * pow(16, hex_digits -1 -i);
                acc += value;
               
            }
        }
    }
    return acc;

}

void dec_octal(int decimal, char* result){
    double acc = decimal;

    for(int i=octal_digits -1; i>=0;i--){
        int int_acc;

        acc = acc / 8;
        int_acc = acc;
        int pos = (acc - int_acc) * 8;
        result[i] = octal[pos];

    }
}

int octal_dec(char* array){
    int acc = 0;
    for(int i=0; i<octal_digits;i++){
        for(int pos_octal = 0; pos_octal<8;pos_octal++){
            
            if(array[i] == hex[pos_octal]){
                double value =  pos_octal * pow(8, octal_digits -1 -i);
                acc += value;
               
            }
        }
    }
    return acc;
}



void main(){
    int array[number_bits];
    dec_bin(200, array);
    
    char hex_array[2];
    dec_hex(bin_dec(array), hex_array);
    hex_dec(hex_array);

    char octal_array[3];
    dec_octal(hex_dec(hex_array), octal_array);

    for(int i=0;i<3;i++){
        printf("%c", octal_array[i]);
    }
      printf("\n%d\n", octal_dec(octal_array));
}