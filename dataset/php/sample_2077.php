<?php

class MatrixOperations {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function forward_pass($weights) {
        $result = [];
        for ($i = 0; $i < count($this->data); $i++) {
            $sum = 0;
            for ($j = 0; $j < count($this->data[0]); $j++) {
                $sum += $this->data[$i][$j] * $weights[$j];
            }
            $result[] = $sum;
        }
        return $result;
    }

    public function activation_function($x) {
        return max(0, $x);
    }

    public function process($weights) {
        $intermediate = $this->forward_pass($weights);
        $result = array_map([$this, 'activation_function'], $intermediate);
        return $result;
    }
}

class NeuralNetwork {
    public $layers;

    public function __construct($layers) {
        $this->layers = $layers;
    }

    public function predict($input_data) {
        $result = $input_data;
        foreach ($this->layers as $layer) {
            $result = $layer->process($result);
        }
        return $result;
    }
}

function generate_random_data($shape) {
    $data = [];
    for ($i = 0; $i < $shape[0]; $i++) {
        $row = [];
        for ($j = 0; $j < $shape[1]; $j++) {
            $row[] = rand() / getrandmax();
        }
        $data[] = $row;
    }
    return $data;
}

function main() {
    $input_shape = [10, 5];
    $weight_shape = [5, 3];
    $num_layers = 3;
    $input_data = generate_random_data($input_shape);
    $weights = generate_random_data($weight_shape);
    $layers = [];
    for ($i = 0; $i < $num_layers; $i++) {
        $layers[] = new MatrixOperations(generate_random_data($weight_shape));
    }
    $nn = new NeuralNetwork($layers);
    $output = $nn->predict($input_data);
    print_r($output);
}

main();