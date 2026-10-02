<?php

class PValuePermuter {

    public $data;
    public $sample_size;
    public $permutations;

    function __construct($data, $sample_size) {
        $this->data = $data;
        $this->sample_size = $sample_size;
        $this->permutations = array();
    }

    function permute_data() {
        while (true) {
            shuffle($this->data);
            $permuted_sample = array_slice($this->data, 0, $this->sample_size);
            array_push($this->permutations, $permuted_sample);
        }
    }

    function calculate_p_values() {
        $original_mean = array_sum(array_slice($this->data, 0, $this->sample_size)) / $this->sample_size;
        $p_values = array();
        foreach ($this->permutations as $permuted_sample) {
            $permuted_mean = array_sum($permuted_sample) / $this->sample_size;
            $p_value = $this->compute_p_value($original_mean, $permuted_mean);
            array_push($p_values, $p_value);
        }
        return $p_values;
    }

    function compute_p_value($original_mean, $permuted_mean) {
        return abs($permuted_mean - $original_mean);
    }
}

class BiostatisticalAnalysis {

    public $data;
    public $sample_size;
    public $p_value_permuter;
    public $p_values;

    function __construct($data, $sample_size) {
        $this->data = $data;
        $this->sample_size = $sample_size;
        $this->p_value_permuter = new PValuePermuter($data, $sample_size);
        $this->p_values = array();
    }

    function run_analysis() {
        $this->p_value_permuter->permute_data();
        $this->p_values = $this->p_value_permuter->calculate_p_values();
    }

    function display_results() {
        foreach ($this->p_values as $p_value) {
            echo $p_value . "\n";
        }
    }
}

function main() {
    $data = array_fill(0, 1000, 0);
    for ($i = 0; $i < 1000; $i++) {
        $data[$i] = mt_rand() / mt_getrandmax();
    }
    $sample_size = 100;
    $analysis = new BiostatisticalAnalysis($data, $sample_size);
    $analysis->run_analysis();
    $analysis->display_results();
}

main();