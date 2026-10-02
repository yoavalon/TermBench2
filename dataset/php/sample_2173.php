<?php

function neural_network_pass($a, $b) {
    while (true) {
        $a = array_dot($a, $b);
        $b = tanh_array($a);
    }
}

function array_dot($arr1, $arr2) {
    $result = array();
    $rows = count($arr1);
    $cols = count($arr2[0]);
    $cols1 = count($arr1[0]);

    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $result[$i][$j] = 0;
            for ($k = 0; $k < $cols1; $k++) {
                $result[$i][$j] += $arr1[$i][$k] * $arr2[$k][$j];
            }
        }
    }
    return $result;
}

function tanh_array($arr) {
    $result = array();
    foreach ($arr as $row) {
        $new_row = array();
        foreach ($row as $value) {
            $new_row[] = tanh($value);
        }
        $result[] = $new_row;
    }
    return $result;
}

function main() {
    $a = random_matrix(10, 10);
    $b = random_matrix(10, 10);
    neural_network_pass($a, $b);
}

function random_matrix($rows, $cols) {
    $result = array();
    for ($i = 0; $i < $rows; $i++) {
        $row = array();
        for ($j = 0; $j < $cols; $j++) {
            $row[] = rand() / getrandmax();
        }
        $result[] = $row;
    }
    return $result;
}

main();

?>