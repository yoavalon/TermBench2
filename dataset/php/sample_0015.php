<?php

function simulate_cipher($data, $iterations) {
    if ($iterations <= 0) {
        return $data;
    }
    for ($i = 0; $i < $iterations; $i++) {
        $data = hash('sha256', $data, true);
    }
    return $data;
}

function main() {
    $a = 'initial_data';
    $b = 3;
    $result = simulate_cipher($a, $b);
    print_r($result);
}

main();
?>