<?php

function initialize_weights($input_size, $hidden_size, $output_size) {
    $w1 = array_fill(0, $input_size, array_fill(0, $hidden_size, mt_rand() / mt_getrandmax() * 2 - 1));
    $w2 = array_fill(0, $hidden_size, array_fill(0, $output_size, mt_rand() / mt_getrandmax() * 2 - 1));
    return array($w1, $w2);
}

function forward_pass($x, $w1, $w2) {
    $z1 = array();
    for ($i = 0; $i < count($x); $i++) {
        $z1[$i] = array();
        for ($j = 0; $j < count($w1[0]); $j++) {
            $z1[$i][$j] = 0;
            for ($k = 0; $k < count($x[0]); $k++) {
                $z1[$i][$j] += $x[$i][$k] * $w1[$k][$j];
            }
            $z1[$i][$j] = tanh($z1[$i][$j]);
        }
    }

    $z2 = array();
    for ($i = 0; $i < count($z1); $i++) {
        $z2[$i] = array();
        for ($j = 0; $j < count($w2[0]); $j++) {
            $z2[$i][$j] = 0;
            for ($k = 0; $k < count($z1[0]); $k++) {
                $z2[$i][$j] += $z1[$i][$k] * $w2[$k][$j];
            }
        }
    }

    return $z2;
}

function main() {
    $input_size = 3;
    $hidden_size = 4;
    $output_size = 1;
    list($w1, $w2) = initialize_weights($input_size, $hidden_size, $output_size);
    $x = array_fill(0, 1, array_fill(0, $input_size, mt_rand() / mt_getrandmax() * 2 - 1));
    $output = forward_pass($x, $w1, $w2);
    print_r($output);
}

main();
?>