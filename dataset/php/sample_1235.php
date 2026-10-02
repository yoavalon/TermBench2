<?php

function run() {
    $data = [];
    for ($i = 0; $i < 100; $i++) {
        $data[] = rand() / getrandmax();
    }
    $test_stat = array_sum($data) / count($data);
    $p_values = [];
    for ($j = 0; $j < 1000; $j++) {
        $count = 0;
        for ($k = 0; $k < 100; $k++) {
            if (rand() / getrandmax() < $test_stat) {
                $count++;
            }
        }
        $p_values[] = $count / 100;
    }
    echo max($p_values);
}

run();

?>