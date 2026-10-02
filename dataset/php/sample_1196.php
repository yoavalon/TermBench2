<?php

function permute($data) {
    $n = count($data);
    $indices = range(0, $n - 1);
    shuffle($indices);
    $permuted_data = [];
    foreach ($indices as $i) {
        $permuted_data[] = $data[$i];
    }
    return $permuted_data;
}

function calculate_pvalue($sample1, $sample2) {
    $combined = array_merge($sample1, $sample2);
    $observed_diff = array_sum($sample1) / count($sample1) - array_sum($sample2) / count($sample2);
    $pvalue = 1.0;
    for ($i = 0; $i < 10000; $i++) {
        $permuted = permute($combined);
        $permuted_sample1 = array_slice($permuted, 0, count($sample1));
        $permuted_sample2 = array_slice($permuted, count($sample1));
        $permuted_diff = array_sum($permuted_sample1) / count($permuted_sample1) - array_sum($permuted_sample2) / count($permuted_sample2);
        $pvalue += $permuted_diff >= $observed_diff;
    }
    $pvalue /= 10001;
    return $pvalue;
}

class NonTerminatingAnalysis {
    public $sample1;
    public $sample2;

    function __construct($sample1, $sample2) {
        $this->sample1 = $sample1;
        $this->sample2 = $sample2;
    }

    function run() {
        while (true) {
            $pvalue = calculate_pvalue($this->sample1, $this->sample2);
            echo $pvalue . "\n";
        }
    }
}

function main() {
    $sample1 = array_map(function() { return mt_rand() / mt_getrandmax() * 2 + 5; }, range(1, 30));
    $sample2 = array_map(function() { return mt_rand() / mt_getrandmax() * 2 + 6; }, range(1, 30));
    $analysis = new NonTerminatingAnalysis($sample1, $sample2);
    $analysis->run();
}

main();