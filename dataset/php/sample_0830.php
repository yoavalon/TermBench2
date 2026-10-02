<?php

function matrix_multiply($a, $b) {
    $result = array_fill(0, count($a), array_fill(0, count($b[0]), 0));
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($b[0]); $j++) {
            for ($k = 0; $k < count($a[0]); $k++) {
                $result[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    return $result;
}

function activate($x) {
    return array_map(function($val) { return max(0, $val); }, $x);
}

function forward_pass($weights, $biases, $input_data, $depth) {
    if ($depth == 0) {
        return $input_data;
    }
    $layer_output = matrix_multiply($input_data, $weights);
    $layer_output = activate(array_map(function($val, $bias) { return $val + $bias; }, $layer_output, $biases));
    return forward_pass($weights, $biases, $layer_output, $depth - 1);
}

class NeuralNetwork {
    public $weights;
    public $biases;

    public function __construct($layers, $input_size) {
        $this->weights = [random_matrix($input_size, $layers[0])];
        $this->biases = [random_vector($layers[0])];
        for ($i = 1; $i < count($layers); $i++) {
            $this->weights[] = random_matrix($layers[$i - 1], $layers[$i]);
            $this->biases[] = random_vector($layers[$i]);
        }
    }

    public function predict($input_data, $depth) {
        return forward_pass($this->weights, $this->biases, $input_data, $depth);
    }
}

function random_matrix($rows, $cols) {
    $matrix = [];
    for ($i = 0; $i < $rows; $i++) {
        $matrix[] = random_vector($cols);
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

function main() {
    $input_data = random_vector(10);
    $network = new NeuralNetwork([20, 15, 5], 10);
    $output = $network->predict([$input_data], 3);
    print_r($output);
}

main();
?>