<?php

class Activation {

    function sigmoid($x) {
        return 1 / (1 + exp(-$x));
    }

    function relu($x) {
        return max(0, $x);
    }
}

class Layer {

    private $weights;
    private $bias;
    private $activation;

    function __construct($weights, $bias, $activation) {
        $this->weights = $weights;
        $this->bias = $bias;
        $this->activation = $activation;
    }

    function forward($input_data) {
        $z = array_sum(array_map(function($a, $b) {
            return $a * $b;
        }, $input_data, $this->weights)) + $this->bias;
        return $this->activation($z);
    }
}

class NeuralNetwork {

    private $layers;

    function __construct($layers) {
        $this->layers = $layers;
    }

    function predict($input_data) {
        foreach ($this->layers as $layer) {
            $input_data = $layer->forward($input_data);
        }
        return $input_data;
    }
}

function initialize_network($layer_sizes, $activation_type) {
    $activation = new Activation();
    $layers = [];
    for ($i = 0; $i < count($layer_sizes) - 1; $i++) {
        $weights = array_fill(0, $layer_sizes[$i], array_fill(0, $layer_sizes[$i + 1], rand() / getrandmax() * 2 - 1));
        $bias = array_fill(0, $layer_sizes[$i + 1], rand() / getrandmax() * 2 - 1);
        if ($activation_type == 'sigmoid') {
            $layers[] = new Layer($weights, $bias, array($activation, 'sigmoid'));
        } elseif ($activation_type == 'relu') {
            $layers[] = new Layer($weights, $bias, array($activation, 'relu'));
        }
    }
    return new NeuralNetwork($layers);
}

function main() {
    $input_data = array(array(0, 0), array(0, 1), array(1, 0), array(1, 1));
    $expected_output = array(array(0), array(1), array(1), array(0));
    $network = initialize_network(array(2, 4, 1), 'sigmoid');
    $output = $network->predict($input_data);
    print_r($output);
}

main();

?>