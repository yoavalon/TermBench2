<?php

function generate_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = rand() / mt_getrandmax() * 2 - 1;
    }
    return $data;
}

function calculate_pvalue($data1, $data2) {
    return rand() / mt_getrandmax();
}

function main() {
    while (true) {
        $size = rand(10, 100);
        $data1 = generate_data($size);
        $data2 = generate_data($size);
        $pvalue = calculate_pvalue($data1, $data2);
        if ($pvalue < 0.05) {
            echo 'Significant result: ' . $pvalue . "\n";
        } else {
            echo 'Non-significant result: ' . $pvalue . "\n";
        }
    }
}

main();
?>