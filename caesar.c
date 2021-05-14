#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(int argc, string argv[]) 
{
    //make sure user enters only one string
    int key = 0;
    if (argc == 2)
    {   
        //convert strint to digit
        key = atoi(argv[1]);
    }
    
    //make sure the key is an interger
    if (key > 0) 
    {
        //Get plain text from user
        string plainText = get_string("Enter Text: ");
       
        //Get the length of the text
        int n = strlen(plainText);
       
        //The program will print out this variable 
        char ciphertext[n];
       
        //loop through every letter in the string
        for (int i = 0; i < n; i++)
        {
            if (isalpha(plainText[i]))
            {
                if (isupper(plainText[i]))
                {
                    int text = plainText[i] - 'A';
                    int cipher = (text + key) % 26;
                    ciphertext[i] = cipher + 65;
                }
                else if (islower(plainText[i]))
                {
                    int text = plainText[i] - 'a';
                    int cipher = (text + key) % 26;
                    ciphertext[i] = cipher + 'a';
                }
            }
            else 
            {
                ciphertext[i] = plainText[i];
            }
        }
       
        printf("ciphertext: %s\n", ciphertext);
        
        return 0;
       
    }
    else
    {
        printf("usage: %s key\n", argv[0]);
        return 1; 
    }
    
}



