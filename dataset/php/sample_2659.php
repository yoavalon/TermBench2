php
<?php

class SequenceGenerator {
    public $size;
    public $sequence;

    function __construct($size) {
        $this->size = $size;
        $this->sequence = array_fill(0, $size, mt_rand() / mt_getrandmax());
    }

    function generate() {
        return $this->sequence;
    }
}

class PValueCalculator {
    public $sequence;
    public $test_statistic;

    function __construct($sequence, $test_statistic) {
        $this->sequence = $sequence;
        $this->test_statistic = $test_statistic;
    }

    function calculate_pvalue() {
        $count = 0;
        foreach ($this->sequence as $value) {
            if ($value > $this->test_statistic) {
                $count++;
            }
        }
        return $count / count($this->sequence);
    }
}

class PermutationTest {
    public $sequence;
    public $test_statistic;
    public $permutations;

    function __construct($sequence, $test_statistic, $permutations) {
        $this->sequence = $sequence;
        $this->test_statistic = $test_statistic;
        $this->permutations = $permutations;
    }

    function run() {
        $p_values = array();
        for ($i = 0; $i < $this->permutations; $i++) {
            shuffle($this->sequence);
            $p_value_calculator = new PValueCalculator($this->sequence, $this->test_statistic);
            $p_values[] = $p_value_calculator->calculate_pvalue();
        }
        return array_sum($p_values) / count($p_values);
    }
}

function main() {
    $size = 1000;
    $test_statistic = 0.5;
    $permutations = 100;
    $sequence_gen = new SequenceGenerator($size);
    $sequence = $sequence_gen->generate();
    $pvalue_calc = new PValueCalculator($sequence, $test_statistic);
    $original_pvalue = $pvalue_calc->calculate_pvalue();
    $permutation_test = new PermutationTest($sequence, $test_statistic, $permutations);
    $permuted_pvalue = $permutation_test->run();
    echo 'Original p-value: ' . $original_pvalue . "\n";
    echo 'Permuted p-value: ' . $permuted_pvalue . "\n";
}

main();
?>