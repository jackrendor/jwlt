# Jack WordList Tracker

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/93b6e5a68b6041329d309f24bf705371)](https://app.codacy.com/app/jackrendor/jwlt?utm_source=github.com&utm_medium=referral&utm_content=jackrendor/jwlt&utm_campaign=Badge_Grade_Settings)

jwlt (Jack WordList Tracker) is a wordlist generator inspirited by [crunch](https://sourceforge.net/projects/crunch-wordlist/).
~~jwlt allows you to save your current session while you are generating your wordlist. If your pc turns off or anything else bad happens, jwlt will keep track of the last elements.~~ **lmao sorry guys, not now. I'll reimplement this later**

## Compile
Just run the `compile.sh` script.
```sh
bash compile.sh
```

## Install
Run the `install.sh` script.
```sh
sudo bash compile.sh
```

or

```sh
su -c "bash compile.sh"
```

## Usage

**jwlt** requires two values:
- `--charset` or `-c` followed by a space and the charset. Examples are: `abcdefghijklmnopqrstuvwxyz`, `ABCDEFGHIJKLMNOPQRSTUVWXYZ`, `abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`, `012346789`, `0123456789ABCDEF` and so on. You decide your own charset based on the known rule.
- `--lenght` or `-l` followed by a space and the lenght of the password that you want to generate. For example, WPA WiFi passwords won't take any password shorter than 8 chars

There are optional arguments:
- `--adiacent-check` or `-a`, no value to specify. Passing this argument won't print words that contains the same char next to eachothers.
- `--help` or `-h`, no value to specify. Prints a quick and minimal usage.

 