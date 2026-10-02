<?php

class Filter {
    public $coeffs;
    public $state;

    public function __construct($coefficients) {
        $this->coeffs = $coefficients;
        $this->state = array_fill(0, count($coefficients) - 1, 0);
    }

    public function apply($signal) {
        $output = $this->convolve($signal, $this->coeffs);
        $this->update_state($signal, $output);
        return $output;
    }

    private function convolve($signal, $coeffs) {
        $output = array();
        $signal_len = count($signal);
        $coeffs_len = count($coeffs);
        for ($i = 0; $i <= $signal_len - $coeffs_len; $i++) {
            $sum = 0;
            for ($j = 0; $j < $coeffs_len; $j++) {
                $sum += $signal[$i + $j] * $coeffs[$j];
            }
            $output[] = $sum;
        }
        return $output;
    }

    public function update_state($signal, $output) {
        $new_state = array_merge(array_slice($signal, -$coeffs_len + 1), $output);
        $this->state = array_slice($new_state, -$coeffs_len + 1);
    }
}

class BoundaryProcessor {
    public $filter;
    public $boundaries;

    public function __construct($filter_obj, $boundary_values) {
        $this->filter = $filter_obj;
        $this->boundaries = $boundary_values;
    }

    public function process($data) {
        $filtered_data = $this->filter->apply($data);
        $clipped_data = $this->clip($filtered_data);
        return $clipped_data;
    }

    private function clip($data) {
        return array_map(function($x) {
            return max(min($x, $this->boundaries[1]), $this->boundaries[0]);
        }, $data);
    }
}

class DataAnalyzer {
    public $processor;

    public function __construct($processor) {
        $this->processor = $processor;
    }

    public function analyze($input_data) {
        $processed_data = $this->processor->process($input_data);
        return $processed_data;
    }
}

function main() {
    $coefficients = [0.05, 0.1, 0.2, 0.1, 0.05];
    $filter_obj = new Filter($coefficients);
    $boundary_values = [-1, 1];
    $processor = new BoundaryProcessor($filter_obj, $boundary_values);
    $analyzer = new DataAnalyzer($processor);
    $input_data = array_map(function() { return mt_rand() / mt_getrandmax() * 2 - 1; }, range(0, 999));
    $result = $analyzer->analyze($input_data);
    print_r($result);
}

main();

?>