#!/bin/bash

# --- Announce the test ---
echo "--- Running Comprehensive Test Suite ---"
echo "The program will be run with 'test_input.txt'."
echo "Below is a breakdown of each test case and its expected result."
echo

# --- Explain Expected Results ---
echo "--- Expected Results Breakdown ---"
echo "1.  2011-01-03 | 3          -> Should succeed. Exact date match."
echo "2.  2011-01-03 | 2.5        -> Should succeed. Float value."
echo "3.  2011-01-05 | 1          -> Should succeed. Fallback to nearest lower date."
echo "4.  2008-12-31 | 10         -> Should fail with 'Error: bad input => ...' (due to year < 2009)."
echo "5.  2012-01-11 | 1000       -> Should succeed. Max valid value."
echo "6.  2012-01-11 | 1001       -> Should fail with 'Error: too large a number.'"
echo "7.  2012-01-11 | -5         -> Should fail with 'Error: not a positive number.'"
echo "8.  2012-01-11 | 0          -> Should succeed. Zero is a valid value."
echo "9.  2013-05-20|500          -> Should succeed"
echo "10. 2013-13-01 | 10         -> Should fail with 'Error: bad input => ...' (invalid month)."
echo "11. 2013-05-32 | 10         -> Should fail with 'Error: bad input => ...' (invalid day)."
echo "12. 2014-07-01 | notanumber -> Should fail with 'Error: bad input => ...' (invalid value)."
echo "13. 2014-07-01 |            -> Should fail with 'Error: bad input => ...' (empty value)."
echo "14. 2014-07-01 | 5 | extra  -> Should fail with 'Error: bad input => ...' (prints value part only)."
echo

# --- Run the program and show actual output ---
echo "--- Actual Program Output ---"
./btc test_input.txt
echo
echo "--- Testing Complete ---"
echo "Please compare the 'Actual' output above with the 'Expected'"