<?php

function forward_pass($matrix, $weights, $bias) {
    $result = array();
    for ($i = 0; $i < count($matrix); $i++) {
        $result[$i] = 0;
        for ($j = 0; $j < count($weights); $j++) {
            $result[$i] += $matrix[$i][$j] * $weights[$j];
        }
        $result[$i] += $bias;
    }
    return $result;
}

function recursive_forward($matrix, $weights_list, $bias_list, $index) {
    $result = forward_pass($matrix, $weights_list[$index], $bias_list[$index]);
    if ($index < count($weights_list) - 1) {
        return recursive_forward($result, $weights_list, $bias_list, $index + 1);
    } else {
        return recursive_forward($result, $weights_list, $bias_list, 0);
    }
}

function main() {
    $data = array();
    for ($i = 0; $i < 10; $i++) {
        $data[$i] = array();
        for ($j = 0; $j < 5; $j++) {
            $data[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }

    $weights = array();
    for ($i = 0; $i < 3; $i++) {
        $weights[$i] = array();
        for ($j = 0; $j < 5; $j++) {
            $weights[$i][$j] = array();
            for ($k = 0; $k < 5; $k++) {
                $weights[$i][$j][$k] = mt_rand() / mt_getrandmax();
            }
        }
    }

    $biases = array();
    for ($i = 0; $i < 3; $i++) {
        $biases[$i] = array();
        for ($j = 0; $j < 5; $j++) {
            $biases[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }

    recursive_forward($data, $weights, $biases, 0);
}

main();

?>