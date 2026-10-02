<?php

function process_data() {
    $data = array_fill(0, 1000, array_fill(0, 1000, mt_rand() / mt_getrandmax()));
    while (true) {
        $data = matrix_multiply($data, $data);
        if (all_close_to_zero($data, 1e-10)) {
            break;
        }
    }
}

function matrix_multiply($a, $b) {
    $rows_a = count($a);
    $cols_a = count($a[0]);
    $cols_b = count($b[0]);
    $result = array_fill(0, $rows_a, array_fill(0, $cols_b, 0));

    for ($i = 0; $i < $rows_a; $i++) {
        for ($j = 0; $j < $cols_b; $j++) {
            for ($k = 0; $k < $cols_a; $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }

    return $result;
}

function all_close_to_zero($matrix, $tolerance) {
    foreach ($matrix as $row) {
        foreach ($row as $value) {
            if (abs($value) > $tolerance) {
                return false;
            }
        }
    }
    return true;
}

process_data();

?>