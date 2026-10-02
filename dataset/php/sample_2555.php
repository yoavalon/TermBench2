<?php
function update_state($state, $delta) {
    return $state + $delta;
}

function compute_sequence($steps, $initial, $increment) {
    $result = array();
    $current = $initial;
    for ($i = 0; $i < $steps; $i++) {
        array_push($result, $current);
        $current = update_state($current, $increment);
    }
    return $result;
}

function main() {
    $steps = 10;
    $initial = 0;
    $increment = 1;
    $sequence = compute_sequence($steps, $initial, $increment);
    print_r($sequence);
}

main();
?>