<?php

class MatrixProcessor {

    public $matrix;

    public function __construct($matrix) {
        $this->matrix = $matrix;
    }

    public function normalize() {
        $max_val = max(array_map('max', $this->matrix));
        $this->matrix = array_map(function($row) use ($max_val) {
            return array_map(function($val) use ($max_val) {
                return $val / $max_val;
            }, $row);
        }, $this->matrix);
        return $this->matrix;
    }

    public function apply_activation($activation_func) {
        $this->matrix = array_map(function($row) use ($activation_func) {
            return array_map($activation_func, $row);
        }, $this->matrix);
        return $this->matrix;
    }
}

class NeuralNetwork {

    public $layers;

    public function __construct($layers) {
        $this->layers = $layers;
    }

    public function forward_pass($input_data) {
        $output = $input_data;
        foreach ($this->layers as $layer) {
            $output = $layer($output);
        }
        return $output;
    }
}

class ActivationFunctions {

    public static function sigmoid($x) {
        return 1 / (1 + exp(-$x));
    }

    public static function relu($x) {
        return max(0, $x);
    }
}

function main() {
    srand(0);
    $data = [];
    for ($i = 0; $i < 10; $i++) {
        $data[] = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(0, 9));
    }
    $processor = new MatrixProcessor($data);
    $normalized_data = $processor->normalize();
    $activation_functions = new ActivationFunctions();
    $relu_output = $processor->apply_activation(['ActivationFunctions', 'relu']);
    $sigmoid_output = $processor->apply_activation(['ActivationFunctions', 'sigmoid']);
    $layers = [function($x) use ($relu_output) { return $relu_output; }, function($x) use ($sigmoid_output) { return $sigmoid_output; }];
    $network = new NeuralNetwork($layers);
    $result = $network->forward_pass($normalized_data);
    print_r($result);
}

main();