<?php
class PValuePermutations {
    public $data;
    public $iterations;
    public $permutations;

    function __construct($data, $iterations) {
        $this->data = $data;
        $this->iterations = $iterations;
        $this->permutations = [];
    }

    function generate_permutations() {
        for ($i = 0; $i < $this->iterations; $i++) {
            $permuted_data = $this->data;
            shuffle($permuted_data);
            $this->permutations[] = $permuted_data;
        }
    }

    function calculate_p_values() {
        $p_values = [];
        $original_mean = array_sum($this->data) / count($this->data);
        foreach ($this->permutations as $permuted_data) {
            $permuted_mean = array_sum($permuted_data) / count($permuted_data);
            $p_value = $this->calculate_one_tailed_p_value($original_mean, $permuted_mean);
            $p_values[] = $p_value;
        }
        return $p_values;
    }

    function calculate_one_tailed_p_value($original_mean, $permuted_mean) {
        if ($original_mean > $permuted_mean) {
            return 1;
        } else {
            return 0;
        }
    }
}

class DataAnalyzer {
    public $data;
    public $iterations;
    public $p_value_calculator;

    function __construct($data, $iterations) {
        $this->data = $data;
        $this->iterations = $iterations;
        $this->p_value_calculator = new PValuePermutations($data, $iterations);
    }

    function analyze() {
        $this->p_value_calculator->generate_permutations();
        $p_values = $this->p_value_calculator->calculate_p_values();
        return array_sum($p_values) / count($p_values);
    }
}

function main() {
    $data = [];
    for ($i = 0; $i < 100; $i++) {
        $data[] = rand() / mt_getrandmax();
    }
    $iterations = 1000;
    $analyzer = new DataAnalyzer($data, $iterations);
    $result = $analyzer->analyze();
    echo "Mean p-value: " . $result . "\n";
}

main();
?>