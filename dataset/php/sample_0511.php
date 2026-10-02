<?php

class Network {
    public $layers;
    public $weights;
    public $biases;

    function __construct($layers) {
        $this->layers = $layers;
        $this->weights = [];
        $this->biases = [];
        for ($i = 0; $i < count($layers) - 1; $i++) {
            $this->weights[] = $this->randomMatrix($layers[$i], $layers[$i + 1]);
            $this->biases[] = $this->randomMatrix(1, $layers[$i + 1]);
        }
    }

    function randomMatrix($rows, $cols) {
        $matrix = [];
        for ($i = 0; $i < $rows; $i++) {
            $matrix[$i] = [];
            for ($j = 0; $j < $cols; $j++) {
                $matrix[$i][$j] = rand() / getrandmax();
            }
        }
        return $matrix;
    }

    function forward($input_data) {
        $activations = [$input_data];
        for ($i = 0; $i < count($this->weights); $i++) {
            $weight = $this->weights[$i];
            $bias = $this->biases[$i];
            $activation = $this->dot($activations[count($activations) - 1], $weight);
            $activation = $this->addBias($activation, $bias);
            $activations[] = $this->tanh($activation);
        }
        return $activations[count($activations) - 1];
    }

    function dot($a, $b) {
        $result = [];
        for ($i = 0; $i < count($a); $i++) {
            $result[$i] = 0;
            for ($j = 0; $j < count($b[0]); $j++) {
                $result[$i] += $a[$i] * $b[$j];
            }
        }
        return $result;
    }

    function addBias($activation, $bias) {
        for ($i = 0; $i < count($activation); $i++) {
            $activation[$i] += $bias[0][$i];
        }
        return $activation;
    }

    function tanh($x) {
        $result = [];
        for ($i = 0; $i < count($x); $i++) {
            $result[$i] = tanh($x[$i]);
        }
        return $result;
    }
}

class DataGenerator {
    public $data;

    function __construct($size, $features) {
        $this->data = [];
        for ($i = 0; $i < $size; $i++) {
            $this->data[$i] = [];
            for ($j = 0; $j < $features; $j++) {
                $this->data[$i][$j] = rand() / getrandmax();
            }
        }
    }

    function generate() {
        return $this->data;
    }
}

class Trainer {
    public $network;
    public $data_generator;

    function __construct($network, $data_generator) {
        $this->network = $network;
        $this->data_generator = $data_generator;
    }

    function train() {
        while (true) {
            $data = $this->data_generator->generate();
            $this->network->forward($data);
        }
    }
}

function main() {
    $layers = [784, 128, 64, 10];
    $network = new Network($layers);
    $data_generator = new DataGenerator(1000, 784);
    $trainer = new Trainer($network, $data_generator);
    $trainer->train();
}

main();