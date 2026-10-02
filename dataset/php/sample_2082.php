<?php

class Layer {
    public $weights;
    public $bias;

    function __construct($input_size, $output_size) {
        $this->weights = array_map(function($x) { return array_map('randn', $x); }, array_fill(0, $input_size, array_fill(0, $output_size, 0)));
        $this->bias = array_map('randn', array_fill(0, $output_size, 0));
    }

    function forward($x) {
        $result = [];
        for ($i = 0; $i < count($x); $i++) {
            $row = [];
            for ($j = 0; $j < count($this->weights[0]); $j++) {
                $sum = 0;
                for ($k = 0; $k < count($this->weights); $k++) {
                    $sum += $x[$i][$k] * $this->weights[$k][$j];
                }
                $row[] = $sum + $this->bias[$j];
            }
            $result[] = $row;
        }
        return $result;
    }
}

function relu($x) {
    return array_map(function($value) { return max(0, $value); }, $x);
}

function softmax($x) {
    $max = max(array_map('max', $x));
    $e_x = array_map(function($row) use ($max) {
        return array_map(function($value) use ($max) { return exp($value - $max); }, $row);
    }, $x);
    $sums = array_map(function($row) { return array_sum($row); }, $e_x);
    return array_map(function($row, $sum) { return array_map(function($value) use ($sum) { return $value / $sum; }, $row); }, $e_x, $sums);
}

function neural_network_forward_pass($input_data, $layers) {
    $a = $input_data;
    foreach ($layers as $layer) {
        $a = $layer->forward($a);
        $a = relu($a);
    }
    return softmax($a);
}

function generate_data($batch_size, $input_size) {
    return array_map(function($x) use ($input_size) { return array_map('randn', array_fill(0, $input_size, 0)); }, array_fill(0, $batch_size, 0));
}

function main() {
    $input_size = 784;
    $hidden_size = 256;
    $output_size = 10;
    $batch_size = 64;
    $layers = [new Layer($input_size, $hidden_size), new Layer($hidden_size, $output_size)];
    $input_data = generate_data($batch_size, $input_size);
    $output = neural_network_forward_pass($input_data, $layers);
    print_r($output);
}

function randn() {
    $u = 0;
    $v = 0;
    while ($u == 0) $u = mt_rand() / mt_getrandmax();
    while ($v == 0) $v = mt_rand() / mt_getrandmax();
    return sqrt(-2 * log($u)) * cos(2 * pi() * $v);
}

main();

?>