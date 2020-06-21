# Jack WordList Tracker

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/93b6e5a68b6041329d309f24bf705371)](https://app.codacy.com/app/jackrendor/jwlt?utm_source=github.com&utm_medium=referral&utm_content=jackrendor/jwlt&utm_campaign=Badge_Grade_Settings)

jwlt (Jack WordList Tracker) is a wordlist generator inspirited by [crunch](https://sourceforge.net/projects/crunch-wordlist/).
~~jwlt allows you to save your current session while you are generating your wordlist. If your pc turns off or anything else bad happens, jwlt will keep track of the last elements.~~ **lmao sorry guys, not now. I'll implement this later**

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

`jwlt --charset/-c <charset string> --lenght/-l <password lenght> <save interval> `

 1. `<charset string>` is a string that contains a char-set like `0123456789` or `abcdefghijklmnopqrstuvwzxy`. For e.g.: if you want to generate a password that contains only letters from **A** to **F** and numbers from **0** to **9**, the charset you have to use is: `ACBDEF0123456789`
 2. `<wordlist lenght>` is the length of every generated word. For e.g.: if the password to generate contains 5 chars, the arugment you have to use is: `5`
 3. `<save interval>` is the interval between each save. For e.g.: if you want to save the session every 50000 generated word, then you have to type `50000` as argument.

## Contacts
In case you want to contribute to this project or you have something to ask, feel free to PM me:

 - [Telegram](https://t.me/a_lombax)
 - [Twitter](https://twitter.com/jackrendor)
 - [GitLab](https://gitlab.com/jackrendor)

 ## Thank to
  - [SamBelieve](https://github.com/samtolomeo) for helping with the translation.
