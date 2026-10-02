<?php

function decay_function($value, $rate) {
    return $value * (1 - $rate);
}

function reward_decay($initial_value, $rate, $steps) {
    $result = $initial_value;
    for ($i = 0; $i < $steps; $i++) {
        $result = decay_function($result, $rate);
    }
    return $result;
}

function main() {
    $initial_value = 1.0;
    $rate = 0.05;
    $steps = 100;
    $final_value = reward_decay($initial_value, $rate, $steps);
    echo $final_value;
}

main();

?>