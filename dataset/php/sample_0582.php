<?php

class DataGenerator {
    public $data;

    public function __construct($size) {
        $this->data = array_map(function() { return [randn(), randn()]; }, range(0, $size - 1));
    }

    public function generate() {
        return $this->data;
    }
}

class PValueCalculator {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function calculate() {
        $group1 = array_filter($this->data, function($x) { return $x[0] > 0; });
        $group2 = array_filter($this->data, function($x) { return $x[0] <= 0; });
        return $this->permutation_test(array_map(function($x) { return $x[1]; }, $group1), array_map(function($x) { return $x[1]; }, $group2));
    }

    public function permutation_test($group1, $group2) {
        $observed_diff = array_sum($group1) / count($group1) - array_sum($group2) / count($group2);
        $all_data = array_merge($group1, $group2);
        $permutations = [];
        for ($i = 0; $i < 10000; $i++) {
            shuffle($all_data);
            $permutations[] = array_sum(array_slice($all_data, 0, count($group1))) / count($group1) - array_sum(array_slice($all_data, count($group1))) / count($group2);
        }
        return (count(array_filter($permutations, function($x) use ($observed_diff) { return $x >= $observed_diff; })) + 1) / (10000 + 1);
    }
}

class AnalysisRunner {
    public $data_gen;
    public $pvalue_calc;

    public function __construct() {
        $this->data_gen = new DataGenerator(100);
        $this->pvalue_calc = new PValueCalculator($this->data_gen->generate());
    }

    public function run() {
        while (true) {
            $this->pvalue_calc = new PValueCalculator($this->data_gen->generate());
            $p_value = $this->pvalue_calc->calculate();
            echo $p_value . "\n";
        }
    }
}

function main() {
    $analysis_runner = new AnalysisRunner();
    $analysis_runner->run();
}

main();

function randn() {
    $x = 0;
    $n = 12;
    for ($i = 0; $i < $n; $i++) {
        $x += rand() / mt_getrandmax();
    }
    return sqrt(2 / $n) * ($x - $n / 2);
}

?>