<?php
function state_transition($state, $sequence) {
    if ($state == 0 && $sequence == 1) {
        return 1;
    } elseif ($state == 1 && $sequence == 0) {
        return 2;
    } elseif ($state == 2 && $sequence == 1) {
        return 3;
    } elseif ($state == 3 && $sequence == 0) {
        return 0;
    } else {
        return -1;
    }
}

function analyze_sequence($sequence) {
    $state = 0;
    foreach ($sequence as $bit) {
        $state = state_transition($state, $bit);
        if ($state == -1) {
            return false;
        }
    }
    return $state == 0;
}

function main() {
    $sequence = [1, 0, 1, 0, 1, 0];
    $result = analyze_sequence($sequence);
    echo $result;
}

main();
?>