#include <iostream>

// Global game variables
double Mines = 0;                   // Current number of dug mines
double MiningMultiplier = 1.0;     // Multiplier that affects mining gains
double TotalEarnings = 0;         // Total mines dug during the game
double MineralsExtracted = 0;    // Total minerals converted from mines
double Gained;                  // Temporary variable to store gained mines per dig
double Convert;                // Amount of mines to convert

int Vote; // Menu selection-vote

// Function to display current game statistics
void StatisticsMenu(){
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Mines: " << Mines << std::endl;                    // Show current mines
    std::cout << "Minerals: " << MineralsExtracted << std::endl;       // Show total minerals
    std::cout << "Mining Multiplier: " << MiningMultiplier << std::endl;  // Show current multiplier
    std::cout << "Total Excavated Mines: " << TotalEarnings << std::endl;  // Show total earned mines
    std::cout << "---------------------------------" << std::endl << std::endl;
}

// Function to display the main menu
void MainMenu(){
    std::cout << "[1] - Dig Mine" << std::endl;                       // Option to dig mines
    std::cout << "[2] - Convert Mines Into Minerals" << std::endl;   // Option to convert mines
    std::cout << "[3] - Exit" << std::endl;                         // Option to exit the game
}

// Function to get the player's menu choice
void VoteFunction(){
    std::cout << "Vote:";    // Prompt user for input
    std::cin >> Vote;       // Read user choice
}

int main(){
     while(true){  // Main game loop
        StatisticsMenu();   // Display current statistics
        MainMenu();         // Display menu options
        VoteFunction();     // Get player input

        switch(Vote){       // Handle player choice
         case 1: // Dig mines
            Gained = 10 * MiningMultiplier;   // Calculate mines gained based on multiplier
            Mines += Gained;                 // Add gained mines to total
            TotalEarnings += Gained;        // Update total earned mines

            std::cout << "You dug " << Gained << " mines!" << std::endl;
            break;


         case 2: // Convert mines into minerals
            std::cout << "Enter the amount to convert: ";
            std::cin >> Convert;  // Get amount to convert

            if(Convert <= Mines && Convert > 0){  // Check for valid conversion
                Mines -= Convert;                // Subtract converted mines
                MineralsExtracted += Convert;   // Add to total minerals

                MiningMultiplier += Convert * 0.005; // Increase multiplier based on converted mines

                std::cout << "Converted " << Convert << " Mines!" << std::endl;
                break;
            }
            else{  // Invalid conversion
                std::cout << "Insufficient mines.." << std::endl;
                break;
            }
            break;


         case 3: // Exit
            return 0;  // Exit main loop and end program


         default: // Invalid menu choice
            std::cout << "Invalid Selection.." << std::endl;
            break;
         }
     }

  return 0;
}
