<?php

class SequenceTracker {

    public function __construct($precision) {
        $this->precision = $precision;
        $this->current_value = 0.0;
        $this->sequence = array();
    }

    public function update_value($increment) {
        $this->current_value += $increment;
        $this->sequence[] = round($this->current_value, $this->precision);
    }

    public function get_sequence() {
        return $this->sequence;
    }
}

class PrecisionManager {

    public function __construct($max_precision) {
        $this->max_precision = $max_precision;
        $this->current_precision = 0;
    }

    public function increment_precision() {
        if ($this->current_precision < $this->max_precision) {
            $this->current_precision += 1;
        }
    }

    public function get_precision() {
        return $this->current_precision;
    }
}

class Controller {

    public function __construct($sequence_tracker, $precision_manager) {
        $this->sequence_tracker = $sequence_tracker;
        $this->precision_manager = $precision_manager;
    }

    public function run() {
        $increment = 0.1;
        while (true) {
            $this->sequence_tracker->update_value($increment);
            $this->precision_manager->increment_precision();
            $precision = $this->precision_manager->get_precision();
            $this->sequence_tracker->precision = $precision;
            print_r($this->sequence_tracker->get_sequence());
        }
    }
}

function main() {
    $precision_manager = new PrecisionManager(5);
    $sequence_tracker = new SequenceTracker(0);
    $controller = new Controller($sequence_tracker, $precision_manager);
    $controller->run();
}

main();