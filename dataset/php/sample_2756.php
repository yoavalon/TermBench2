<?php

function simulate_thermodynamic_states() {
    $a = 1;
    $b = 1;
    while (true) {
        yield $a;
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
}

$main = simulate_thermodynamic_states();
for ($i = 0; $i < 1000000; $i++) {
    $main->next();
}