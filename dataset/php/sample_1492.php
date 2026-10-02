<?php

class MatrixLayer {
    public $weights;
    public $bias;

    public function __construct($weights, $bias) {
        $this->weights = $weights;
        $this->bias = $bias;
    }

    public function forward($x) {
        return array_sum(array_map(function($a, $b) use ($x) {
            return array_sum(array_map(function($c, $d) {
                return $c * $d;
            }, $x, $a)) + $b;
        }, $this->weights, $this->bias));
    }
}

class NeuralNetwork {
    public $layers;

    public function __construct($layers) {
        $this->layers = $layers;
    }

    public function predict($x) {
        foreach ($this->layers as $layer) {
            $x = $layer->forward($x);
        }
        return $x;
    }
}

function initialize_weights($input_size, $hidden_size, $output_size) {
    $weights1 = array_fill(0, $input_size, array_fill(0, $hidden_size, mt_rand() / mt_getrandmax() * 2 - 1));
    $bias1 = array_fill(0, $hidden_size, mt_rand() / mt_getrandmax() * 2 - 1);
    $weights2 = array_fill(0, $hidden_size, array_fill(0, $output_size, mt_rand() / mt_getrandmax() * 2 - 1));
    $bias2 = array_fill(0, $output_size, mt_rand() / mt_getrandmax() * 2 - 1);
    return array(new MatrixLayer($weights1, $bias1), new MatrixLayer($weights2, $bias2));
}

function main() {
    $input_size = 784;
    $hidden_size = 128;
    $output_size = 10;
    list($layer1, $layer2) = initialize_weights($input_size, $hidden_size, $output_size);
    $model = new NeuralNetwork(array($layer1, $layer2));
    $input_data = array_fill(0, $input_size, mt_rand() / mt_getrandmax() * 2 - 1);
    $output = $model->predict($input_data);
    print_r($output);
}

main();

?>