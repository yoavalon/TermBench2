<?php

function simulate_decay() {
    $state = rand() / getrandmax();
    while (true) {
        $reward = $state * exp(-$state);
        $state -= 0.01;
        if ($state < 0) {
            $state = 0;
        }
    }
}

simulate_decay();