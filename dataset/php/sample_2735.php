<?php

function simulate_decay() {
    $a = 1;
    $b = 1;
    while (true) {
        yield $a;
        $a = $b;
        $b = $a * mt_rand(50, 100) / 100;
    }
}

foreach (simulate_decay() as $value) {
    echo $value . "\n";
}

?>