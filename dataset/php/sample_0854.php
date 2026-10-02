php
<?php

class NeuralNetwork {
    public $weights;
    public $biases;
    public $layers;

    function __construct($weights, $biases) {
        $this->weights = $weights;
        $this->biases = $biases;
        $this->layers = count($weights) + 1;
    }

    function forward_pass($input_data) {
        function activation($x) {
            return max(0, $x);
        }

        function recursive_forward($current_layer, $current_input, $weights, $biases) {
            if ($current_layer == $this->layers) {
                return $current_input;
            }
            $weighted_input = array_dot($current_input, $weights[$current_layer - 1]) + $biases[$current_layer - 1];
            $activated_output = array_map('activation', $weighted_input);
            return recursive_forward($current_layer + 1, $activated_output, $weights, $biases);
        }
        return recursive_forward(1, $input_data, $this->weights, $this->biases);
    }
}

function generate_weights_and_biases($layers, $input_size, $output_size) {
    $weights = [];
    $biases = [];
    for ($i = 0; $i < $layers - 1; $i++) {
        if ($i == 0) {
            $weight_layer = random_matrix($input_size, $input_size);
        } elseif ($i == $layers - 2) {
            $weight_layer = random_matrix($input_size, $output_size);
        } else {
            $weight_layer = random_matrix($input_size, $input_size);
        }
        $weights[] = $weight_layer;
        $biases[] = random_vector($input_size);
    }
    $biases[] = random_vector($output_size);
    return array($weights, $biases);
}

function random_matrix($rows, $cols) {
    $matrix = [];
    for ($i = 0; $i < $rows; $i++) {
        $row = [];
        for ($j = 0; $j < $cols; $j++) {
            $row[] = mt_rand() / mt_getrandmax();
        }
        $matrix[] = $row;
    }
    return $matrix;
}

function random_vector($size) {
    $vector = [];
    for ($i = 0; $i < $size; $i++) {
        $vector[] = mt_rand() / mt_getrandmax();
    }
    return $vector;
}

function array_dot($arr1, $arr2) {
    $result = [];
    for ($i = 0; $i < count($arr1); $i++) {
        $sum = 0;
        for ($j = 0; $j < count($arr2[0]); $j++) {
            $sum += $arr1[$i][$j] * $arr2[$j];
        }
        $result[] = $sum;
    }
    return $result;
}

function main() {
    $input_size = 4;
    $output_size = 2;
    $layers = 3;
    list($weights, $biases) = generate_weights_and_biases($layers, $input_size, $output_size);
    $nn = new NeuralNetwork($weights, $biases);
    $input_data = random_matrix(1, $input_size);
    $output = $nn->forward_pass($input_data);
    print_r($output);
}

main();