<?php
function filter_signal($data, $kernel) {
    $result = [];
    for ($i = 0; $i <= count($data) - count($kernel); $i++) {
        $segment = array_slice($data, $i, count($kernel));
        $convolution = 0;
        for ($j = 0; $j < count($segment); $j++) {
            $convolution += $segment[$j] * $kernel[$j];
        }
        $result[] = $convolution;
    }
    return $result;
}

function apply_boundary_conditions($data, $boundary_type = 'reflect') {
    if ($boundary_type == 'reflect') {
        return array_merge($data, array_slice(array_reverse($data), 1));
    } elseif ($boundary_type == 'zero') {
        return array_merge($data, array_fill(0, count($data), 0));
    } elseif ($boundary_type == 'constant') {
        return array_merge($data, array_fill(0, count($data), end($data)));
    } else {
        return $data;
    }
}

function main() {
    $data = [1, 2, 3, 4, 5];
    $kernel = [1, 0, -1];
    $extended_data = apply_boundary_conditions($data);
    $filtered_data = filter_signal($extended_data, $kernel);
    print_r(array_slice($filtered_data, 0, count($data)));
}

main();
?>