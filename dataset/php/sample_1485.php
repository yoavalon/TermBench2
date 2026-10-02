<?php

class MatrixOperations {

    public $a;
    public $b;

    function __construct($a, $b) {
        $this->a = $a;
        $this->b = $b;
    }

    function multiply() {
        $result = [];
        for ($i = 0; $i < count($this->a); $i++) {
            $row = [];
            for ($j = 0; $j < count($this->b[0]); $j++) {
                $sum = 0;
                for ($k = 0; $k < count($this->b); $k++) {
                    $sum += $this->a[$i][$k] * $this->b[$k][$j];
                }
                $row[] = $sum;
            }
            $result[] = $row;
        }
        return $result;
    }

    function add($b) {
        $result = [];
        for ($i = 0; $i < count($this->a); $i++) {
            $row = [];
            for ($j = 0; $j < count($this->a[0]); $j++) {
                $row[] = $this->a[$i][$j] + $b[$i][$j];
            }
            $result[] = $row;
        }
        return $result;
    }

    function subtract($b) {
        $result = [];
        for ($i = 0; $i < count($this->a); $i++) {
            $row = [];
            for ($j = 0; $j < count($this->a[0]); $j++) {
                $row[] = $this->a[$i][$j] - $b[$i][$j];
            }
            $result[] = $row;
        }
        return $result;
    }
}

class NeuralNetwork {

    public $weights;
    public $biases;

    function __construct($weights, $biases) {
        $this->weights = $weights;
        $this->biases = $biases;
    }

    function forward_pass($input_data) {
        $operations = new MatrixOperations($input_data, $this->weights);
        $weighted_sum = $operations->multiply();
        $biased_sum = $operations->add($this->biases);
        return $this->activation_function($biased_sum);
    }

    function activation_function($x) {
        $result = [];
        for ($i = 0; $i < count($x); $i++) {
            $row = [];
            for ($j = 0; $j < count($x[0]); $j++) {
                $row[] = max(0, $x[$i][$j]);
            }
            $result[] = $row;
        }
        return $result;
    }
}

function main() {
    $input_data = [[1, 2], [3, 4]];
    $weights = [[0.1, 0.2], [0.3, 0.4]];
    $biases = [0.5, 0.6];
    $nn = new NeuralNetwork($weights, $biases);
    $output = $nn->forward_pass($input_data);
    print_r($output);
}

main();

?>