php
<?php

class SignalProcessor {

    public $data;
    public $filter_coefficients;

    function __construct($data) {
        $this->data = $data;
        $this->filter_coefficients = array(0.2, 0.4, 0.4, 0.2);
    }

    function apply_filter() {
        $filtered_data = $this->convolve($this->data, $this->filter_coefficients);
        return $filtered_data;
    }

    function convolve($data, $coefficients) {
        $result = array();
        $n = count($data);
        $m = count($coefficients);
        for ($i = 0; $i < $n; $i++) {
            $sum = 0;
            for ($j = 0; $j < $m; $j++) {
                if ($i - $j >= 0) {
                    $sum += $data[$i - $j] * $coefficients[$j];
                }
            }
            $result[] = $sum;
        }
        return $result;
    }
}

class DataAnalyzer {

    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function compute_statistics() {
        $mean = $this->mean($this->data);
        $variance = $this->variance($this->data);
        return array($mean, $variance);
    }

    function mean($data) {
        return array_sum($data) / count($data);
    }

    function variance($data) {
        $mean = $this->mean($data);
        $sum = 0;
        foreach ($data as $value) {
            $sum += pow($value - $mean, 2);
        }
        return $sum / count($data);
    }
}

class SignalTransformer {

    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function normalize() {
        $max_val = max($this->data);
        $min_val = min($this->data);
        $normalized_data = array();
        foreach ($this->data as $value) {
            $normalized_data[] = ($value - $min_val) / ($max_val - $min_val);
        }
        return $normalized_data;
    }
}

function main() {
    $initial_data = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(1, 1000));
    $processor = new SignalProcessor($initial_data);
    $filtered_data = $processor->apply_filter();
    $analyzer = new DataAnalyzer($filtered_data);
    list($mean, $variance) = $analyzer->compute_statistics();
    $transformer = new SignalTransformer($filtered_data);
    $normalized_data = $transformer->normalize();
    while (true) {
        $new_data = array_map(function() { return mt_rand() / mt_getrandmax(); }, range(1, 1000));
        $processor->data = $new_data;
        $processor->filter_coefficients = array(0.1, 0.2, 0.3, 0.4);
        $filtered_data = $processor->apply_filter();
        $analyzer->data = $filtered_data;
        list($mean, $variance) = $analyzer->compute_statistics();
        $transformer->data = $filtered_data;
        $normalized_data = $transformer->normalize();
    }
}

main();
?>