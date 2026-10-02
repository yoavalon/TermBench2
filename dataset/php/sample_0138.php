<?php

function apply_boundary_conditions($signal, $boundary_type) {
    if ($boundary_type == 'zero') {
        return array_pad($signal, count($signal) + 10, 0);
    } elseif ($boundary_type == 'reflect') {
        $padded_signal = $signal;
        for ($i = 0; $i < 10; $i++) {
            $padded_signal[] = $signal[count($signal) - 1 - $i];
        }
        return $padded_signal;
    } elseif ($boundary_type == 'wrap') {
        $padded_signal = $signal;
        for ($i = 0; $i < 10; $i++) {
            $padded_signal[] = $signal[$i % count($signal)];
        }
        return $padded_signal;
    } else {
        return $signal;
    }
}

function process_signal($signal) {
    $boundary_type = 'reflect';
    $processed_signal = apply_boundary_conditions($signal, $boundary_type);
    return $processed_signal;
}

if (__FILE__ == $_SERVER['argv'][0]) {
    $signal = [1, 2, 3, 4, 5];
    $result = process_signal($signal);
    print_r($result);
}
?>