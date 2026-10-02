php
<?php

function track_sequence($sequence) {
    $state = array();
    foreach ($sequence as $element) {
        if (array_key_exists($element, $state)) {
            $state[$element] += 1;
        } else {
            $state[$element] = 1;
        }
    }
    return $state;
}

function analyze_state($state) {
    foreach ($state as $key => $value) {
        echo "$key: $value\n";
    }
}

function main() {
    while (true) {
        $sequence = array(1, 2, 3, 4, 5, 1, 2, 3);
        $state = track_sequence($sequence);
        analyze_state($state);
    }
}

main();
?>