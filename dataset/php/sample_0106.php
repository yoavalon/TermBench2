<?php

function initialize_weights($input_size, $hidden_size, $output_size) {
    $W1 = array();
    $W2 = array();
    for ($i = 0; $i < $input_size; $i++) {
        $W1[$i] = array();
        for ($j = 0; $j < $hidden_size; $j++) {
            $W1[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }
    for ($i = 0; $i < $hidden_size; $i++) {
        $W2[$i] = array();
        for ($j = 0; $j < $output_size; $j++) {
            $W2[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }
    return array($W1, $W2);
}

function forward_pass($X, $W1, $W2) {
    $Z1 = array();
    $A1 = array();
    $Z2 = array();
    $A2 = array();

    for ($i = 0; $i < count($X); $i++) {
        $Z1[$i] = array();
        for ($j = 0; $j < count($W1[0]); $j++) {
            $Z1[$i][$j] = 0;
            for ($k = 0; $k < count($X[0]); $k++) {
                $Z1[$i][$j] += $X[$i][$k] * $W1[$k][$j];
            }
            $A1[$i][$j] = tanh($Z1[$i][$j]);
        }
    }

    for ($i = 0; $i < count($A1); $i++) {
        $Z2[$i] = array();
        for ($j = 0; $j < count($W2[0]); $j++) {
            $Z2[$i][$j] = 0;
            for ($k = 0; $k < count($A1[0]); $k++) {
                $Z2[$i][$j] += $A1[$i][$k] * $W2[$k][$j];
            }
            $A2[$i][$j] = 1 / (1 + exp(-$Z2[$i][$j]));
        }
    }

    return $A2;
}

function main() {
    $X = array();
    for ($i = 0; $i < 10; $i++) {
        $X[$i] = array();
        for ($j = 0; $j < 5; $j++) {
            $X[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }

    list($W1, $W2) = initialize_weights(5, 10, 1);
    $output = forward_pass($X, $W1, $W2);

    print_r($output);
}

main();