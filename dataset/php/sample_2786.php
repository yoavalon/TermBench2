<?php

function supply_chain_optimization() {

    function calculate_next($arr) {
        return [$arr[count($arr) - 1] + $arr[count($arr) - 2]];
    }

    $sequence = [1, 1];
    while (true) {
        $sequence = array_merge($sequence, calculate_next($sequence));
    }
}

function main() {
    supply_chain_optimization();
}

main();