#!/usr/bin/env bash
# ──────────────────────────────────────────────────────────────────────────
# Tiny regression-test script for ex00 – Scalar Converter (with pass/fail)
#
# • Keep this file next to your executable $BIN
# • Run: ./run_tests.sh
# ──────────────────────────────────────────────────────────────────────────

BIN=./convert

if [[ ! -x $BIN ]]; then
  echo "❌  Expected binary '$BIN' not found or not executable." >&2
  exit 1
fi

# ──────────────────────────────────────────────────────────────────────────
# 1) TEST LITERALS
# ──────────────────────────────────────────────────────────────────────────
TESTS=(
  "A"
  $'\t'
  "0"
  "-42"
  "2147483647"
  "-2147483648"
  "2147483648"
  "128"
  "-129"
  "42.0f"
  "-123.456f"
  "nanf"
  "+inff"
  "-inff"
  "42.0"
  "-123.456"
  "nan"
  "+inf"
  "-inf"
  " "
)

# ──────────────────────────────────────────────────────────────────────────
# 2) EXPECTED OUTPUTS  (four lines each; use $'\n' within each array entry)
# ──────────────────────────────────────────────────────────────────────────
EXPECTED=(
$'char: \'A\'\nint: 65\nfloat: 65.0f\ndouble: 65.0'
$'char: Non displayable\nint: 9\nfloat: 9.0f\ndouble: 9.0'
$'char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0'
$'char: Non displayable\nint: -42\nfloat: -42.0f\ndouble: -42.0'
$'char: impossible\nint: 2147483647\nfloat: 2147483648.0f\ndouble: 2147483647.0'
$'char: impossible\nint: -2147483648\nfloat: -2147483648.0f\ndouble: -2147483648.0'
$'char: impossible\nint: impossible\nfloat: 2147483648.0f\ndouble: 2147483648.0'
$'char: impossible\nint: 128\nfloat: 128.0f\ndouble: 128.0'
$'char: impossible\nint: -129\nfloat: -129.0f\ndouble: -129.0'
$'char: \'*\'\nint: 42\nfloat: 42.0f\ndouble: 42.0'
$'char: Non displayable\nint: -123\nfloat: -123.5f\ndouble: -123.5'
$'char: impossible\nint: impossible\nfloat: nanf\ndouble: nan'
$'char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf'
$'char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf'
$'char: \'*\'\nint: 42\nfloat: 42.0f\ndouble: 42.0'
$'char: Non displayable\nint: -123\nfloat: -123.5f\ndouble: -123.5'
$'char: impossible\nint: impossible\nfloat: nanf\ndouble: nan'
$'char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf'
$'char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf'

$'char: \' \'\nint: 32\nfloat: 32.0f\ndouble: 32.0'
)

# ──────────────────────────────────────────────────────────────────────────
#  Sanity check
# ──────────────────────────────────────────────────────────────────────────
if (( ${#TESTS[@]} != ${#EXPECTED[@]} )); then
  echo "❌  TESTS and EXPECTED array lengths differ: ${#TESTS[@]} vs ${#EXPECTED[@]}" >&2
  exit 2
fi

# ──────────────────────────────────────────────────────────────────────────
#  Test loop with comparison
# ──────────────────────────────────────────────────────────────────────────
echo -e "\n=== ScalarConverter test-run ($(date)) ===\n"
pass_count=0
fail_count=0

for i in "${!TESTS[@]}"; do
  lit="${TESTS[i]}"
  exp="${EXPECTED[i]}"
  # run and capture actual
  actual="$("$BIN" "$lit")"

  printf "▶️  Test %02d – literal: %q\n" "$((i+1))" "$lit"
  echo "----- EXPECTED -----"
  echo -e "$exp"
  echo "----- ACTUAL -------"
  echo -e "$actual"

  if [[ "$actual" == "$exp" ]]; then
    echo "✅ PASS"
    ((pass_count++))
  else
    echo "❌ FAIL"
    echo "----- DIFF ----------"
    diff <(printf "%s\n" "$exp") <(printf "%s\n" "$actual") || true
    ((fail_count++))
  fi
  echo
done

echo "=== Summary: $pass_count passed, $fail_count failed ==="
[[ $fail_count -eq 0 ]] && exit 0 || exit 3
