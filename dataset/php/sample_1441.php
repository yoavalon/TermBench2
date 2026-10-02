<?php

class MatrixProcessor {

    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function apply_transformation($weights) {
        return array_map(function($row) use ($weights) {
            return array_sum(array_map(function($value, $weight) {
                return $value * $weight;
            }, $row, $weights));
        }, $this->data);
    }

    public function sigmoid($x) {
        return 1 / (1 + exp(-$x));
    }

    public function forward_pass($weights) {
        $transformed = $this->apply_transformation($weights);
        $activated = array_map([$this, 'sigmoid'], $transformed);
        return $activated;
    }
}

class DataMutator {

    public $matrix;

    public function __construct($matrix) {
        $this->matrix = $matrix;
    }

    public function mutate($factor) {
        return array_map(function($row) use ($factor) {
            return array_map(function($value) use ($factor) {
                return $value * $factor;
            }, $row);
        }, $this->matrix);
    }

    public function normalize() {
        $norm = sqrt(array_sum(array_map(function($row) {
            return array_sum(array_map(function($value) {
                return $value * $value;
            }, $row));
        }, $this->matrix)));
        return array_map(function($row) use ($norm) {
            return array_map(function($value) use ($norm) {
                return $value / $norm;
            }, $row);
        }, $this->matrix);
    }

    public function process($factor) {
        $mutated = $this->mutate($factor);
        $normalized = $this->normalize();
        return $normalized;
    }
}

class NeuralNetwork {

    public $input_data;
    public $weights;

    public function __construct($input_data, $weights) {
        $this->input_data = $input_data;
        $this->weights = $weights;
    }

    public function execute() {
        $processor = new MatrixProcessor($this->input_data);
        $activated_output = $processor->forward_pass($this->weights);
        return $activated_output;
    }
}

function main() {
    $data = array_map(function($_) { return array_fill(0, 5, rand() / mt_getrandmax()); }, range(0, 9));
    $weights = array_map(function($_) { return array_fill(0, 3, rand() / mt_getrandmax()); }, range(0, 4));
    $factor = 2.0;
    $mutator = new DataMutator($data);
    $processed_data = $mutator->process($factor);
    $network = new NeuralNetwork($processed_data, $weights);
    $output = $network->execute();
    print_r($output);
}

main();