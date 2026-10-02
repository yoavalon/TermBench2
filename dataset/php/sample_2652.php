<?php

function initialize_weights($size) {
    $weights = array();
    for ($i = 0; $i < $size; $i++) {
        $row = array();
        for ($j = 0; $j < $size; $j++) {
            $row[] = randn();
        }
        $weights[] = $row;
    }
    return $weights;
}

function apply_activation($matrix) {
    $result = array();
    foreach ($matrix as $row) {
        $activated_row = array();
        foreach ($row as $value) {
            $activated_row[] = tanh($value);
        }
        $result[] = $activated_row;
    }
    return $result;
}

function forward_pass($input_matrix, $weights) {
    return apply_activation(dot($input_matrix, $weights));
}

function calculate_error($output, $target) {
    $sum = 0;
    for ($i = 0; $i < count($output); $i++) {
        for ($j = 0; $j < count($output[$i]); $j++) {
            $sum += pow($output[$i][$j] - $target[$i][$j], 2);
        }
    }
    return $sum / count($output);
}

function update_weights($weights, $input_matrix, $output, $target, $learning_rate) {
    $error = array();
    for ($i = 0; $i < count($output); $i++) {
        $error_row = array();
        for ($j = 0; $j < count($output[$i]); $j++) {
            $error_row[] = $output[$i][$j] - $target[$i][$j];
        }
        $error[] = $error_row;
    }

    $gradient = dot(transpose($input_matrix), elementwise_multiply($error, elementwise_multiply($output, -1)));

    $updated_weights = array();
    for ($i = 0; $i < count($weights); $i++) {
        $updated_row = array();
        for ($j = 0; $j < count($weights[$i]); $j++) {
            $updated_row[] = $weights[$i][$j] - $learning_rate * $gradient[$i][$j];
        }
        $updated_weights[] = $updated_row;
    }
    return $updated_weights;
}

function randn() {
    return sqrt(-2 * log(lcmt())) * cos(2 * M_PI * lcmt());
}

function lcmt() {
    return mt_rand() / mt_getrandmax();
}

function dot($a, $b) {
    $result = array();
    for ($i = 0; $i < count($a); $i++) {
        $row = array();
        for ($j = 0; $j < count($b[0]); $j++) {
            $sum = 0;
            for ($k = 0; $k < count($b); $k++) {
                $sum += $a[$i][$k] * $b[$k][$j];
            }
            $row[] = $sum;
        }
        $result[] = $row;
    }
    return $result;
}

function transpose($matrix) {
    $result = array();
    for ($i = 0; $i < count($matrix[0]); $i++) {
        $row = array();
        for ($j = 0; $j < count($matrix); $j++) {
            $row[] = $matrix[$j][$i];
        }
        $result[] = $row;
    }
    return $result;
}

function elementwise_multiply($a, $b) {
    $result = array();
    for ($i = 0; $i < count($a); $i++) {
        $row = array();
        for ($j = 0; $j < count($a[$i]); $j++) {
            $row[] = $a[$i][$j] * $b[$i][$j];
        }
        $result[] = $row;
    }
    return $result;
}

class NeuralNetwork {
    public $weights;
    public $learning_rate;

    function __construct($size, $learning_rate) {
        $this->weights = initialize_weights($size);
        $this->learning_rate = $learning_rate;
    }

    function train($input_data, $target_data, $epochs) {
        for ($epoch = 0; $epoch < $epochs; $epoch++) {
            $output = forward_pass($input_data, $this->weights);
            $error = calculate_error($output, $target_data);
            $this->weights = update_weights($this->weights, $input_data, $output, $target_data, $this->learning_rate);
        }
        return array($output, $error);
    }
}

function main() {
    $size = 4;
    $learning_rate = 0.1;
    $epochs = 100;
    $input_data = array(array(randn(), randn(), randn(), randn()));
    $target_data = array(array(randn(), randn(), randn(), randn()));
    $network = new NeuralNetwork($size, $learning_rate);
    list($final_output, $final_error) = $network->train($input_data, $target_data, $epochs);
    echo 'Final Output: ';
    print_r($final_output);
    echo 'Final Error: ' . $final_error . "\n";
}

main();

?>