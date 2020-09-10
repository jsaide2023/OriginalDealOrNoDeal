// Saide Johnson
// CS1428 Honors Fall 2019

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

const int ARRAY_SIZE = 26; // global constant set for the array size

struct dealCases{
    int caseNumber;
    float caseValue;
    bool isOpen;
    bool isCasePick;
};

// Functions declared at the top, as they come before other functions
void displayAmounts(dealCases valueCases[]);
void delayTime();

/* Function takes in the struct array and the constant array. The function
 * goes through the struct array and initalized the member case value with 
 * an initial random number from the constant array. Another loop assigns
 * a variable with a random value from the constant array and checks to
 * see if value has been already assign. If it has, the check is false
 * and reassigns value until no values are repeating. If it doesn't repeat,
 * value is assigned to struct array. Returns void */

void randomizeCases(dealCases randomCase[], const float caseWorth[]){
    int i, j =  0;
    float n = 0;
    bool check;
   
    for (i = 0; i < ARRAY_SIZE; i++){
	//assigns values to the array
	randomCase[i].caseValue = caseWorth[rand() % 26];
    }
    for (i = 0; i < ARRAY_SIZE; i++){
	do{
	    n = caseWorth[rand() % ARRAY_SIZE]; //assigns value to the variable
	    check = true;
	    for (j = 0; (j < i); j++){
		//searches through the array to see if it was repeated
		if (n == randomCase[j].caseValue){
		    check = false;
		    break;
		}
	    }
	}while(!check);
	randomCase[i].caseValue = n; //if check is valid, assigns value to the array
    }
    return;
}

/* Function takes in the struct array. Within the function, the constant
 * array of set case values is declared. Function goes through a for-loop
 * and initialize each member of the struct within that element to certain
 * conditions. Afterwards, the function calls randomizeCases. Returns void */
  
void initializeCases(dealCases initializeCase[]){
    int i;

    srand(time(0));
    const float caseWorth[] = {0.01, 1, 5, 10, 25, 50, 75, 100, 200,
			   300, 400, 500, 750, 1000, 5000, 10000,
			   25000, 50000, 75000, 100000, 200000,
			   300000, 400000, 500000, 750000,
			   1000000};

    for (i = 0; i < ARRAY_SIZE; i++){
	initializeCase[i].caseNumber = i+1;
	initializeCase[i].isOpen = false;
	initializeCase[i].isCasePick = false;
    }
    randomizeCases(initializeCase, caseWorth);
    return;
    
}

/* Function takes in the struct array, select element, and if the parameter isn't
 * passed, the bool value is passed as false.
 * The function has a static counter to ensure that the first time an element is passed,
 * it is set at the case pick. If the counter is greater than zero and the bool value
 * isn't passed, the select element in the struct array is set true, for the isOpen \
 * member. Returns void. */

void updateCases(dealCases updateCases[], int selectElement, bool isStartOver = false){
    static int counter = 0;
    if (isStartOver)
	counter = 0; //if the game starts over, counter is set back to 0
    updateCases[ARRAY_SIZE];
    selectElement--;
    if (counter == 0){
        updateCases[selectElement].isCasePick = true;
        counter++;
	return;
    }
    else if (updateCases[selectElement].isOpen != true){
	updateCases[selectElement].isOpen = true;
	return;
    }
    return;
}

/* Function takes in the struct array. Function searches within the struct
 * array to find the "case pick" and prints out that case separately. The
 * function also later prints out unopened cases. It also calls the function
 * that displays the amounts of the cases remaining. Return void. */

void displayCases(dealCases showCases[]){
    for (int i = 0; i < ARRAY_SIZE; i++){
	if (showCases[i].isCasePick == true){
	    cout << endl;
            cout << "This Is Your Case:    [ " << showCases[i].caseNumber << " ]" << endl;
	    break;
        }
    }
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
    for (int j = 0; j < ARRAY_SIZE; j++){
	if (showCases[j].isOpen == false && showCases[j].isCasePick == false){
	    cout << "   [" << showCases[j].caseNumber << "]";
	    if (j == 12)
		    cout << endl;
	}
    }
    cout << endl << endl;
    displayAmounts(showCases);

    cout << endl;
    return;
}

/* Function takes in the struct array and declares a constant array
 * of the values set for the game. Function compares the constant array
 * to the struct array. If the cases aren't open, have the same value
 * as the constant array of a certain element and hasn't been printing
 * more than once, the case's amount will be printed. Returns void */

void displayAmounts(dealCases valueCases[]){
    valueCases[ARRAY_SIZE];
    //declared as a constant so that it won't be modify by anything
    const float caseWorth[ARRAY_SIZE] = {0.01, 1, 5, 10, 25, 50, 75, 100, 200,
			                 300, 400, 500, 750, 1000, 5000, 10000,
			                 25000, 50000, 75000, 100000, 200000,
			                 300000, 400000, 500000, 750000,
			                 1000000};

    float n; 
    int counter = 0;
    cout << "+++++Case Amounts+++++" << endl << endl;
    for (int i = 0; i < ARRAY_SIZE; i++){
        n = caseWorth[i]; //saves the element of the array into n
	counter = 0; //resets for every value of i
	for (int j = 0; j < ARRAY_SIZE; j++){
	    //checks to see if the case is open, has the same value of n, and counts to see how many times
	    //it has been printing
	    if (((valueCases[j].isOpen == false) && (valueCases[j].caseValue == n)) && (counter == 0)){
		    cout << setfill(' ') << setw(4) << fixed << setprecision(2) << "$" << caseWorth[i];
		    cout << endl;
		    counter++; //increments so that it doesn't print more than once
		    break;
	    }
	}

    }

    return;
}

/* Function takes in the struct array and the selected case. 
 * Function decrements the selected case by one to fit the index
 * of the arrray. Function returns false if the selected case is
 * out of range or if the selected case in that array is already
 * open of is the case they picked at the beginning of the game.
 * function returns true if they don't apply to other cases */

bool isValidInput(dealCases validCase[], int selectedCase){
   selectedCase--;
   if (selectedCase <= -1 || selectedCase >= 26)
	return false;
   else if ((validCase[selectedCase].isOpen == true) || (validCase[selectedCase].isCasePick == true))
	return false;
   return true;
}


float calculateBankOffer(dealCases valueCases[]){
    valueCases[ARRAY_SIZE];
    float sum = 0;
    float divisor = 0;
    for (int i = 0; i < ARRAY_SIZE; i++){
	//goes through array and finds the cases that aren't open
	if (valueCases[i].isOpen == false){
	    //adds the closed cases' values to each other
	    sum = sum + valueCases[i].caseValue;
	    //counts how many cases are not open
	    divisor++;
	}
    }
    //calculates the average of the closed cases
    return (sum/divisor);
}

/* Function takes in the struct array and sends it to the calucateBankOffer
 * function. 
 * The function prints the prompt for the offer and takes in user choice, which
 * determines if the function returns true or false. Function returns true if
 * user accepts the offer and false if the user doesn't. */

bool acceptsBankOffer(dealCases caseValues[]){
    char userChoice;
    float moneyWon = 0;

    cout << "   Calculating....." << endl;
    delayTime();
    cout << endl;
    cout << "The Bank Offers You: $" << fixed << setprecision(2) <<  calculateBankOffer(caseValues) << endl << endl;
    cout << "+++++++ Deal Or No Deal? +++++++" << endl;
    cout << "Press D for Deal or Press Any Key For No Deal: "; 
    cin >> userChoice;
    userChoice = toupper(userChoice);
    if (userChoice == 'D'){
	moneyWon = calculateBankOffer(caseValues);
	cout << "You Won: $" << fixed << setprecision(2) << moneyWon << endl << endl;
	return true;
	}
    return false;

}

/* Function takes in the struct array and takes in bool value. The bool
 * value is set to default. 
 * The function goes through each round. With,
 * each round, valid input updates the array.  The static variable 
 * starts with six and decrements with each round after,
 * until rounds 6 - 9. The static variable resets when isStartOver
 * is true. Returns void */

void gameRounds(dealCases dealBoxes[], bool isStartOver = false){
    dealBoxes[ARRAY_SIZE];
    bool isChoiceMade = false;
    int selectCase;
    bool isRoundComplete  = false;
    static int roundsRemaining = 6; //the amount cases for a round
    if (isStartOver == true){
	roundsRemaining = 6; //resets the cases each game
    }
	for (int i = 0; i < roundsRemaining; i++){
	    isChoiceMade = false;
	    while (!isChoiceMade){
		if (roundsRemaining > 1)
		    cout << "    Select " << roundsRemaining << " Cases (" << i << "/" << roundsRemaining << "): ";
		if (roundsRemaining == 1)
		    cout << "    Select " << roundsRemaining << " Case (" << i << "/" << roundsRemaining << "): ";
		cin >> selectCase;
		cout << endl;
		//checks for valid input and if it is valid, cases are updated
	        if (isValidInput(dealBoxes, selectCase)){
		    updateCases(dealBoxes, selectCase);
		    isChoiceMade = true;
	    	}
		else{
		    //invalid inputs forces user to input again    
		    cout << "    Invalid Input! Try Again" << endl;
		    isChoiceMade = false;
		}
	    }
	    //displays a case every time a valid choice is made
	    displayCases(dealBoxes);
	}
    //exits out function for rounds 6-9, so it doesn't decrement
    if (roundsRemaining == 1)
	return;
    else
    //decrements for rounds 1 - 5, so that it coincides with the respective rounds
	roundsRemaining--;
    return;
}

/*Function delays time for dramatic effect. function doesn't take in
 * any parameters and returns void */		
void delayTime(){
   for (unsigned int i = 0; i < time(0) + 1; i++){
   }
return;
}
 	
    

int main(){
    dealCases moneyCases[ARRAY_SIZE];
    int selectCase;
    float moneyWon = 0;
    char userChoice;
    bool isContinue = false;
    bool isGameOver = false;
    bool isValid = false;
    bool isAnotherGame = false;


    cout << "++++Welcome to Deal or No Deal++++" << endl;
    while (!isGameOver){
	//initiates the game
        initializeCases(moneyCases);
        displayCases(moneyCases);
	while (!isValid){
            cout << "Pick One Case: ";
            cin >> selectCase;
	    if (isValidInput(moneyCases, selectCase)){
		//bool value is sent to check to see if the game has reset
            	updateCases(moneyCases, selectCase, isAnotherGame);
        	displayCases(moneyCases);
		isValid = true;
		break;
	    }
	    else
		cout << "Incorrect Input! Try Again" << endl;
	}
 
	do{
       	    cout << "++++This Is The First Round++++" << endl;
	    //bool value is sent to check to see if the game has reset
	    gameRounds(moneyCases, isAnotherGame);
	    //game ends if bank offer is accepted, which returns true
	    if(acceptsBankOffer(moneyCases)){
	        isGameOver = true;
		isContinue = false; //doesn't continue to the next rounds
		break;
	    }
	    cout << "++++This Is The Second Round++++" << endl;
	    gameRounds(moneyCases);
	    if(acceptsBankOffer(moneyCases)){
	        isGameOver = true;
		isContinue = false;
		break;
	    }
	    cout << "++++This Is The Third Round++++" << endl;
	    gameRounds(moneyCases);
	    if(acceptsBankOffer(moneyCases)){
	        isGameOver = true;
		isContinue = false;
		break;
	    }

	    cout << "++++This Is The Fourth Round++++" << endl;
	    gameRounds(moneyCases);
	    if(acceptsBankOffer(moneyCases)){
	        isGameOver = true;
		isContinue = false;
		break;
	    }
	    cout << "++++This Is The Fifth Round++++" << endl;
	    gameRounds(moneyCases);
	    if(acceptsBankOffer(moneyCases)){
	        isGameOver = true;
		isContinue = false;
		break;
	    }
	    cout << "++++This Is The Sixth Round++++" << endl;
	    gameRounds(moneyCases);
	    if(acceptsBankOffer(moneyCases)){
	        isGameOver = true;
		isContinue = false;
		break;
	    }
	    cout << "++++This Is The Seventh Round++++" << endl;
	    gameRounds(moneyCases);
	    if(acceptsBankOffer(moneyCases)){
	         isGameOver = true;
		 isContinue = false;
		 break;
	    }
	    cout << "++++This Is The Eighth Round++++" << endl;
	    gameRounds(moneyCases);
	    if(acceptsBankOffer(moneyCases)){
	        isGameOver = true;
		isContinue = false;
		break;
	    }
	    cout << "++++This Is The Ninth Round++++" << endl;
	    gameRounds(moneyCases);
	    if(acceptsBankOffer(moneyCases)){
	        isGameOver = true;
		isContinue = false;
		break;
	    }
	    cout << "++++This Is The Last Round++++" << endl;
	    isValid = false;
	    isContinue = true;
	    while (!isValid){
		displayCases(moneyCases);
	        cout << "Would Like to Keep and Open Your Case or Would You Like To Swap?" << endl;
	        cout << "Press K to Keep and Press S to Swap" << endl;
	        cin >> userChoice;
		userChoice = toupper(userChoice);
		if (userChoice == 'K'){
		    //decrements the selectCase to correspond with the right index of the array
		    moneyCases[selectCase - 1].isCasePick = true;
		    moneyWon = moneyCases[selectCase - 1].caseValue; //sets the case value of that case pick to money won
		    cout << "You Won: $" << fixed << setprecision(2) << moneyWon << endl;
		    isGameOver = true;
		    isValid = true;
		    break;
		}

		if (userChoice == 'S'){
		    for (int i = 0; i < ARRAY_SIZE; i++){
			if (moneyCases[i].isCasePick){
			        moneyCases[i].isCasePick = false; //sets case pick for originial case pick to false
				if (moneyCases[i].isOpen == false){
			    	    moneyCases[i].isCasePick = true; //sets the swapped case "case pick" to true
			            moneyWon = moneyCases[i].caseValue; //sets the case value of that case pick to money won
			    	    cout << "You Won: $" << fixed << setprecision(2) <<  moneyWon << endl;
			            isGameOver = true;
			            isValid = true;
				}
			}
		    }
	    	}
		else{
		    //if input is invalid, it will prompt the user to try again
		    cout << "Invalid Input! Try again!" << endl;
		    isValid = false;
		}
		
	    }		        
	  					
        }while(!isContinue);

    cout << "Do You Want To Play Again?" << endl;
    cout << "Press Q to Quit or Press Any Key to Continue: ";
    cin >> userChoice;
    userChoice = toupper(userChoice);
    if (userChoice == 'Q'){
	isGameOver = true;
	cout << "++++Thank You For Playing. Goodbye.++++" << endl;
    }
    else{
	//resets the game
	isGameOver = false;
	isValid = false;
	isAnotherGame = true;
	for (int i = 0; i < ARRAY_SIZE; i++){
	    //resets the case pick
	    moneyCases[i].isCasePick = false;
	}
	
    }
}
	
return 0;
}
    	
