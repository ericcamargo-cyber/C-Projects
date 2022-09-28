#include <stdio.h>

void write() {

    FILE *first_file;
    first_file = fopen("D:\\Documents\\CPP\\numbers.txt", "w");
    FILE *second_file;
    first_file = fopen("D:\\Documents\\CPP\\numbers.bin", "wb");
    int i = 1, j;
    printf("Input data %d: ", (i));
    while (scanf("%d", &j) ==1 ) {
       
        fprintf(first_file, "%d ", j);         
        fwrite(&j, sizeof(j), 1, second_file); 
        i++;                             
        printf("Input data %d: ", (i));
        
    }
    
    fclose(first_file);
    fclose(second_file);
    
}

void read() {

    int count = 0;
    int text, bin, idx;
    
    FILE *first_file;
    first_file = fopen("D:\\Documents\\CPP\\numbers.txt", "r");
    FILE *second_file;
    second_file = fopen("D:\\Documents\\CPP\\numbers.bin", "rb");
    printf("Input idx: ");
    getchar();      
    scanf("%d", &idx); 
    
    while (count < idx && fscanf(first_file, "%d", &text) != EOF && fread(&bin, sizeof(bin), 1, second_file) != EOF) {
    
        count++;
        
    }

    fclose(first_file);
    fclose(second_file);
    printf("the integer was saved in text file: %d\n", text); 
    printf("the integer was saved in binary file: %d\n", bin);
    
}

int main() {

    write();
    read();
    return 0;
    
}