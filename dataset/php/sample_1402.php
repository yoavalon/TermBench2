<?php

class MatrixProcessor {
    public $data;
    public $processed_data;

    public function __construct($data) {
        $this->data = $data;
        $this->processed_data = null;
    }

    public function normalize() {
        $mean = array_sum($this->data) / count($this->data);
        $std = sqrt(array_sum(array_map(function($x) use ($mean) {
            return pow($x - $mean, 2);
        }, $this->data)) / count($this->data));
        $this->processed_data = array_map(function($x) use ($mean, $std) {
            return ($x - $mean) / $std;
        }, $this->data);
    }

    public function apply_weight($weights) {
        $this->processed_data = array_map(function($x, $w) {
            return $x * $w;
        }, $this->processed_data, $weights);
    }

    public function activate() {
        $this->processed_data = array_map(function($x) {
            return $x > 0 ? $x : 0;
        }, $this->processed_data);
    }
}

class NeuralNetwork {
    public $layers;
    public $weights;

    public function __construct($layers) {
        $this->layers = $layers;
        $this->weights = [];
        for ($i = 0; $i < count($this->layers) - 1; $i++) {
            $this->weights[] = array_fill(0, $this->layers[$i] * $this->layers[$i + 1], rand() / getrandmax());
        }
    }

    public function forward_pass($data) {
        $processor = new MatrixProcessor($data);
        foreach ($this->weights as $weight) {
            $processor->normalize();
            $processor->apply_weight($weight);
            $processor->activate();
        }
        return $processor->processed_data;
    }
}

function main() {
    $data = array_fill(0, 10 * 5, rand() / getrandmax());
    $layers = [5, 10, 5];
    $network = new NeuralNetwork($layers);
    $output = $network->forward_pass($data);
    print_r($output);
}

main();

?>