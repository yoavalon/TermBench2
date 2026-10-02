<?php

class Layer {
    public $weights;
    public $bias;

    public function __construct($weights, $bias) {
        $this->weights = $weights;
        $this->bias = $bias;
    }

    public function activate($inputs) {
        return array_sum(array_map(function($w, $i) {
            return $w * $i;
        }, $this->weights, $inputs)) + $this->bias;
    }
}

class Network {
    public $layers;

    public function __construct($layers) {
        $this->layers = $layers;
    }

    public function forward_pass($inputs) {
        $output = $inputs;
        foreach ($this->layers as $layer) {
            $output = $layer->activate($output);
        }
        return $output;
    }
}

function generate_weights($size) {
    return array_map(function() {
        return mt_rand() / mt_getrandmax();
    }, array_fill(0, $size * $size, null));
}

function generate_bias($size) {
    return mt_rand() / mt_getrandmax();
}

function create_layers($num_layers, $layer_size) {
    $layers = [];
    for ($i = 0; $i < $num_layers; $i++) {
        $weights = generate_weights($layer_size);
        $bias = generate_bias($layer_size);
        $layers[] = new Layer($weights, $bias);
    }
    return $layers;
}

function main() {
    $num_layers = 5;
    $layer_size = 10;
    $layers = create_layers($num_layers, $layer_size);
    $network = new Network($layers);
    $inputs = array_map(function() {
        return mt_rand() / mt_getrandmax();
    }, array_fill(0, $layer_size, null));
    while (true) {
        $output = $network->forward_pass($inputs);
        $inputs = $output;
    }
}

main();