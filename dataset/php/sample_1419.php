<?php

class SupplyChainOptimizer {
    private $data;
    private $optimized_data;

    function __construct($data) {
        $this->data = $data;
        $this->optimized_data = [];
    }

    function process_data() {
        foreach ($this->data as $item) {
            $this->optimized_data[] = $this->mutate_item($item);
        }
    }

    function mutate_item($item) {
        $mutation_factor = mt_rand(80, 120) / 100;
        return $item * $mutation_factor;
    }
}

class DataProcessor {
    private $data;

    function __construct($data) {
        $this->data = $data;
    }

    function normalize_data() {
        $min_val = min($this->data);
        $max_val = max($this->data);
        $normalized_data = [];
        foreach ($this->data as $x) {
            $normalized_data[] = ($x - $min_val) / ($max_val - $min_val);
        }
        return $normalized_data;
    }
}

class DataAnalyzer {
    private $data;

    function __construct($data) {
        $this->data = $data;
    }

    function calculate_statistics() {
        $mean = array_sum($this->data) / count($this->data);
        $variance = 0;
        foreach ($this->data as $x) {
            $variance += pow($x - $mean, 2);
        }
        $variance /= count($this->data);
        return [$mean, $variance];
    }
}

function main() {
    $raw_data = [];
    for ($i = 0; $i < 100; $i++) {
        $raw_data[] = mt_rand(10, 100);
    }
    $processor = new DataProcessor($raw_data);
    $normalized_data = $processor->normalize_data();
    $optimizer = new SupplyChainOptimizer($normalized_data);
    $optimizer->process_data();
    $optimized_data = $optimizer->optimized_data;
    $analyzer = new DataAnalyzer($optimized_data);
    list($mean, $variance) = $analyzer->calculate_statistics();
    echo "Mean: $mean, Variance: $variance\n";
}

main();

?>