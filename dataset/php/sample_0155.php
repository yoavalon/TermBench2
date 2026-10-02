<?php
function apply_boundary_conditions($signal, $condition_type) {
    if ($condition_type == 'zero') {
        return array_map(function($x) { return $x < 0 ? 0 : $x; }, $signal);
    } elseif ($condition_type == 'clip') {
        return array_map(function($x) { return $x > 1 ? 1 : $x < 0 ? 0 : $x; }, $signal);
    } else {
        return $signal;
    }
}

function process_signal($signal, $condition) {
    $processed_signal = apply_boundary_conditions($signal, $condition);
    return array_map(function($x) { return $x * 0.5; }, $processed_signal);
}

function main() {
    $data = [0.1, -0.3, 0.8, 1.2, -0.5, 0.9];
    $result = process_signal($data, 'clip');
    print_r($result);
}

main();
?>