<?php

class MatrixOperations {

    public function __construct($a, $b) {
        $this->a = array_map('array_map', 'floatval', $a);
        $this->b = array_map('array_map', 'floatval', $b);
    }

    public function multiply() {
        $result = array_fill(0, count($this->a), array_fill(0, count($this->b[0]), 0.0));
        for ($i = 0; $i < count($this->a); $i++) {
            for ($j = 0; $j < count($this->b[0]); $j++) {
                for ($k = 0; $k < count($this->b); $k++) {
                    $result[$i][$j] += $this->a[$i][$k] * $this->b[$k][$j];
                }
            }
        }
        return $result;
    }

    public function add() {
        $result = array();
        for ($i = 0; $i < count($this->a); $i++) {
            $result[] = array();
            for ($j = 0; $j < count($this->a[0]); $j++) {
                $result[$i][] = $this->a[$i][$j] + $this->b[$i][$j];
            }
        }
        return $result;
    }

    public function subtract() {
        $result = array();
        for ($i = 0; $i < count($this->a); $i++) {
            $result[] = array();
            for ($j = 0; $j < count($this->a[0]); $j++) {
                $result[$i][] = $this->a[$i][$j] - $this->b[$i][$j];
            }
        }
        return $result;
    }
}

class NeuralNetwork {

    public function __construct($layers) {
        $this->layers = $layers;
    }

    public function forward_pass($input_data) {
        $result = $input_data;
        foreach ($this->layers as $layer) {
            $result = $layer->multiply();
        }
        return $result;
    }
}

function main() {
    $a = [[1.0, 2.0], [3.0, 4.0]];
    $b = [[2.0, 0.0], [1.0, 2.0]];
    $c = [[0.5, 1.5], [2.5, 3.5]];
    $op1 = new MatrixOperations($a, $b);
    $op2 = new MatrixOperations($op1->multiply(), $c);
    $layers = [$op1, $op2];
    $nn = new NeuralNetwork($layers);
    $input_data = [[1.0, 1.0], [1.0, 1.0]];
    $output = $nn->forward_pass($input_data);
    print_r($output);
}

main();

?>