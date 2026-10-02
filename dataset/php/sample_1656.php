<?php

function simulate_state($state, $rate) {
    while (true) {
        $state = mutate_state($state, $rate);
        yield $state;
    }
}

function mutate_state($state, $rate) {
    for ($i = 0; $i < count($state); $i++) {
        if ($state[$i] > 0) {
            $state[$i] -= $rate;
        } else {
            $state[$i] = 0;
        }
    }
    return $state;
}

function main() {
    $initial_state = [10, 20, 30, 40, 50];
    $mutation_rate = 5;
    foreach (simulate_state($initial_state, $mutation_rate) as $state) {
        print_r($state);
    }
}

main();

?>