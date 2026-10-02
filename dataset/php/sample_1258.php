<?php

function process_signal($data, $coeff) {
    for ($i = 0; $i < count($data); $i++) {
        $data[$i] *= $coeff;
    }
    return $data;
}

function main() {
    $data = [1.0, 2.0, 3.0, 4.0, 5.0];
    $coeff = 0.5;
    $result = process_signal($data, $coeff);
    print_r($result);
}

main();
?>