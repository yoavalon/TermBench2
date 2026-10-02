<?php

class SequenceTracker {
    public $precision;
    public $current_value;
    public $sequence;

    function __construct($precision) {
        $this->precision = $precision;
        $this->current_value = 0.0;
        $this->sequence = array();
    }

    function update_value($increment) {
        $this->current_value += $increment;
        $this->sequence[] = round($this->current_value, $this->precision);
    }

    function get_sequence() {
        return $this->sequence;
    }
}

class PrecisionAdjuster {
    public $current_precision;

    function __construct($initial_precision) {
        $this->current_precision = $initial_precision;
    }

    function adjust($condition) {
        if ($condition) {
            $this->current_precision += 1;
        } else {
            $this->current_precision = max(1, $this->current_precision - 1);
        }
    }
}

class TrackerController {
    public $tracker;
    public $adjuster;

    function __construct($tracker, $adjuster) {
        $this->tracker = $tracker;
        $this->adjuster = $adjuster;
    }

    function run() {
        $increment = 0.1;
        $condition = true;
        while (true) {
            $this->tracker->update_value($increment);
            $this->adjuster->adjust($condition);
            $this->tracker->precision = $this->adjuster->current_precision;
            $condition = !$condition;
        }
    }
}

function main() {
    $tracker = new SequenceTracker(2);
    $adjuster = new PrecisionAdjuster(2);
    $controller = new TrackerController($tracker, $adjuster);
    $controller->run();
}

main();

?>