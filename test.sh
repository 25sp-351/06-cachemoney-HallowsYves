make || exit 1  

test_inputs=("1234" "4734" "0" "1500" "999")

declare -A expected_outputs=(
    ["1234"]="Twelve dollars and Thirty-Four cents."
    ["4734"]="Forty-Seven dollars and Thirty-Four cents."
    ["0"]="Zero dollars and Zero cents."
    ["1500"]="Fifteen dollars and Zero cents."
    ["999"]="Nine dollars and Ninety-Nine cents."
)

cache_tests=("1234" "999")

: '
declare -A cache_expected_outputs=(
    ["1234"]="Retrieved from cache: 1234 = Twelve dollars and Thirty-Four cents."
    ["999"]="Retrieved from cache: 999 = Nine dollars and Ninety-Nine cents."
)
'

for input in "${test_inputs[@]}"; do
    expected="${expected_outputs[$input]}"

    output=$(echo -e "$input" | ./money_converter 2>/dev/null | tail -n +2)

    if [[ "$output" == *"$expected"* ]]; then
        echo "PASSED | INPUT: $input, $expected"
    else
        echo "FAILED | INPUT: $input"
        echo "   Expected: $expected"
        echo "   Got: $output"
    fi
done