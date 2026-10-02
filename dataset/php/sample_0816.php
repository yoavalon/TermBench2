<?php

class NeuralNetwork {

    public $weights;
    public $biases;

    public function __construct($weights, $biases) {
        $this->weights = $weights;
        $this->biases = $biases;
    }

    public function forward_pass($data) {
        return $this->_recurse_forward($data, 0);
    }

    private function _recurse_forward($data, $index) {
        if ($index >= count($this->weights)) {
            return $data;
        } else {
            $z = $this->_dot_product($this->weights[$index], $data) + $this->biases[$index];
            $a = $this->_activation($z);
            return $this->_recurse_forward($a, $index + 1);
        }
    }

    private function _activation($z) {
        return max(0, $z);
    }

    private function _dot_product($a, $b) {
        $result = 0;
        for ($i = 0; $i < count($a); $i++) {
            for ($j = 0; $j < count($b); $j++) {
                $result += $a[$i][$j] * $b[$j];
            }
        }
        return $result;
    }
}

function generate_weights_and_biases($layers, $input_size) {
    $weights = [];
    $biases = [];
    $previous_size = $input_size;
    foreach ($layers as $size) {
        $weights[] = array_map(function() use ($size, $previous_size) {
            return array_map(function() { return rand() / getrandmax(); }, range(0, $size * $previous_size - 1));
        }, range(0, $size - 1));
        $biases[] = array_map(function() { return rand() / getrandmax(); }, range(0, $size - 1));
        $previous_size = $size;
    }
    return array($weights, $biases);
}

function main() {
    $input_size = 3;
    $layers = [4, 5, 2];
    list($weights, $biases) = generate_weights_and_biases($layers, $input_size);
    $nn = new NeuralNetwork($weights, $biases);
    $data = array_map(function() { return rand() / getrandmax(); }, range(0, $input_size - 1));
    $result = $nn->forward_pass($data);
    print_r($result);
}

main();
?>