#include <stdio.h>
#include "cs50.h"
#include <math.h>
#include <string.h>

bool checkIfValid(string []);

int main(int argc, string argv[]){

    if(argc == 1 || argc > 2) {

        printf("Error: Must provide exactly one key\n");
        return 1;


    } else {

        bool invalid = checkIfValid(argv);
        if(invalid){
            return 1;
        }

        string alpha_lower = "abcdefghijklmnopqrstuvwxyz";
        string alpha_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string plain = get_string("plaintext: ");
        char cypher[strlen(plain)];

        int ctr = 0;
        while(plain[ctr] != '\0'){

/*            bool isUpper = false;
            bool isLower = false*/
            int position = 0;

            if(plain[ctr] >= 65 && plain[ctr] <= 90){

                //isUpper = true;
                for(int i = 0; i <= 25 ; ++i){
                    if(plain[ctr] == alpha_upper[i]){
                        position = i;
                        break;
                    }
                }

                if(argv[1][position] >= 65 && argv[1][position] <= 90){
                    cypher[ctr] = argv[1][position];
                } else {
                    cypher[ctr] = argv[1][position] - 32;
                }


            } else if(plain[ctr] >= 97 && plain[ctr] <= 122) {

               // isLower = true;
                for(int i = 0; i <= 25 ; ++i){
                    if(plain[ctr] == alpha_lower[i]){
                        position = i;
                        break;
                    }
                }

                if(argv[1][position] >= 97 && argv[1][position] <= 122){
                    cypher[ctr] = argv[1][position];
                } else {
                    cypher[ctr] = argv[1][position] + 32;
                }

            } else{
                cypher[ctr] = plain[ctr];
            }

            ++ctr;

        }

        printf("ciphertext: %s\n", cypher);

    }

}


bool checkIfValid(string argv[]){

        int ctr = 0;
        bool isNotAlpha;
        bool isNotExactLength;
        bool isCharRepeated;

        //checking if all characters are alphabetical
        while(argv[1][ctr] != '\0'){

            isNotAlpha = (argv[1][ctr] < 65) || (argv[1][ctr] > 90 && argv[1][ctr] < 97) || (argv[1][ctr] > 122);

            if( isNotAlpha ){
                printf("Invalid Key: Must only contain alphabetic characters\n");
                return isNotAlpha;
            }

            ++ctr;

        }

        //checking if there are 26 characters in string
        isNotExactLength = (ctr!=26);
        if ( isNotExactLength ){
            printf("Key must contain 26 characters.\n");
            return isNotExactLength;
        }

        //checking if all characters are unique
        for(int i = 0; i < 25 ; ++i){
            for(int j = i + 1; j <= 25 ; ++j ){
                if(argv[1][i] == argv[1][j]){
                    isCharRepeated = true;
                    printf("Key must not contain repeated characters.\n");
                    return isCharRepeated;
                }
            }
        }


        return false;
}