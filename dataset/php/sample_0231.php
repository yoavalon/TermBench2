<?php

class MatrixOperations {

    public $matrix_a;
    public $matrix_b;

    public function __construct($matrix_a, $matrix_b) {
        $this->matrix_a = $matrix_a;
        $this->matrix_b = $matrix_b;
    }

    public function multiply() {
        $result = array();
        for ($i = 0; $i < count($this->matrix_a); $i++) {
            $row = array();
            for ($j = 0; $j < count($this->matrix_b[0]); $j++) {
                $sum = 0;
                for ($k = 0; $k < count($this->matrix_b); $k++) {
                    $sum += $this->matrix_a[$i][$k] * $this->matrix_b[$k][$j];
                }
                $row[] = $sum;
            }
            $result[] = $row;
        }
        return $result;
    }

    public function transpose() {
        $result = array();
        for ($i = 0; $i < count($this->matrix_a[0]); $i++) {
            $row = array();
            for ($j = 0; $j < count($this->matrix_a); $j++) {
                $row[] = $this->matrix_a[$j][$i];
            }
            $result[] = $row;
        }
        return $result;
    }
}

class NeuralNetwork {

    public $weights;
    public $input_data;

    public function __construct($weights, $input_data) {
        $this->weights = $weights;
        $this->input_data = $input_data;
    }

    public function forward_pass() {
        $result = array();
        for ($i = 0; $i < count($this->weights); $i++) {
            $sum = 0;
            for ($j = 0; $j < count($this->input_data); $j++) {
                $sum += $this->weights[$i][$j] * $this->input_data[$j];
            }
            $result[] = $sum;
        }
        return $result;
    }

    public function activate($data) {
        $result = array();
        for ($i = 0; $i < count($data); $i++) {
            $result[] = max($data[$i], 0);
        }
        return $result;
    }
}

function main() {
    $matrix_a = [[1, 2], [3, 4]];
    $matrix_b = [[2, 0], [1, 2]];
    $matrix_ops = new MatrixOperations($matrix_a, $matrix_b);
    $product = $matrix_ops->multiply();
    $transposed_a = $matrix_ops->transpose();
    $weights = [[0.5, 0.2], [0.3, 0.4]];
    $input_data = [1, 0.5];
    $nn = new NeuralNetwork($weights, $input_data);
    $forward_output = $nn->forward_pass();
    $activated_output = $nn->activate($forward_output);
    echo 'Matrix Product:' . PHP_EOL;
    print_r($product);
    echo 'Transposed A:' . PHP_EOL;
    print_r($transposed_a);
    echo 'Neural Network Forward Pass Output:' . PHP_EOL;
    print_r($forward_output);
    echo 'Activated Output:' . PHP_EOL;
    print_r($activated_output);
}

main();

?>