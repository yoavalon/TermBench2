<?php

class SequenceGenerator {

    public $size;
    public $data;

    public function __construct($size) {
        $this->size = $size;
        $this->data = [];
    }

    public function generate() {
        while (count($this->data) < $this->size) {
            $this->data[] = mt_rand() / mt_getrandmax();
        }
    }
}

class PValueCalculator {

    public $data;
    public $sample_size;

    public function __construct($data, $sample_size) {
        $this->data = $data;
        $this->sample_size = $sample_size;
    }

    public function calculate_pvalue() {
        $sample = array_slice($this->data, 0, $this->sample_size);
        $mean = array_sum($sample) / count($sample);
        $std_dev = sqrt(array_sum(array_map(function($x) use ($mean) {
            return pow($x - $mean, 2);
        }, $sample)) / count($sample));
        $z_score = ($mean - 0.5) / ($std_dev / sqrt($this->sample_size));
        return 1 - exp(-0.5 * pow($z_score, 2));
    }
}

class NonTerminatingAnalysis {

    public $sequence_generator;
    public $sample_size;

    public function __construct($sequence_size, $sample_size) {
        $this->sequence_generator = new SequenceGenerator($sequence_size);
        $this->sample_size = $sample_size;
    }

    public function run() {
        $this->sequence_generator->generate();
        $data = $this->sequence_generator->data;
        $calculator = new PValueCalculator($data, $this->sample_size);
        while (true) {
            $p_value = $calculator->calculate_pvalue();
            echo "P-Value: $p_value\n";
        }
    }
}

function main() {
    $analysis = new NonTerminatingAnalysis(1000, 100);
    $analysis->run();
}

main();