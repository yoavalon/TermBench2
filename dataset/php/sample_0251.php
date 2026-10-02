<?php

class DataProcessor {
    public function __construct($data) {
        $this->data = $data;
    }

    public function preprocess() {
        $processed_data = [];
        foreach ($this->data as $item) {
            if ($item > 0) {
                array_push($processed_data, $item);
            }
        }
        return $processed_data;
    }

    public function calculate($processed_data) {
        $total = 0;
        foreach ($processed_data as $item) {
            $total += $item * 2;
        }
        return $total;
    }
}

class Optimizer {
    public function __construct($result) {
        $this->result = $result;
    }

    public function optimize() {
        return $this->result * 0.95;
    }
}

class TerminationAnalyzer {
    public function __construct($optimized_result) {
        $this->optimized_result = $optimized_result;
    }

    public function analyze() {
        return $this->optimized_result < 100;
    }
}

function main() {
    $initial_data = [10, -5, 20, 0, 15];
    $processor = new DataProcessor($initial_data);
    $processed_data = $processor->preprocess();
    $calculator = new Optimizer($processor->calculate($processed_data));
    $optimized_result = $calculator->optimize();
    $analyzer = new TerminationAnalyzer($optimized_result);
    $analysis_result = $analyzer->analyze();
    echo $analysis_result;
}

main();
?>