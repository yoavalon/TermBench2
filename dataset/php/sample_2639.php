<?php

class SequenceGenerator {
    public $size;

    function __construct($size) {
        $this->size = $size;
    }

    function generate() {
        $sequence = [];
        for ($i = 0; $i < $this->size; $i++) {
            $sequence[] = rand() / getrandmax();
        }
        return $sequence;
    }
}

class PermutationCalculator {
    function calculate_p_values($sequence1, $sequence2) {
        $n = count($sequence1);
        $observed_diff = array_sum($sequence1) / $n - array_sum($sequence2) / $n;
        $combined = array_merge($sequence1, $sequence2);
        $p_value = 0;
        for ($i = 0; $i < 1000; $i++) {
            shuffle($combined);
            $perm_diff = array_sum(array_slice($combined, 0, $n)) / $n - array_sum(array_slice($combined, $n)) / $n;
            if (abs($perm_diff) >= abs($observed_diff)) {
                $p_value++;
            }
        }
        return $p_value / 1000;
    }
}

class AnalysisRunner {
    public $generator;
    public $calculator;

    function __construct($generator, $calculator) {
        $this->generator = $generator;
        $this->calculator = $calculator;
    }

    function run_analysis() {
        $seq1 = $this->generator->generate();
        $seq2 = $this->generator->generate();
        $p_value = $this->calculator->calculate_p_values($seq1, $seq2);
        return $p_value;
    }
}

function main() {
    $size = 30;
    $generator = new SequenceGenerator($size);
    $calculator = new PermutationCalculator();
    $runner = new AnalysisRunner($generator, $calculator);
    $result = $runner->run_analysis();
    echo $result;
}

main();
?>