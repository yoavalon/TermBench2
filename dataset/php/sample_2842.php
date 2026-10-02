<?php

function generate_sequence($state, $sequence) {
    if ($state == 0) {
        $next_state = 1;
        $next_value = end($sequence) + 1;
    } elseif ($state == 1) {
        $next_state = 2;
        $next_value = end($sequence) * 2;
    } elseif ($state == 2) {
        $next_state = 0;
        $next_value = end($sequence) - 1;
    }
    return array($next_state, $next_value);
}

function main() {
    $state = 0;
    $sequence = array(1);
    while (true) {
        list($state, $value) = generate_sequence($state, $sequence);
        $sequence[] = $value;
    }
}

main();