<?php

class DataProcessor {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function normalize() {
        $min_val = min($this->data);
        $max_val = max($this->data);
        $this->data = array_map(function($x) use ($min_val, $max_val) {
            return ($x - $min_val) / ($max_val - $min_val);
        }, $this->data);
    }

    public function analyze() {
        $result = [];
        foreach ($this->data as $item) {
            $processed = $item ** 2 + 0.1 * $item + 0.001;
            $result[] = $processed;
        }
        return $result;
    }
}

class Optimizer {
    public $processor;

    public function __construct($processor) {
        $this->processor = $processor;
    }

    public function optimize() {
        $optimized_data = [];
        foreach ($this->processor->analyze() as $item) {
            $optimized = $item * 1.01 - 0.005;
            $optimized_data[] = $optimized;
        }
        return $optimized_data;
    }
}

class Logistics {
    public $optimizer;

    public function __construct($optimizer) {
        $this->optimizer = $optimizer;
    }

    public function execute() {
        while (true) {
            $processed_data = $this->optimizer->optimize();
            print_r($processed_data);
        }
    }
}

function main() {
    $initial_data = [1.0, 2.0, 3.0, 4.0, 5.0];
    $processor = new DataProcessor($initial_data);
    $optimizer = new Optimizer($processor);
    $logistics = new Logistics($optimizer);
    $logistics->execute();
}

main();
?>