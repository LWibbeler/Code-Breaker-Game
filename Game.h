#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

class Game {
    public:
        /**
         * @brief Construct a new Game object
         * 
         */
        Game();

        /**
         * @brief resets the game board and generated a new random number.
         * 
         */
        void newGame();

        /**
         * @brief handles key presses
         * 
         */
        void keyPress(const int);

        /**
         * @brief checks if each digit is in the right place, wrong place, or not in the secret number at all
         * 
         */
        void checkNum();

        /**
         * @brief Get the _GuessNum object
         * 
         * @return int _GuessNum
         */
        int getGuessNum() const;

        /**
         * @brief Get the _message object
         * 
         * @return std::string _message 
         */
        std::string getMessage() const;

        /**
         * @brief Get the _hints object
         * 
         * @return std::vector<std::vector<int>> _hints 
         */
        std::vector<std::vector<int>> getHints() const;

        /**
         * @brief Get the _guesses object
         * 
         * @return std::vector<std::vector<int>> _guesses 
         */
        std::vector<std::vector<int>> getGuesses() const;

    private:
        /**
         * @brief stores the string that is shown at the top of the screen
         * 
         */
        std::string _message;

        /**
         * @brief stores the number of guesses the player has made
         * 
         */
        short _guessNum;

        /**
         * @brief stores each int of the secret number in a vector
         * 
         */
        std::vector<int> _secretNumber;

        /**
         * @brief stores the quantity of each digit in the secret number
         * 
         */
        std::vector<int> _secretNumCounts;

        /**
         * @brief stores the values of the user's guesses in a 2d list
         * 
         */
        std::vector<std::vector<int>> _guesses;

        /**
         * @brief a 2d list that stores 0 if a integer is not in the random number, 1 if it is but in the wrong place, or 2 if it it is in the right place.
         * 
         */
        std::vector<std::vector<int>> _hints;

        /**
         * @brief counts the quantity of each digit in a given code
         * 
         * 
         * @return std::vector<int> code to be counted
         */
        std::vector<int> countNums(const std::vector<int>) const;
        
        /**
         * @brief displays a winning message and calls newGame
         * 
         */
        void win();

        /**
         * @brief displays a loosing message and calls newGame
         * 
         */
        void fail();
};

#endif