#include <stdio.h>
#include <string.h>
#include <ctype.h>

void append(char user_array[], char letter); 
void zip(char dest[],char input_array1[],char input_array2[], int length); 
void zip_leftovers(char dest[], char user_array_stream[], int start, int finish); 
char *merge(char dest[], char user_array1[],char user_array2[] ); 
char *reversed(char input_array[]);
// void percentage_table(char input_array1[], char input_array2[]); 
// void data_tabe(char input_array1[], char input_array2[]); 


#define sentence_size 350

int main(void) {
  char sentence1[sentence_size]; 
  char sentence2[sentence_size];  
  char combined[sentence_size*2] = { 0 }; 
  
  printf("enter your sentences: \n"); 
  scanf("%[^\n]%*c", sentence1); 
  scanf("%[^\n]%*c", sentence2);

  printf("\n%-11s%s","combined: " ,merge(combined, sentence1, sentence2));
  printf("\n%-11s%s","reversed: " ,reversed(combined));

  // percentage_table(sentence1, sentence2); 
  return 0;
} 

void append(char user_array[], char letter){ 
  // store the length of user_array
  int length = strlen(user_array);
  // set the last index to the element to be added
  user_array[length] = letter;  
  // add the null character to the end of the list 
  user_array[length+1] = '\0';  
} 

// function which takes turns storing elements from 2 lists with length being the amount of pairs to store. 
void zip(char dest[],char input_array1[],char input_array2[], int length){
  // 0 - n where n is the length specified by the user
  for (int i = 0; i < length; i++){
    // put the input_array1[i] element at the end of the destination array
    append(dest, input_array1[i]); 
    // put the input_array2[i] element at the end of the destination array
    append(dest, input_array2[i]); 
  }
}

// function to store the excess elements which had no pairs 
void zip_leftovers(char dest[], char user_array_stream[], int start, int finish){
  // range to access indexs, the range is decided by the user with start and finish
  for (int i = start; i < finish; i++){
    //add user_array_stream[i] to the end of the destination array 
    append(dest, user_array_stream[i]); 
  }
}

char *merge(char dest[], char user_array1[],char user_array2[] ){
  int length1 = strlen(user_array1); 
  int length2 = strlen(user_array2); 

  if (length1 == length2){
    zip(dest, user_array1, user_array2, length1);
  }
  else if(length1 < length2){
    zip(dest, user_array1, user_array2, length1);
    zip_leftovers(dest, user_array2, length1, length2); 
  }
    else{
    zip(dest, user_array1, user_array2, length2);
    zip_leftovers(dest, user_array1, length2, length1); 
  }
  char *dest_pointer = dest; 
  return dest_pointer; 
}

char *reversed(char input_array[]){
  int length = strlen(input_array);
  char reversed_array[sentence_size*2] = {0}; 
  for (int i = length; i >= 0; i-- ){
    append(reversed_array, input_array[i]);  
  }
  char *reversed = reversed_array; 
  return reversed; 
}



void percentage_table(char input_array1[], char input_array2[]){
  float digit_cent1; 
  float symbol_cent1;
  float lower_cent1;
  float upper_cent1; 
  float space_cent1; 
  int length1 = strlen(input_array1); 
  float digit_count1 = 0; 
  float symbol_count1 = 0; 
  float lower_count1 = 0;
  float upper_count1 = 0; 
  float space_count1 = 0; 

  float digit_cent2; 
  float symbol_cent2;
  float lower_cent2;
  float upper_cent2; 
  float space_cent2; 
  int length2 = strlen(input_array2); 
  float digit_count2 = 0; 
  float symbol_count2 = 0; 
  float lower_count2 = 0;
  float upper_count2 = 0; 
  float space_count2 = 0; 

  
  for (int i = 0; i < length1; i++){

    if (isdigit(input_array1[i]) != 0){
      digit_count1++; 
    }
    else if (ispunct(input_array1[i]) != 0){
      symbol_count1++; 
    }
    else if (islower(input_array1[i]) != 0){
      lower_count1++; 
    }
    else if (isupper(input_array1[i]) != 0 ){
      upper_count1++; 
    }
    else if (isspace(input_array1[i]) != 0){
      space_count1++; 
    }
  }



    for (int i = 0; i < length2; i++){

    if (isdigit(input_array2[i]) != 0){
      digit_count2++; 
    }
    else if (ispunct(input_array2[i]) != 0){
      symbol_count2++; 
    }
    else if (islower(input_array2[i]) != 0){
      lower_count2++; 
    }
    else if (isupper(input_array2[i]) != 0 ){
      upper_count2++; 
    }
    else if (isspace(input_array2[i]) != 0){
      space_count2++; 
    }
  }


  digit_cent1 = (digit_count1/ length1)*100; 
  upper_cent1 = (upper_count1/ length1)*100;
  lower_cent1 = (lower_count1/ length1)*100;
  symbol_cent1 = (symbol_count1/ length1)*100; 
  space_cent1 = (space_count1/ length1)*100; 

  digit_cent2 = (digit_count2/ length2)*100; 
  upper_cent2 = (upper_count2/ length2)*100;
  lower_cent2 = (lower_count2/ length2)*100;
  symbol_cent2 = (symbol_count2/ length2)*100; 
  space_cent2 = (space_count2/ length2)*100; 

  printf("\n");
  printf("\n|Char type| Sentence1 | Sentence2 |"); 
  printf("\n|Digits   |   %4.1f%%   |  %4.1f%%    |  " ,digit_cent1, digit_cent2);
  printf("\n|Lower    |   %4.1f%%   |  %4.1f%%    |  " ,lower_cent1, lower_cent2);
  printf("\n|Upper    |   %4.1f%%   |  %4.1f%%    |  " ,upper_cent1, upper_cent2);
  printf("\n|Symbols  |   %4.1f%%   |  %4.1f%%    |  " ,symbol_cent1, symbol_cent2);
  printf("\n|Space    |   %4.1f%%   |  %4.1f%%    |  " ,space_cent1, space_cent2);

}



void data_tabe(char input_array1[], char input_array2[]){



} 