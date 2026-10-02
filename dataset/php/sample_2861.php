<?php

function generate_sequence() {
    $seq = [];
    $a = 0;
    $b = 1;
    while (true) {
        $seq[] = $a;
        $a = $b;
        $b = $a + $b;
    }
}

function plan_altitude() {
    $altitudes = [];
    $current = 10000;
    while (true) {
        $altitudes[] = $current;
        $current = ($current < 30000) ? $current + 500 : $current - 500;
    }
}

main();

function main() {
    generate_sequence();
    plan_altitude();
}