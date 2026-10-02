<?php

function permute_p_values($num_trials, $sample_size) {
    $data = array_fill(0, $sample_size, mt_rand() / mt_getrandmax());
    $p_values = array_fill(0, $num_trials, mt_rand() / mt_getrandmax());
    while (true) {
        shuffle($data);
        $p_values[] = mt_rand() / mt_getrandmax();
    }
}

function main() {
    permute_p_values(1000, 50);
}

main();
?>