# Welcome to TP C++!

Hi! With **Raphael Vignon** and **Louis LOMBARD**, we make a little c++ program in order to analyse your Appache log. If you are the teacher who will evaluate us, please go to our [Github Project](https://github.com/Rafouf69/AnalyseLogs/tree/main). Let's explain to you how it works

## General

Run the command `$ make` in order to generate the bin/analog executable.
Then you can run `$ bin/analog [YOURAPPACHELOGFILE]` where `[YOURAPPACHELOGFILE]` is the relative path to your log file

## Options

| Option                    | Code exemple                                  | Description                                                                      |
| ------------------------- | --------------------------------------------- | -------------------------------------------------------------------------------- |
|                           | `$ /bin/analog /tmp/versioncourt.log`         | Give you the 10+ most visited website                                            |
| -g [(Optionnal) Filename] | `$ /bin/analog -g /tmp/versioncourt.log`      | Generate a .dot. default ouputname is out.dot                                    |
| -t [HOUR]                 | `$ /bin/analog -t[12] /tmp/versioncourt.log"` | Give you the 10+ most visited URL, filtered by hour between HOUR and HOUR+1      |
| -h                        | `$ /bin/analog h"`                            | Display Help                                                                     |

Of course All options are **permutable** and can be added to each other. Please note that **your code must finish with your appachelog filename**

## Test

Run the command `$ make test` to run all the test. A little feedback will be given.

## Debug Version

Run the command `$ make debug` to generate a debuggable version of the exxecutable

## Clean

Run the command `$ make clean` to clean the folder
