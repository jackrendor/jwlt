#include <iostream>
#include "argparse.h"
#include "jwlt_func.h"

std::string USAGE = " jwlt --help / -h\t\tDisplay this help message\n"
                    " jwlt --charset / -c\t\tCharacters to use (e.g. 0123456789)\n"
                    " jwlt --lenght / -l\t\tLenght of the password to generate\n"
                    " jwlt --adiacent-check / -a\tExclude password with same adiacent chars\n";

int main(int argc, char **argv){
    Argparse args(argc, argv);
    
    if (args.check_arg("--help", "-h")){
        std::cerr << USAGE;
        return -1;
    }
    if (argc < 4){
        std::cerr << " [!] Missing argument.\n [i] Usage: \n";
        std::cerr << USAGE;
        return -1;
    }
    size_t C_LEN;
    const char *CHARSET = args.get_value("--charset", "-c");
    if (CHARSET == NULL || (C_LEN = strlen((char*)CHARSET)) == 0){
        std::cerr << "Missing argument value for --charset/-c\n";
        return -1;
    }
    

    size_t PSWD_LEN = atoi(args.get_value("--lenght", "-l"));
    if (PSWD_LEN <=0){
        std::cerr << "Missing argument value for --lenght/-l\n";
        return -1;
    }
    
    bool ADIACENT_CHECK = args.check_arg("--adiacent-check", "-a");

    size_t tracker[PSWD_LEN];
    for (size_t i=0; i<PSWD_LEN; i++){
        tracker[i] = 0;
    }

    std::cerr << "Charset: " << CHARSET << std::endl;
    std::cerr << "Charset lenght: " << C_LEN << std::endl;
    std::cerr << "Password lenght: " << PSWD_LEN << std::endl;
    std::cerr << "Adiacent check: " << (ADIACENT_CHECK ? "yes" : "no") << std::endl;
    
    wordlist_generator(tracker, CHARSET, PSWD_LEN, C_LEN, ADIACENT_CHECK);

}