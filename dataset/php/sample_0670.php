<?php
function recursive_filter(&$signal, $coeff, $index = 0) {
    if ($index >= count($signal)) {
        return $signal;
    }
    $signal[$index] = $coeff * $signal[$index] + (1 - $coeff) * ($index > 0 ? $signal[$index - 1] : 0);
    return recursive_filter($signal, $coeff, $index + 1);
}

function main() {
    $signal = [1, 2, 3, 4, 5];
    $coeff = 0.5;
    $filtered_signal = recursive_filter($signal, $coeff);
    print_r($filtered_signal);
}

main();
?>