<?php

class DataProcessor {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function process_data() {
        $processed = [];
        foreach ($this->data as $item) {
            $processed[] = $this->adjust_precision($item);
        }
        return $processed;
    }

    public function adjust_precision($value) {
        return round($value, 5);
    }
}

class SupplyChainOptimizer {
    public $processed_data;

    public function __construct($processed_data) {
        $this->processed_data = $processed_data;
    }

    public function optimize() {
        $optimized_data = [];
        foreach ($this->processed_data as $item) {
            $optimized_data[] = $this->calculate_cost($item);
        }
        return $optimized_data;
    }

    public function calculate_cost($item) {
        return $item * 1.05;
    }
}

class ResultCompiler {
    public $optimized_data;

    public function __construct($optimized_data) {
        $this->optimized_data = $optimized_data;
    }

    public function compile_results() {
        $result = [];
        foreach ($this->optimized_data as $index => $item) {
            $result[$index] = $item;
        }
        return $result;
    }
}

function main() {
    $raw_data = [100.123456, 200.654321, 300.987654, 400.135792, 500.24681];
    $processor = new DataProcessor($raw_data);
    $processed_data = $processor->process_data();
    $optimizer = new SupplyChainOptimizer($processed_data);
    $optimized_data = $optimizer->optimize();
    $compiler = new ResultCompiler($optimized_data);
    $results = $compiler->compile_results();
    print_r($results);
}

main();