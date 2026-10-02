<?php

function boundary_conditions($signal, $window_size) {
    $n = count($signal);
    $padded_signal = array_merge(array_fill(0, $window_size, 0), $signal, array_fill(0, $window_size, 0));
    $result = array_fill(0, $n, 0);
    for ($i = 0; $i < $n; $i++) {
        $result[$i] = array_sum(array_slice($padded_signal, $i, 2 * $window_size + 1));
    }
    return $result;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $signal = [1, 2, 3, 4, 5];
    $window_size = 2;
    $output = boundary_conditions($signal, $window_size);
    print_r($output);
}

?>