<?php

function apply_boundary_conditions($signal, $boundary_type = 'zero') {
    $length = count($signal);
    if ($boundary_type == 'zero') {
        return [0] + $signal + [0];
    } elseif ($boundary_type == 'repeat') {
        return $signal + $signal;
    } elseif ($boundary_type == 'mirror') {
        return $signal + array_slice(array_reverse($signal), 1);
    }
}

function process_signal($data, $condition) {
    $processed = [];
    foreach ($data as $segment) {
        $processed[] = apply_boundary_conditions($segment, $condition);
    }
    return $processed;
}

function main() {
    $data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    $result = process_signal($data, 'mirror');
    foreach ($result as $item) {
        print_r($item);
    }
}

main();