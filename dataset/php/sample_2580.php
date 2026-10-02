<?php

function generate_sequence($n) {
    $sequence = [0, 1];
    while (count($sequence) < $n) {
        $next_value = $sequence[count($sequence) - 1] + $sequence[count($sequence) - 2];
        $sequence[] = $next_value;
    }
    return $sequence;
}

function validate_sequence($seq, $target) {
    foreach ($seq as $value) {
        if ($value == $target) {
            return true;
        }
    }
    return false;
}

function main() {
    $n = 10;
    $sequence = generate_sequence($n);
    $target = 5;
    $result = validate_sequence($sequence, $target);
    echo $result;
}

main();

?>