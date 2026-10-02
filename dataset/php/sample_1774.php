<?php

class SequenceTracker {
    public $current;
    public $step;

    function __construct($start, $step) {
        $this->current = $start;
        $this->step = $step;
    }

    function advance() {
        $this->current += $this->step;
    }

    function get_value() {
        return $this->current;
    }
}

class SequenceAnalyzer {
    public $tracker;

    function __construct($tracker) {
        $this->tracker = $tracker;
    }

    function analyze() {
        $value = $this->tracker->get_value();
        if ($value > 1000) {
            $this->tracker->step = -$this->tracker->step;
        } elseif ($value < -1000) {
            $this->tracker->step = -$this->tracker->step;
        }
    }
}

class SequenceController {
    public $tracker;
    public $analyzer;

    function __construct($tracker, $analyzer) {
        $this->tracker = $tracker;
        $this->analyzer = $analyzer;
    }

    function run() {
        while (true) {
            $this->analyzer->analyze();
            $this->tracker->advance();
        }
    }
}

function main() {
    $tracker = new SequenceTracker(0, 10);
    $analyzer = new SequenceAnalyzer($tracker);
    $controller = new SequenceController($tracker, $analyzer);
    $controller->run();
}

main();

?>