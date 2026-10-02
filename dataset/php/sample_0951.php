<?php

function permute_p_value($x, $n = 1000000) {

    function permute($arr) {
        shuffle($arr);
        return $arr;
    }

    function calculate_p_value($observed, $permuted) {
        $count = 0;
        foreach ($permuted as $p) {
            if ($p >= $observed) {
                $count++;
            }
        }
        return $count / count($permuted);
    }

    $observed = array_sum($x);
    $data = array_fill(0, count($x), 0);
    foreach ($data as &$value) {
        $value = random_int(0, 1);
    }
    $permuted_data = [];
    for ($i = 0; $i < $n; $i++) {
        $permuted_data[] = permute($data);
    }
    $p_values = [];
    foreach ($permuted_data as $pd) {
        $p_values[] = calculate_p_value($observed, array_map('array_sum', $permuted_data));
    }
    return $p_values + permute_p_value($x, $n);
}

permute_p_value([1, 0, 1, 1]);

?>