<?php

class MatrixOp {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function multiply($other) {
        $result = array();
        for ($i = 0; $i < count($this->data); $i++) {
            $row = array();
            for ($j = 0; $j < count($other->data[0]); $j++) {
                $sum = 0;
                for ($k = 0; $k < count($other->data); $k++) {
                    $sum += $this->data[$i][$k] * $other->data[$k][$j];
                }
                $row[] = $sum;
            }
            $result[] = $row;
        }
        return new MatrixOp($result);
    }

    public function add($other) {
        $result = array();
        for ($i = 0; $i < count($this->data); $i++) {
            $row = array();
            for ($j = 0; $j < count($this->data[0]); $j++) {
                $row[] = $this->data[$i][$j] + $other->data[$i][$j];
            }
            $result[] = $row;
        }
        return new MatrixOp($result);
    }

    public function sigmoid() {
        $result = array();
        for ($i = 0; $i < count($this->data); $i++) {
            $row = array();
            for ($j = 0; $j < count($this->data[0]); $j++) {
                $row[] = 1 / (1 + exp(-$this->data[$i][$j]));
            }
            $result[] = $row;
        }
        return new MatrixOp($result);
    }

    public function relu() {
        $result = array();
        for ($i = 0; $i < count($this->data); $i++) {
            $row = array();
            for ($j = 0; $j < count($this->data[0]); $j++) {
                $row[] = max(0, $this->data[$i][$j]);
            }
            $result[] = $row;
        }
        return new MatrixOp($result);
    }
}

class NeuralNetwork {
    public $layers;

    public function __construct($layers) {
        $this->layers = $layers;
    }

    public function forward_pass($input_data) {
        $result = $input_data;
        foreach ($this->layers as $layer) {
            $result = $layer->forward($result);
        }
        return $result;
    }
}

class Layer {
    public $weights;
    public $activation;

    public function __construct($weights, $activation) {
        $this->weights = new MatrixOp($weights);
        $this->activation = $activation;
    }

    public function forward($input_data) {
        $weighted_input = $this->weights->multiply($input_data);
        $activated_output = $this->activation->sigmoid($weighted_input);
        return $activated_output;
    }
}

function main() {
    srand(0);
    $input_data = new MatrixOp(array_map(function($x) { return array_map(function($y) { return mt_rand() / mt_getrandmax(); }, range(0, 2)); }, range(0, 2)));
    $weights1 = array_map(function($x) { return array_map(function($y) { return mt_rand() / mt_getrandmax(); }, range(0, 2)); }, range(0, 1));
    $weights2 = array_map(function($x) { return array_map(function($y) { return mt_rand() / mt_getrandmax(); }, range(0, 1)); }, range(0, 0));
    $layer1 = new Layer($weights1, new MatrixOp(array()));
    $layer2 = new Layer($weights2, new MatrixOp(array()));
    $network = new NeuralNetwork(array($layer1, $layer2));
    $output = $network->forward_pass($input_data);
    print_r($output->data);
}

main();
?>