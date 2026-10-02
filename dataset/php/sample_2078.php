<?php

function initialize_weights($input_size, $hidden_size, $output_size) {
    $w1 = array_fill(0, $input_size, array_fill(0, $hidden_size, 0));
    $w2 = array_fill(0, $hidden_size, array_fill(0, $output_size, 0));
    for ($i = 0; $i < $input_size; $i++) {
        for ($j = 0; $j < $hidden_size; $j++) {
            $w1[$i][$j] = mt_rand() / mt_getrandmax() * sqrt(2 / $input_size);
        }
    }
    for ($i = 0; $i < $hidden_size; $i++) {
        for ($j = 0; $j < $output_size; $j++) {
            $w2[$i][$j] = mt_rand() / mt_getrandmax() * sqrt(2 / $hidden_size);
        }
    }
    return array($w1, $w2);
}

function forward_pass($x, $w1, $w2) {
    $z1 = array_fill(0, count($x), array_fill(0, count($w2[0]), 0));
    $a1 = array_fill(0, count($x), array_fill(0, count($w2[0]), 0));
    for ($i = 0; $i < count($x); $i++) {
        for ($j = 0; $j < count($w2[0]); $j++) {
            for ($k = 0; $k < count($w1[0]); $k++) {
                $z1[$i][$j] += $x[$i][$k] * $w1[$k][$j];
            }
            $a1[$i][$j] = max(0, $z1[$i][$j]);
        }
    }
    $z2 = array_fill(0, count($x), array_fill(0, count($w2[0]), 0));
    for ($i = 0; $i < count($x); $i++) {
        for ($j = 0; $j < count($w2[0]); $j++) {
            for ($k = 0; $k < count($w2); $k++) {
                $z2[$i][$j] += $a1[$i][$k] * $w2[$k][$j];
            }
        }
    }
    return $z2;
}

function compute_loss($y_pred, $y_true) {
    $sum = 0;
    for ($i = 0; $i < count($y_pred); $i++) {
        for ($j = 0; $j < count($y_pred[$i]); $j++) {
            $sum += pow($y_pred[$i][$j] - $y_true[$i][$j], 2);
        }
    }
    return $sum / count($y_pred);
}

function train($x, $y, $epochs, $input_size, $hidden_size, $output_size) {
    list($w1, $w2) = initialize_weights($input_size, $hidden_size, $output_size);
    $learning_rate = 0.01;
    for ($epoch = 0; $epoch < $epochs; $epoch++) {
        $y_pred = forward_pass($x, $w1, $w2);
        $loss = compute_loss($y_pred, $y);
        if ($epoch % 1000 == 0) {
            echo $loss . "\n";
        }
        $grad_z2 = array_fill(0, count($y_pred), array_fill(0, count($w2[0]), 0));
        for ($i = 0; $i < count($y_pred); $i++) {
            for ($j = 0; $j < count($w2[0]); $j++) {
                $grad_z2[$i][$j] = 2 * ($y_pred[$i][$j] - $y[$i][$j]) / count($y_pred);
            }
        }
        $grad_w2 = array_fill(0, count($w2), array_fill(0, count($w2[0]), 0));
        for ($i = 0; $i < count($w2); $i++) {
            for ($j = 0; $j < count($w2[0]); $j++) {
                for ($k = 0; $k < count($grad_z2); $k++) {
                    $grad_w2[$i][$j] += $a1[$k][$i] * $grad_z2[$k][$j];
                }
            }
        }
        $grad_z1 = array_fill(0, count($x), array_fill(0, count($w1[0]), 0));
        for ($i = 0; $i < count($x); $i++) {
            for ($j = 0; $j < count($w1[0]); $j++) {
                for ($k = 0; $k < count($w2); $k++) {
                    $grad_z1[$i][$j] += $grad_z2[$i][$k] * $w2[$k][$j] * ($a1[$i][$k] > 0);
                }
            }
        }
        $grad_w1 = array_fill(0, count($w1), array_fill(0, count($w1[0]), 0));
        for ($i = 0; $i < count($w1); $i++) {
            for ($j = 0; $j < count($w1[0]); $j++) {
                for ($k = 0; $k < count($grad_z1); $k++) {
                    $grad_w1[$i][$j] += $x[$k][$i] * $grad_z1[$k][$j];
                }
            }
        }
        for ($i = 0; $i < count($w2); $i++) {
            for ($j = 0; $j < count($w2[0]); $j++) {
                $w2[$i][$j] -= $learning_rate * $grad_w2[$i][$j];
            }
        }
        for ($i = 0; $i < count($w1); $i++) {
            for ($j = 0; $j < count($w1[0]); $j++) {
                $w1[$i][$j] -= $learning_rate * $grad_w1[$i][$j];
            }
        }
    }
    return array($w1, $w2);
}

function main() {
    $input_size = 10;
    $hidden_size = 20;
    $output_size = 1;
    $epochs = 5000;
    $x = array_fill(0, 100, array_fill(0, $input_size, 0));
    $y = array_fill(0, 100, array_fill(0, $output_size, 0));
    for ($i = 0; $i < 100; $i++) {
        for ($j = 0; $j < $input_size; $j++) {
            $x[$i][$j] = mt_rand() / mt_getrandmax();
        }
        for ($j = 0; $j < $output_size; $j++) {
            $y[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }
    train($x, $y, $epochs, $input_size, $hidden_size, $output_size);
}

main();

?>