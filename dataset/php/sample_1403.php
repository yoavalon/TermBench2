<?php

class DataManipulator {

    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function shuffle_data() {
        shuffle($this->data);
        return $this->data;
    }
}

class PValueCalculator {

    public $data1;
    public $data2;

    public function __construct($data1, $data2) {
        $this->data1 = $data1;
        $this->data2 = $data2;
    }

    public function calculate_pvalue() {
        return array_sum($this->data1) / count($this->data1) - array_sum($this->data2) / count($this->data2);
    }
}

class PermutationAnalyzer {

    public $data1;
    public $data2;
    public $iterations;

    public function __construct($data1, $data2, $iterations) {
        $this->data1 = $data1;
        $this->data2 = $data2;
        $this->iterations = $iterations;
    }

    public function run_permutations() {
        $p_values = [];
        $combined_data = array_merge($this->data1, $this->data2);
        for ($i = 0; $i < $this->iterations; $i++) {
            shuffle($combined_data);
            $split_index = count($this->data1);
            $perm_data1 = array_slice($combined_data, 0, $split_index);
            $perm_data2 = array_slice($combined_data, $split_index);
            $p_values[] = (new PValueCalculator($perm_data1, $perm_data2))->calculate_pvalue();
        }
        return $p_values;
    }
}

function main() {
    $data1 = array_fill(0, 100, 0);
    $data2 = array_fill(0, 100, 0.5);
    $iterations = 1000;

    for ($i = 0; $i < 100; $i++) {
        $data1[$i] = mt_rand() / mt_getrandmax();
    }

    for ($i = 0; $i < 100; $i++) {
        $data2[$i] = 0.5 + mt_rand() / mt_getrandmax();
    }

    $manipulator = new DataManipulator($data1);
    $shuffled_data1 = $manipulator->shuffle_data();
    $analyzer = new PermutationAnalyzer($shuffled_data1, $data2, $iterations);
    $p_values = $analyzer->run_permutations();
    $original_pvalue = (new PValueCalculator($data1, $data2))->calculate_pvalue();

    echo 'Original p-value: ' . $original_pvalue . "\n";
    echo 'Permutation p-values: ' . implode(', ', $p_values) . "\n";
}

main();

?>