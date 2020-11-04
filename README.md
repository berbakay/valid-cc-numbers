**About**

An Algoritm which checks whether the user has input a valid credit card number and returns the type of card inputted.


**To Run**<br>

Clone this repo

`git clone https://github.com/berbakay/valid-cc-numbers.git`

Compile code 

`clang -o credit credit.c -lcs50`

run file

`./credit`

enter credit card details - digits only, spaces and dashes will prompt the number to be asked for again.

**Example Output**<br>
Number:4012888888881881 
VISA

or

Number:369421438430814
INVALID
**Requirements**<br>
A dev environment that can compile and run C code.<br>
CS50 Library https://cs50.readthedocs.io/libraries/cs50/c/