# OriginalDealOrNoDeal
C++ Command-Line Deal or No Deal Game

Description
--------------------------------------------
This C++ program is the Deal or No Deal game. The game begins with the display of the cases and the case amounts. The game
prompts the user to select a case that they will keep for the entirety of the game. The user goes through rounds, up to 9,
guessing cases and hopes to be left with a great amount of money at the end of the game. The user can choose to go up to the
last round of the game, or they can accept the offer the bank gave them. At the end of the game, the user is prompted if they
want to play again or exit the game. If they choose to play again, the game resets and allows people to play again. Input is checked,
and if an invalid choice is inputted, like opening an already open case or choosing outside of the index of the array, the user is
prompted to input a valid choice.
 
Instructions
--------------------------------------------
Using a Command Line Interface, compile the file by typing g++ -o assg5 assg5.cpp. To run the executable, type ./assg5 .
You could also compile the file as g++ assg5.cpp and run the executable as ./a.out .  

Disclaimer:

If any other data type besides int is entered, the program will print a message prompting them to enter a valid input. 
However, this causes a infinite loop, and "cin" isn't reached and cannot be used again.  

If case 13 is selected, the two rows of the cases being displayed merges into one. The game still functions as normal.


Author:
--------------------------------------------
-Saide Johnson
 Fall2019
