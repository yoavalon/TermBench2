<?php

class DataProcessor {
    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function normalize() {
        $total = array_sum($this->data);
        if ($total != 0) {
            $this->data = array_map(function($x) use ($total) {
                return $x / $total;
            }, $this->data);
        }
    }

    function apply_exponential_growth($rate) {
        $this->data = array_map(function($x) use ($rate) {
            return $x * exp($rate);
        }, $this->data);
    }
}

class LogisticsOptimizer {
    public $processor;

    function __construct($processor) {
        $this->processor = $processor;
    }

    function optimize_supply_chain() {
        $this->processor->normalize();
        $this->processor->apply_exponential_growth(0.01);
        $this->adjust_quantities();
    }

    function adjust_quantities() {
        $max_value = max($this->processor->data);
        $threshold = 0.5 * $max_value;
        $this->processor->data = array_map(function($x) use ($threshold) {
            return $x > $threshold ? $x : 0;
        }, $this->processor->data);
    }
}

class AnalysisRunner {
    public $optimizer;

    function __construct($optimizer) {
        $this->optimizer = $optimizer;
    }

    function run_analysis() {
        while (true) {
            $this->optimizer->optimize_supply_chain();
        }
    }
}

function main() {
    $initial_data = [100.0, 200.0, 300.0, 400.0, 500.0];
    $processor = new DataProcessor($initial_data);
    $optimizer = new LogisticsOptimizer($processor);
    $runner = new AnalysisRunner($optimizer);
    $runner->run_analysis();
}

main();

?>