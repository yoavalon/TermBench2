<?php
function generate_sequence($n) {
    $a = 0;
    $b = 1;
    $sequence = [];
    for ($i = 0; $i < $n; $i++) {
        array_push($sequence, $a);
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
    return $sequence;
}

function simulate_states($seq) {
    $states = [];
    foreach ($seq as $value) {
        $state = $value * 2 + 1;
        array_push($states, $state);
    }
    return $states;
}

function main() {
    while (true) {
        $n = 10;
        $sequence = generate_sequence($n);
        $states = simulate_states($sequence);
        print_r($states);
    }
}

main();
?>