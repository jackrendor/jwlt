#include <string>
#include <iostream>
#include <cstdlib>

class Argparse
{
    private:
        size_t argc_class;
        char **argv_class;
    public:
        /**
         * Init for the class.
         * 
         * @param argv array of arguments passed by the cli
         * @param argc contains the lenght of @param argv
         */
        Argparse(size_t argc, char **argv){
            argc_class = argc;
            argv_class = argv;
        }
        /**
         * Check if argument exist. No value expected;
         * @param arg_long std::string for argument in this format: --name
         * @param arg_short std::string for argument in this format: -n
         */
        bool check_arg(std::string arg_long="", std::string arg_short=""){
            for (size_t i=1; i<argc_class; i++){
                if (std::string(argv_class[i]) == arg_long || std::string(argv_class[i]) == arg_short){
                    return true;
                }
            }
            return false;
        }
        /**
         * Check if argument exist. Value expected;
         * @param arg_long std::string for argument in this format: --name
         * @param arg_short std::string for argument in this format: -n
         */
        const char *get_value(std::string arg_long="", std::string arg_short=""){
            for (size_t i=1; i<argc_class; i++){
                if (std::string(argv_class[i]) == arg_long || std::string(argv_class[i]) == arg_short){
                    i++;
                    if (i > argc_class){
                        return "";
                    }
                    return argv_class[i];
                }
            }
            return "";
        }
};