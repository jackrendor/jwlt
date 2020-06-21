#include <iostream>
#include <cmath>

/**
 * Can we actually ignore this? Or someone wants to point out that there's a library that does this better than I do?
 */
size_t strlen(char* s){
    size_t r;
    if (s == NULL)
        return 0;
    for (r = 0; *s++ != '\0'; r++);
    return r;
}

/**
 * Increases the value of the array
 * @param tracker the array that contains the numbers to use as charset's index.
 * @param t_len array tracker lenght. How many element the tracker is made of.
 * @param c_len charset lenght. How many characters are in the charset.
 */
void increase(size_t *tracker, size_t t_len, size_t c_len){
    for (size_t i=0; i<t_len; i++){
        if (tracker[i] < c_len-1){
            tracker[i]++;
            return;
        }else{
            tracker[i] = 0;
        }
    }
}

/**
 * Prints the word based on the numbers in the @param tracker array.
 * if @param adiacent_check if true, it only prints words without adiacent identical char.
 * 
 * @param tracker the array that contains the numbers to use as charset's index.
 * @param charset the array that contains the charset.
 * @param psw_len lenght of the word to generate.
 * @param adiacent_check if true, it prints only words with no chars that are adiacent and equals.
*/
void print_tracker(size_t *tracker, const char *charset, size_t psw_len, bool adiacent_check){
    std::string result;
    for (size_t i=0; i<psw_len; i++){
        if (adiacent_check && i<psw_len-1 && tracker[i] == tracker[i+1])
            return;
        result += charset[tracker[i]];
    }
    std::cout << result << std::endl;
}

/**
 * Increases the tracker array and prints it's result based on the give charset
 * @param tracker the array that contains the numbers to use as charset's index.
 * @param CHARSET the array that contains the charset.
 * @param PSWD_LEN lenght of the word to generate.
 * @param C_LEN lenght of @param CHARSET
 * @param ADIACENT_CHECK if true, it prints only words with no chars that are adiacent and equals
 */
void wordlist_generator(size_t *tracker, const char *CHARSET, size_t PSWD_LEN, size_t C_LEN, bool ADIACENT_CHECK){
    size_t combinations = pow(C_LEN, PSWD_LEN);
    print_tracker(tracker, CHARSET, PSWD_LEN, ADIACENT_CHECK);
    for (size_t i=0; i<combinations; i++, increase(tracker, PSWD_LEN, C_LEN))
        print_tracker(tracker, CHARSET, PSWD_LEN, ADIACENT_CHECK);
    
}