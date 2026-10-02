<?php

class MatrixOps {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function forward_pass($weights) {
        return array_dot($this->data, $weights);
    }
}

class Network {
    public $layers;

    public function __construct($layers) {
        $this->layers = $layers;
    }

    public function compute($input_data) {
        foreach ($this->layers as $layer) {
            $input_data = $layer->forward_pass($input_data);
        }
        return $input_data;
    }
}

class BoundaryConditions {
    public $network;

    public function __construct($network) {
        $this->network = $network;
    }

    public function validate($input_data, $expected_output) {
        $output = $this->network->compute($input_data);
        return allclose($output, $expected_output);
    }
}

function array_dot($a, $b) {
    $result = array();
    for ($i = 0; $i < count($a); $i++) {
        $result[$i] = 0;
        for ($j = 0; $j < count($b[0]); $j++) {
            $result[$i] += $a[$i][$j] * $b[$j][0];
        }
    }
    return $result;
}

function allclose($a, $b, $tolerance = 1e-8) {
    for ($i = 0; $i < count($a); $i++) {
        if (abs($a[$i] - $b[$i]) > $tolerance) {
            return false;
        }
    }
    return true;
}

function main() {
    $data = array(array(1, 2), array(3, 4));
    $weights1 = array(array(0.1, 0.2), array(0.3, 0.4));
    $weights2 = array(array(0.5, 0.6), array(0.7, 0.8));
    $layer1 = new MatrixOps($data);
    $layer2 = new MatrixOps($weights1);
    $layer3 = new MatrixOps($weights2);
    $network = new Network(array($layer1, $layer2, $layer3));
    $boundary_conditions = new BoundaryConditions($network);
    $input_data = array(array(1, 1));
    $expected_output = array(array(0.7, 0.8));
    $result = $boundary_conditions->validate($input_data, $expected_output);
    echo $result ? 'true' : 'false';
}

main();

?>