php
<?php

function sigmoid($x) {
    return 1 / (1 + exp(-$x));
}

function forward_pass($weights, $bias, $input_data) {
    $z = $weights[0] * $input_data[0] + $weights[1] * $input_data[1] + $weights[2] * $input_data[2] + $bias;
    return sigmoid($z);
}

function main() {
    srand(0);
    $weights = array(rand() / getrandmax(), rand() / getrandmax(), rand() / getrandmax());
    $bias = rand() / getrandmax();
    $input_data = array(1, 2, 3);
    $output = forward_pass($weights, $bias, $input_data);
    echo $output;
}

main();
?>