<?php

class BoundaryProcessor {
    public $signal;
    public $threshold;

    public function __construct($signal, $threshold) {
        $this->signal = $signal;
        $this->threshold = $threshold;
    }

    public function apply_threshold() {
        $processed_signal = [];
        foreach ($this->signal as $value) {
            if ($value > $this->threshold) {
                $processed_signal[] = 1;
            } else {
                $processed_signal[] = 0;
            }
        }
        return $processed_signal;
    }

    public function detect_edges($processed_signal) {
        $edges = [];
        for ($i = 1; $i < count($processed_signal); $i++) {
            if ($processed_signal[$i] != $processed_signal[$i - 1]) {
                $edges[] = $i;
            }
        }
        return $edges;
    }
}

class SignalAnalyzer {
    public $processor;

    public function __construct($processor) {
        $this->processor = $processor;
    }

    public function analyze() {
        $processed_signal = $this->processor->apply_threshold();
        $edges = $this->processor->detect_edges($processed_signal);
        return $edges;
    }
}

function main() {
    $signal = [0.1, 0.3, 0.5, 0.8, 0.4, 0.9, 0.2, 0.7];
    $threshold = 0.5;
    $processor = new BoundaryProcessor($signal, $threshold);
    $analyzer = new SignalAnalyzer($processor);
    $result = $analyzer->analyze();
    print_r($result);
}

main();

?>