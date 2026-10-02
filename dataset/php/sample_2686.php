<?php

class SequenceGenerator {
    public $size;
    public $data;

    public function __construct($size) {
        $this->size = $size;
        $this->data = array_map(function($_) { return mt_rand() / mt_getrandmax(); }, range(0, $size - 1));
    }

    public function generate_sequence() {
        return $this->data;
    }
}

class PValueCalculator {
    public $sequence1;
    public $sequence2;

    public function __construct($sequence1, $sequence2) {
        $this->sequence1 = $sequence1;
        $this->sequence2 = $sequence2;
    }

    public function calculate_p_value() {
        $diff = array_sum($this->sequence1) / count($this->sequence1) - array_sum($this->sequence2) / count($this->sequence2);
        $bootstrap_samples = [];
        for ($i = 0; $i < 1000; $i++) {
            $combined = array_merge($this->sequence1, $this->sequence2);
            shuffle($combined);
            $new_mean_diff = array_sum(array_slice($combined, 0, count($this->sequence1))) / count($this->sequence1) - array_sum(array_slice($combined, count($this->sequence1))) / count($this->sequence2);
            $bootstrap_samples[] = $new_mean_diff;
        }
        $bootstrap_samples = array_map('abs', $bootstrap_samples);
        $count = count($bootstrap_samples);
        $p_value = (array_sum(array_map(function($x) use ($diff) { return abs($x) >= abs($diff); }, $bootstrap_samples)) + 1) / ($count + 1);
        return $p_value;
    }
}

class AnalysisRunner {
    public $sequence_generator1;
    public $sequence_generator2;

    public function __construct($sequence_generator1, $sequence_generator2) {
        $this->sequence_generator1 = $sequence_generator1;
        $this->sequence_generator2 = $sequence_generator2;
    }

    public function run_analysis() {
        $seq1 = $this->sequence_generator1->generate_sequence();
        $seq2 = $this->sequence_generator2->generate_sequence();
        $p_value_calculator = new PValueCalculator($seq1, $seq2);
        $p_value = $p_value_calculator->calculate_p_value();
        return $p_value;
    }
}

function main() {
    $size1 = 100;
    $size2 = 100;
    $seq_gen1 = new SequenceGenerator($size1);
    $seq_gen2 = new SequenceGenerator($size2);
    $analysis_runner = new AnalysisRunner($seq_gen1, $seq_gen2);
    $result = $analysis_runner->run_analysis();
    echo $result;
}

main();