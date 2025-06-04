#!/usr/bin/env bash

prog=./sed_is_for_losers

##############################################################################
# 1. Basic replace must work and leak-free                                   #
##############################################################################
echo "⏳  Test 1: simple replacement and Valgrind leak check"
echo "ℹ️ Expected: t1.txt.replace contains 'XXX def XXX'"
echo "abc def abc" > t1.txt
valgrind "$prog" t1.txt abc XXX #>/dev/null
echo -n "➡️ Actual: "
cat t1.txt.replace
grep -q "^XXX def XXX$" t1.txt.replace && echo "✅  Test 1 passed" || \
  { echo "❌  Test 1 failed" ; exit 1 ; }
rm t1.txt t1.txt.replace

##############################################################################
# 2. Non-existent file must return error code 1                              #
##############################################################################
echo "⏳  Test 2: non-existent input file"
echo "ℹ️ Expected: program exits with a non-zero code"
"$prog" no_such_file.txt a b #>/dev/null 2>&1
code=$?
echo "➡️ Actual exit code: $code"
if [ "$code" -ne 0 ]; then
  echo "✅  Test 2 passed"
else
  echo "❌  Test 2 failed (program returned 0)" ; exit 1
fi

##############################################################################
# 3. Permission denied (directory not writable) → error code 1              #
##############################################################################
echo "⏳  Test 3: permissions error"
echo "ℹ️ Expected: program exits with a non-zero code"
mkdir ro_dir
echo "data" > ro_dir/file.txt
chmod 555 ro_dir
"$prog" ro_dir/file.txt a b #>/dev/null 2>&1
code=$?
echo "➡️ Actual exit code: $code"
if [ "$code" -ne 0 ]; then
  echo "✅  Test 3 passed"
else
  echo "❌  Test 3 failed (program returned 0)" ; chmod 755 ro_dir && rm -r ro_dir ; exit 1
fi
chmod 755 ro_dir && rm -r ro_dir

##############################################################################
# 4. Empty file should be handled gracefully (still exit 0)                  #
##############################################################################
echo "⏳  Test 4: empty input file"
echo "ℹ️ Expected: empty.txt.replace is empty (identical to empty.txt)"
: > empty.txt
valgrind "$prog" empty.txt foo bar #>/dev/null
echo -n "➡️ Actual: '"; cat empty.txt.replace; echo "'"
cmp --silent empty.txt empty.txt.replace && echo "✅  Test 4 passed" || \
  { echo "❌  Test 4 failed" ; exit 1 ; }
rm empty.txt empty.txt.replace

echo -e "\n🎉  All tests passed"
