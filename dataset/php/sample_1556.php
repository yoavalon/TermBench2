<?php

function simulate() {
    $state = [0.5, 0.5, 0.5];
    while (true) {
        for ($i = 0; $i < 3; $i++) {
            $state[$i] += mt_rand(-10, 10) / 100;
            $state[$i] = max(0, min(1, $state[$i]));
        }
        print_r($state);
    }
}

simulate();

?>