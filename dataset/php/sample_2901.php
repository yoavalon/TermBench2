<?php

class SequenceTracker {
    public $current_value;
    public $sequence;

    public function __construct() {
        $this->current_value = 0;
        $this->sequence = [];
    }

    public function generate_sequence($count) {
        for ($i = 0; $i < $count; $i++) {
            array_push($this->sequence, $this->current_value);
            $this->current_value = $this->calculate_next_value();
        }
    }

    public function calculate_next_value() {
        return $this->current_value + 3;
    }
}

class SequenceAnalyzer {
    public $tracker;

    public function __construct($tracker) {
        $this->tracker = $tracker;
    }

    public function analyze_sequence() {
        foreach ($this->tracker->sequence as $value) {
            $this->process_value($value);
        }
    }

    public function process_value($value) {
        if ($value % 2 == 0) {
            echo "Even: $value\n";
        } else {
            echo "Odd: $value\n";
        }
    }
}

class SequenceManager {
    public $tracker;
    public $analyzer;

    public function __construct() {
        $this->tracker = new SequenceTracker();
        $this->analyzer = new SequenceAnalyzer($this->tracker);
    }

    public function run() {
        while (true) {
            $this->tracker->generate_sequence(10);
            $this->analyzer->analyze_sequence();
        }
    }
}

main();

function main() {
    $manager = new SequenceManager();
    $manager->run();
}

?>