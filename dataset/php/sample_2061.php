<?php

class Simulation {
    public $a;
    public $b;
    public $c;

    function __construct($a, $b, $c) {
        $this->a = $a;
        $this->b = $b;
        $this->c = $c;
    }

    function calculate($x) {
        return $this->a * pow($x, 2) + $this->b * $x + $this->c;
    }
}

class PrecisionAnalyzer {
    public $simulation;

    function __construct($simulation) {
        $this->simulation = $simulation;
    }

    function analyze($x_values) {
        $results = array();
        foreach ($x_values as $x) {
            $result = $this->simulation->calculate($x);
            array_push($results, $result);
        }
        return $results;
    }
}

class DataProcessor {
    public $analyzer;

    function __construct($analyzer) {
        $this->analyzer = $analyzer;
    }

    function process($x_values) {
        $raw_data = $this->analyzer->analyze($x_values);
        $processed_data = $this->format_data($raw_data);
        return $processed_data;
    }

    function format_data($data) {
        $formatted = array();
        foreach ($data as $value) {
            array_push($formatted, round($value, 5));
        }
        return $formatted;
    }
}

function main() {
    $sim = new Simulation(2.0, 3.0, 1.0);
    $analyzer = new PrecisionAnalyzer($sim);
    $processor = new DataProcessor($analyzer);
    $x_values = array(0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0);
    $processed_results = $processor->process($x_values);
    foreach ($processed_results as $i => $value) {
        echo 'X: ' . $x_values[$i] . ', Result: ' . $value . "\n";
    }
}

main();

?>