#include <iostream>
#include <cmath>

size_t strlen(char* s){
    size_t r;
    if (s == NULL)
        return 0;
    for (r = 0; *s++ != '\0'; r++);
    return r;
}

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

void print_tracker(size_t *tracker, const char *charset, size_t psw_len, bool adiacent_check){
    std::string result;
    for (size_t i=0; i<psw_len; i++){
        if (adiacent_check && i<psw_len-1 && tracker[i] == tracker[i+1])
            return;
        result += charset[tracker[i]];
    }
    std::cout << result << std::endl;
}

void wordlist_generator(size_t *tracker, const char *CHARSET, size_t PSWD_LEN, size_t C_LEN, bool ADIACENT_CHECK){
    size_t combinations = pow(C_LEN, PSWD_LEN);
    print_tracker(tracker, CHARSET, PSWD_LEN, ADIACENT_CHECK);
    for (size_t i=0; i<combinations; i++, increase(tracker, PSWD_LEN, C_LEN))
        print_tracker(tracker, CHARSET, PSWD_LEN, ADIACENT_CHECK);
    
}