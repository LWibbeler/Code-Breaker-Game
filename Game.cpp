#include "Game.h"

#include <iostream>
#include <random>
#include <string>
#include <vector>

Game::Game() {
    _message = "Enter a 4 digit number and press enter to start.";
    newGame();
}

void Game::newGame() {
    //Clear the game board
    _secretNumber.clear();
    _secretNumCounts.clear();
    _guesses.clear();
    _hints.clear();
    _guessNum = 0;

    //Add a new row to vectors
    _guesses.push_back(std::vector<int>());
    _hints.push_back(std::vector<int>());

    //generate random 4-digit number
    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_int_distribution<int> code(0, 9);

    for (int i = 0; i < 4; i++) {
        _secretNumber.push_back(code(mt));
    }
    
    _secretNumCounts = countNums(_secretNumber);
}

void Game::keyPress(const int NUM){
    // Check for backspace first
    if (NUM == -1) {
        if (_guesses.at(_guessNum).size() > 0) {
            _guesses.at(_guessNum).pop_back();
        }
    } 
    //If any other integer, add it to the _guesses array
    else {
    if (_guesses.at(_guessNum).size() < 4) {
        _guesses.at(_guessNum).push_back(NUM);
    }
    }
}

void Game::checkNum() {
    //Check if 4 digits have been entered
    if (_guesses.at(_guessNum).size() == 4) {

        //create vectors that define the quantity of each digit in the secret number and the player's guess
        std::vector<int> tempSecretNumCounts = _secretNumCounts, guessNumCounts = countNums(_guesses.at(_guessNum));

        //Add a row to the hints vector and set each value to 0
        _hints.push_back(std::vector<int>());
        for (int i = 0; i < 4; i++) {
            _hints.at(_guessNum).push_back(0);
        }

        // Check for digits in the right place
        for (int i = 0; i < 4; i++){
            if (_secretNumber.at(i) == _guesses.at(_guessNum).at(i)){
                _hints.at(_guessNum).at(i) = 2;
                guessNumCounts.at(_secretNumber.at(i)) --;
                tempSecretNumCounts.at(_secretNumber.at(i)) --;
            }
        }

        // Check for digits in the wrong place
        for (int i = 0; i < 10; i++) {
            while (tempSecretNumCounts.at(i) > 0 && guessNumCounts.at(i) > 0) {
                for (int j = 0; j < 4; j++) {
                    if (i == _guesses.at(_guessNum).at(j) && _hints.at(_guessNum).at(j) == 0) {
                        _hints.at(_guessNum).at(j) = 1;
                        tempSecretNumCounts.at(i)--;
                        guessNumCounts.at(i)--;
                        break;
                    }
                }
            }
        }

        //Check win/loss state
        if ((_hints.at(_guessNum).at(0) == 2) && (_hints.at(_guessNum).at(1) == 2) && (_hints.at(_guessNum).at(2) == 2) && (_hints.at(_guessNum).at(3) == 2)) {
            win();
        } else if (_guessNum >= 7) {
            fail();
        } else {
            _guesses.push_back(std::vector<int>());
            _guessNum++;
        }
    } else {
        _message = "Enter a 4 digit number to continue.";
    }
}

std::vector<int> Game::countNums(const std::vector<int> NUM) const {
    int count;
    std::vector<int> numCounts;
    for (int i = 0; i < 10; i++) {
        count = 0;
        for (int j = 0; j < 4; j++){
            if (i == NUM.at(j)) {
                count++;
            }
        }
        numCounts.push_back(count);
    }
    return numCounts;
}

void Game::win() {
    std::cout << "You won in " << _guessNum + 1 << " guesses!" << std::endl;
    if (_guessNum < 1) {
        _message = "You won! It took you " + std::to_string(_guessNum + 1) + " guess.";
    } else {
        _message = "You won! It took you " + std::to_string(_guessNum + 1) + " guesses.";
    }
    
    newGame();
}

void Game::fail() {
    std::cout << "You lost!" << std::endl;
    _message = "You lost!";
    newGame();
}

int Game::getGuessNum() const {
    return _guessNum;
}

std::string Game::getMessage() const {
    return _message;
}

std::vector<std::vector<int>> Game::getHints() const {
    return _hints;
}

std::vector<std::vector<int>> Game::getGuesses() const {
    return _guesses;
}