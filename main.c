#include <stdio.h>
#include <string.h>

void append(char user_array[], char letter); 

void zip(char dest[],char input_array1[],char input_array2[], int length); 
void zip_leftovers(char dest[], char user_array_stream[], int start, int finish); 
void merge(char dest[], char user_array1[],char user_array2[] ); 

int main(void) {
  char sentence1[100]; 
  char sentence2[100];  
  char combined[200]; 

  for (int i = 0; i < 200; i++){
    combined[i] = 0; 
  }
  printf("enter your sentences: \n"); 
  scanf("%[^\n]%*c", sentence1); 
  scanf("%[^\n]%*c", sentence2);

  merge(combined, sentence1, sentence2); 
  // length1 = strlen(sentence1); 
  // length2 = strlen(sentence2); 

  // if (length1 == length2){
  //   printf("\npass 1");
  //   zip(combined, sentence1, sentence2, length1);
  // }
  // else if(length1 < length2){
  //   printf("\npass 2"); 
  //   zip(combined, sentence1, sentence2, length1);
  //   zip_leftovers(combined, sentence2, length1, length2); 
  // }
  //   else{
  //     printf("\npass 3"); 
  //   zip(combined, sentence1, sentence2, length2);
  //   zip_leftovers(combined, sentence1, length2, length1); 
  // }
  // printf("\n%s", combined); 
  return 0;
}


void append(char user_array[], char letter){ 
  int length = strlen(user_array);
  int temp = user_array[length]; 
  user_array[length] = letter;  
  user_array[length+1] = '\0';  
} 

void zip(char dest[],char input_array1[],char input_array2[], int length){
  for (int i = 0; i < length; i++){
  append(dest, input_array1[i]); 
  append(dest, input_array2[i]); 
  }
}

void zip_leftovers(char dest[], char user_array_stream[], int start, int finish){
  for (int i = start; i < finish; i++){
  append(dest, user_array_stream[i]); 
  }
}

void merge(char dest[], char user_array1[],char user_array2[] ){
  int length1 = strlen(user_array1); 
  int length2 = strlen(user_array2); 

  if (length1 == length2){
    printf("\npass 1");
    zip(dest, user_array1, user_array2, length1);
  }
  else if(length1 < length2){
    printf("\npass 2"); 
    zip(dest, user_array1, user_array2, length1);
    zip_leftovers(dest, user_array2, length1, length2); 
  }
    else{
      printf("\npass 3"); 
    zip(dest, user_array1, user_array2, length2);
    zip_leftovers(dest, user_array1, length2, length1); 
  }
  printf("\n%s", dest); 
}