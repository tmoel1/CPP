#!/bin/bash

# --- Announce the test suite ---
echo "--- Running RPN Test Suite ---"
echo

# --- VALID EXPRESSIONS (Should Succeed) ---
echo "--- Testing Valid Expressions ---"

echo "Test: Subject example 1"
echo "CMD: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\""
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo "-------------------------------------"

echo "Test: Subject example 2"
echo "CMD: ./RPN \"7 7 * 7 -\""
./RPN "7 7 * 7 -"
echo "-------------------------------------"

echo "Test: Subject example 3"
echo "CMD: ./RPN \"1 2 * 2 / 2 * 2 4 - +\""
./RPN "1 2 * 2 / 2 * 2 4 - +"
echo "-------------------------------------"

echo "Test: Standard RPN example"
echo "CMD: ./RPN \"5 1 2 + 4 * + 3 -\""
./RPN "5 1 2 + 4 * + 3 -"
echo "-------------------------------------"

echo "Test: Simple integer division"
echo "CMD: ./RPN \"9 2 /\""
./RPN "9 2 /"
echo "-------------------------------------"

echo "Test: Multiple sub-expressions"
echo "CMD: ./RPN \"2 3 * 4 5 * +\""
./RPN "2 3 * 4 5 * +"
echo "-------------------------------------"

echo "Test: A single number"
echo "CMD: ./RPN \"9\""
./RPN "9"
echo "-------------------------------------"
echo

# --- INVALID EXPRESSIONS (Should print "Error") ---
echo "--- Testing Invalid Expressions (All should print 'Error') ---"

echo "Test: Invalid token \"(\""
echo "CMD: ./RPN \"(1 + 1)\""
./RPN "(1 + 1)"
echo "-------------------------------------"

echo "Test: Too many operands left"
echo "CMD: ./RPN \"1 2 3 *\""
./RPN "1 2 3 *"
echo "-------------------------------------"

echo "Test: Not enough operands for \"+\""
echo "CMD: ./RPN \"1 +\""
./RPN "1 +"
echo "-------------------------------------"

echo "Test: Not enough operands for \"*\""
echo "CMD: ./RPN \"*\""
./RPN "*"
echo "-------------------------------------"

echo "Test: Division by zero"
echo "CMD: ./RPN \"5 0 /\""
./RPN "5 0 /"
echo "-------------------------------------"

echo "Test: Not enough operands for second op"
echo "CMD: ./RPN \"1 2 + -\""
./RPN "1 2 + -"
echo "-------------------------------------"

echo "Test: Invalid token \".\""
echo "CMD: ./RPN \"1 . 5 +\""
./RPN "1 . 5 +"
echo "-------------------------------------"

echo "Test: Invalid token \"10\""
echo "CMD: ./RPN \"10 2 +\""
./RPN "10 2 +"
echo "-------------------------------------"

echo "Test: Invalid token \"a\""
echo "CMD: ./RPN \"1 a +\""
./RPN "1 a +"
echo "-------------------------------------"

echo "Test: Empty expression"
echo "CMD: ./RPN \"\""
./RPN ""
echo "-------------------------------------"

echo "Test: Expression with only numbers"
echo "CMD: ./RPN \"1 2 3 4\""
./RPN "1 2 3 4"
echo "-------------------------------------"

echo "--- Testing Complete ---"