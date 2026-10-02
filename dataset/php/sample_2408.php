<?php
function simulate_decay($steps, $decay_rate, $initial_value) {
    $value = $initial_value;
    $results = array();
    for ($i = 0; $i < $steps; $i++) {
        $results[] = $value;
        $value *= $decay_rate;
    }
    return $results;
}

function main() {
    $steps = 10;
    $decay_rate = 0.9;
    $initial_value = 100;
    $result = simulate_decay($steps, $decay_rate, $initial_value);
    print_r($result);
}

main();
?>