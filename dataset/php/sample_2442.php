<?php

function simulate_p_values($n) {
    $data = array();
    for ($i = 0; $i < $n; $i++) {
        $data[] = rand() / getrandmax();
    }
    
    $p_values = array();
    for ($i = 0; $i < $n; $i++) {
        $p_values[] = rand() / getrandmax();
    }
    
    array_multisort($data, SORT_ASC, $p_values);
    return $p_values;
}

function main() {
    $n = 1000;
    $result = simulate_p_values($n);
    print_r($result);
}

main();