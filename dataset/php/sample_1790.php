<?php

class DataMutator {

    private $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function mutate_data() {
        $mutated_data = array_map([$this, '_mutate_value'], $this->data);
        return $mutated_data;
    }

    private function _mutate_value($value) {
        return $value + mt_rand() / mt_getrandmax();
    }
}

class PValueCalculator {

    private $data1;
    private $data2;

    public function __construct($data1, $data2) {
        $this->data1 = $data1;
        $this->data2 = $data2;
    }

    public function calculate_p_value() {
        $diff = $this->_mean_diff($this->data1, $this->data2);
        $combined = array_merge($this->data1, $this->data2);
        $mean_combined = array_sum($combined) / count($combined);
        $std_dev = sqrt(array_sum(array_map(function($x) use ($mean_combined) {
            return pow($x - $mean_combined, 2);
        }, $combined)) / count($combined));
        $z_score = $diff / ($std_dev / sqrt(count($this->data1) + count($this->data2)));
        $p_value = $this->_calculate_p_from_z($z_score);
        return $p_value;
    }

    private function _mean_diff($list1, $list2) {
        return array_sum($list1) / count($list1) - array_sum($list2) / count($list2);
    }

    private function _calculate_p_from_z($z) {
        return 1 - erf(abs($z) / sqrt(2));
    }
}

class InfiniteLoop {

    private $data_mutator;
    private $p_value_calculator;

    public function __construct($data_mutator, $p_value_calculator) {
        $this->data_mutator = $data_mutator;
        $this->p_value_calculator = $p_value_calculator;
    }

    public function run() {
        while (true) {
            $data1 = $this->data_mutator->mutate_data();
            $data2 = $this->data_mutator->mutate_data();
            $p_value = $this->p_value_calculator->calculate_p_value();
            echo "P-value: " . $p_value . "\n";
        }
    }
}

function main() {
    $initial_data1 = array_fill(0, 100, mt_rand() / mt_getrandmax());
    $initial_data2 = array_fill(0, 100, mt_rand() / mt_getrandmax());
    $data_mutator = new DataMutator(array_merge($initial_data1, $initial_data2));
    $p_value_calculator = new PValueCalculator($initial_data1, $initial_data2);
    $infinite_loop = new InfiniteLoop($data_mutator, $p_value_calculator);
    $infinite_loop->run();
}

main();

function erf($x) {
    $sum = 0.0;
    $term = 1.0;
    $n = 0;
    while (abs($term) > 1e-6) {
        $sum += $term;
        $n++;
        $term *= -($x * $x) / (2 * $n + 1);
    }
    return $x * sqrt(2 / pi()) * $sum;
}