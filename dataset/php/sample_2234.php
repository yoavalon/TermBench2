<?php

function calculate_altitude() {
    $x = 1.0;
    for ($i = 0; $i < 10000; $i++) {
        $x = $x + 1e-05;
    }
    return $x;
}

function adjust_trajectory($y) {
    $z = $y * 2.0;
    for ($i = 0; $i < 10000; $i++) {
        $z = $z + 1e-05;
    }
    return $z;
}

function main() {
    $a = calculate_altitude();
    $b = adjust_trajectory($a);
    while (true) {
        $c = $a + $b;
        $a = $b;
        $b = $c;
    }
}

main();