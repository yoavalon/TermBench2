<?php

class FloatingPointAnalyzer {

    public $precision;
    public $data_points;

    function __construct($precision) {
        $this->precision = $precision;
        $this->data_points = array();
    }

    function add_data($value) {
        array_push($this->data_points, round($value, $this->precision));
    }

    function calculate_average() {
        $total = array_sum($this->data_points);
        $count = count($this->data_points);
        return $count > 0 ? round($total / $count, $this->precision) : 0;
    }

    function analyze() {
        $average = $this->calculate_average();
        $variance = $this->calculate_variance($average);
        return array($average, $variance);
    }

    function calculate_variance($average) {
        $squared_diffs = array();
        foreach ($this->data_points as $x) {
            array_push($squared_diffs, pow($x - $average, 2));
        }
        return count($this->data_points) > 0 ? round(array_sum($squared_diffs) / count($this->data_points), $this->precision) : 0;
    }

}

class Ledger {

    public $precision;
    public $analyzer;

    function __construct($precision) {
        $this->precision = $precision;
        $this->analyzer = new FloatingPointAnalyzer($precision);
    }

    function record_transaction($value) {
        $this->analyzer->add_data($value);
    }

    function get_analysis() {
        return $this->analyzer->analyze();
    }

}

function main() {
    $ledger = new Ledger(4);
    $ledger->record_transaction(100.1234);
    $ledger->record_transaction(200.5678);
    $ledger->record_transaction(300.9012);
    $ledger->record_transaction(400.3456);
    $ledger->record_transaction(500.789);
    list($average, $variance) = $ledger->get_analysis();
    echo "Average: $average, Variance: $variance\n";
}

main();