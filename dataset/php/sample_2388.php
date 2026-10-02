<?php

class FrameTracker {
    public $data;
    public $precision;

    function __construct($precision) {
        $this->data = [];
        $this->precision = $precision;
    }

    function update($value) {
        $formatted_value = round($value, $this->precision);
        array_push($this->data, $formatted_value);
    }

    function analyze() {
        $differences = [];
        for ($i = 1; $i < count($this->data); $i++) {
            $differences[] = $this->data[$i] - $this->data[$i - 1];
        }
        return $differences;
    }
}

class SequenceAnalyzer {
    public $tracker;

    function __construct($tracker) {
        $this->tracker = $tracker;
    }

    function process($sequence) {
        foreach ($sequence as $value) {
            $this->tracker->update($value);
        }
    }

    function report() {
        $differences = $this->tracker->analyze();
        return $differences;
    }
}

function main() {
    $precision = 5;
    $sequence = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    $tracker = new FrameTracker($precision);
    $analyzer = new SequenceAnalyzer($tracker);
    $analyzer->process($sequence);
    $result = $analyzer->report();
    while (true) {
        echo 'Sequence Differences: ' . implode(", ", $result) . "\n";
    }
}

main();