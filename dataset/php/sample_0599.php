<?php

class DataGenerator {
    public $size;

    public function __construct($size) {
        $this->size = $size;
    }

    public function generate_data() {
        $data = [];
        for ($i = 0; $i < $this->size; $i++) {
            $data[] = rand() / getrandmax();
        }
        return $data;
    }
}

class PValueCalculator {
    public $data1;
    public $data2;

    public function __construct($data1, $data2) {
        $this->data1 = $data1;
        $this->data2 = $data2;
    }

    public function calculate_p_value() {
        $combined_data = array_merge($this->data1, $this->data2);
        $observed_diff = $this->mean_difference();
        shuffle($combined_data);
        $larger_count = 0;
        for ($i = 0; $i < 999; $i++) {
            $larger_count += ($this->mean_difference(array_slice($combined_data, 0, count($this->data1)), array_slice($combined_data, count($this->data1))) >= $observed_diff) ? 1 : 0;
        }
        return $larger_count / 1000;
    }

    public function mean_difference($data1 = null, $data2 = null) {
        $data1 = $data1 !== null ? $data1 : $this->data1;
        $data2 = $data2 !== null ? $data2 : $this->data2;
        return abs(array_sum($data1) / count($data1) - array_sum($data2) / count($data2));
    }
}

class AnalysisRunner {
    public $data_generator;

    public function __construct($data_generator) {
        $this->data_generator = $data_generator;
    }

    public function run_analysis() {
        while (true) {
            $data1 = $this->data_generator->generate_data();
            $data2 = $this->data_generator->generate_data();
            $calculator = new PValueCalculator($data1, $data2);
            $p_value = $calculator->calculate_p_value();
            echo "P-Value: $p_value\n";
        }
    }
}

function main() {
    $data_generator = new DataGenerator(100);
    $analysis_runner = new AnalysisRunner($data_generator);
    $analysis_runner->run_analysis();
}

main();

?>