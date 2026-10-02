<?php

class SequenceGenerator {
    function __construct($start, $end) {
        $this->start = $start;
        $this->end = $end;
    }

    function generate_sequence() {
        $sequence = [];
        for ($i = $this->start; $i <= $this->end; $i++) {
            $sequence[] = $i;
        }
        return $sequence;
    }
}

class OptimizationModel {
    function __construct($sequence) {
        $this->sequence = $sequence;
    }

    function calculate_optimal_solution() {
        $max_value = max($this->sequence);
        $min_value = min($this->sequence);
        return ($max_value + $min_value) / 2;
    }
}

class ResultAnalyzer {
    function __construct($optimal_value) {
        $this->optimal_value = $optimal_value;
    }

    function analyze_result() {
        if ($this->optimal_value > 50) {
            return 'High efficiency';
        } elseif ($this->optimal_value > 25) {
            return 'Moderate efficiency';
        } else {
            return 'Low efficiency';
        }
    }
}

function main() {
    $start = 1;
    $end = 100;
    $generator = new SequenceGenerator($start, $end);
    $sequence = $generator->generate_sequence();
    $model = new OptimizationModel($sequence);
    $optimal_value = $model->calculate_optimal_solution();
    $analyzer = new ResultAnalyzer($optimal_value);
    $result = $analyzer->analyze_result();
    echo $result;
}

main();

?>