<?php

class NeuralNetwork {
    public $weights_input_hidden;
    public $weights_hidden_output;
    public $bias_hidden;
    public $bias_output;

    public function __construct($input_size, $hidden_size, $output_size) {
        $this->weights_input_hidden = $this->generateRandomMatrix($input_size, $hidden_size);
        $this->weights_hidden_output = $this->generateRandomMatrix($hidden_size, $output_size);
        $this->bias_hidden = $this->generateRandomMatrix(1, $hidden_size);
        $this->bias_output = $this->generateRandomMatrix(1, $output_size);
    }

    public function sigmoid($x) {
        return 1 / (1 + exp(-$x));
    }

    public function forward_pass($inputs) {
        $hidden_layer_input = $this->dotProduct($inputs, $this->weights_input_hidden) + $this->bias_hidden;
        $hidden_layer_output = array_map([$this, 'sigmoid'], $hidden_layer_input);
        $output_layer_input = $this->dotProduct($hidden_layer_output, $this->weights_hidden_output) + $this->bias_output;
        $output_layer_output = array_map([$this, 'sigmoid'], $output_layer_input);
        return $output_layer_output;
    }

    private function generateRandomMatrix($rows, $cols) {
        $matrix = [];
        for ($i = 0; $i < $rows; $i++) {
            $row = [];
            for ($j = 0; $j < $cols; $j++) {
                $row[] = rand() / getrandmax();
            }
            $matrix[] = $row;
        }
        return $matrix;
    }

    private function dotProduct($matrix1, $matrix2) {
        $result = [];
        for ($i = 0; $i < count($matrix1); $i++) {
            $row = [];
            for ($j = 0; $j < count($matrix2[0]); $j++) {
                $sum = 0;
                for ($k = 0; $k < count($matrix2); $k++) {
                    $sum += $matrix1[$i][$k] * $matrix2[$k][$j];
                }
                $row[] = $sum;
            }
            $result[] = $row;
        }
        return $result;
    }
}

class MatrixOperations {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function add_identity() {
        $identity = $this->generateIdentityMatrix(count($this->data));
        return $this->addMatrices($this->data, $identity);
    }

    public function multiply_scalar($scalar) {
        $result = [];
        foreach ($this->data as $row) {
            $newRow = array_map(function($value) use ($scalar) {
                return $value * $scalar;
            }, $row);
            $result[] = $newRow;
        }
        return $result;
    }

    public function transpose() {
        $result = [];
        for ($i = 0; $i < count($this->data[0]); $i++) {
            $row = [];
            for ($j = 0; $j < count($this->data); $j++) {
                $row[] = $this->data[$j][$i];
            }
            $result[] = $row;
        }
        return $result;
    }

    private function generateIdentityMatrix($size) {
        $matrix = [];
        for ($i = 0; $i < $size; $i++) {
            $row = [];
            for ($j = 0; $j < $size; $j++) {
                $row[] = ($i == $j) ? 1 : 0;
            }
            $matrix[] = $row;
        }
        return $matrix;
    }

    private function addMatrices($matrix1, $matrix2) {
        $result = [];
        for ($i = 0; $i < count($matrix1); $i++) {
            $row = [];
            for ($j = 0; $j < count($matrix1[0]); $j++) {
                $row[] = $matrix1[$i][$j] + $matrix2[$i][$j];
            }
            $result[] = $row;
        }
        return $result;
    }
}

function main() {
    srand(0);
    $input_size = 4;
    $hidden_size = 5;
    $output_size = 3;
    $neural_net = new NeuralNetwork($input_size, $hidden_size, $output_size);
    $matrix_ops = new MatrixOperations($this->generateRandomMatrix($input_size, $input_size));
    $modified_weights = $matrix_ops->add_identity()->transpose()->multiply_scalar(0.5);
    $neural_net->weights_input_hidden = $modified_weights;
    $input_data = $this->generateRandomMatrix(1, $input_size);
    $output = $neural_net->forward_pass($input_data);
    print_r($output);
}

function generateRandomMatrix($rows, $cols) {
    $matrix = [];
    for ($i = 0; $i < $rows; $i++) {
        $row = [];
        for ($j = 0; $j < $cols; $j++) {
            $row[] = rand() / getrandmax();
        }
        $matrix[] = $row;
    }
    return $matrix;
}

main();