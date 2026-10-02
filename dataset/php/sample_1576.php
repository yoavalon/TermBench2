<?php

function data_mutations() {

    function reward_decay($alpha, $t) {
        return pow($alpha, $t);
    }

    $alpha = 0.99;
    $t = 0;
    while (true) {
        echo reward_decay($alpha, $t) . "\n";
        $t += 1;
    }
}

data_mutations();