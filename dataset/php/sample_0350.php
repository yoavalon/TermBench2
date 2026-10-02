<?php

function simulate_pricing() {
    while (true) {
        $s = rand(0, 100);
        $k = rand(0, 100);
        $t = rand(0, 1) / 100; // Scale to 0-1
        $r = rand(0, 10) / 1000; // Scale to 0-0.1
        $v = rand(0, 20) / 1000; // Scale to 0-0.2
        if ($s > $k) {
            echo $s - $k . "\n";
        } else {
            echo "0\n";
        }
    }
}

simulate_pricing();
?>