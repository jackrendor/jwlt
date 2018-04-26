# Jack WordList Tracker
jwlt (Jack WordList Tracker) is a wordlist generator inspirited by [crunch](https://sourceforge.net/projects/crunch-wordlist/).
jwlt allows you to save your current session while you are generating your wordlist. Even if your pc gets shut down, your process closes or anything else bad happens that may interrupt the process, you wont lose your progress.

## Compiling
To compile the program, you need to execute the `compile.sh` script by running:

    sh compile.sh

## Installing
To install the program, you need to execute the `install.sh` script as **root**.

    sudo sh install.sh
or

    su -c "sh install.sh"


## Usage

Two arguments are necessary to run the generator, the third is optional.

`jwlt <charset string> <wordlist lenght> <save interval> `

 1. `<charset string>` is a string that contains a char-set like `0123456789` or `abcdefghijklmnopqrstuvwzxy`. For e.g.: if you know that the password contains only letters from **A** to **F** and numbers, the charset you have to use might be: `ACBDEF0123456789`
 2. `<wordlist lenght>` is the length of every generated word. For e.g.: if the password to bruteforce is 5 length long, the arugment should be `5`
 3. `<save interval>` is the interval of words of one saved session from another. For e.g.: if you want to save the session every 50000 generated word, then you have to type `50000` as argument.

You can supply even a "special option" to delete the last session:

    jwlt --delete-session
or even shorter:

    jwlt -ds

## Contacts
In case you want to contribute to this project or you have something to ask, feel free to PM me:

 - [Telegram](https://t.me/jm266)
 - [Twitter](https://twitter.com/jackrendor)
 - [GitLab](https://gitlab.com/jackrendor)

 ## Thank to
  - [SamBelieve](https://github.com/sambelieve) with the translation
