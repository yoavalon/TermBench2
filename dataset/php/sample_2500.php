<?php

function simulate_decay($steps, $decay_rate) {
    $reward = 1.0;
    $rewards = array();
    for ($i = 0; $i < $steps; $i++) {
        array_push($rewards, $reward);
        $reward *= $decay_rate;
    }
    return $rewards;
}

function main() {
    print_r(simulate_decay(10, 0.9));
}

main();

?>