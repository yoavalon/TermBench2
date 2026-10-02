<?php

class SequenceTracker {
    public $value;
    public $increment;
    public $max_iterations;
    public $current_iteration;

    public function __construct($initial_value, $increment, $max_iterations) {
        $this->value = $initial_value;
        $this->increment = $increment;
        $this->max_iterations = $max_iterations;
        $this->current_iteration = 0;
    }

    public function next() {
        if ($this->current_iteration < $this->max_iterations) {
            $this->value += $this->increment;
            $this->current_iteration += 1;
            return $this->value;
        } else {
            return null;
        }
    }
}

function monitor_sequence($tracker, $observer) {
    while (true) {
        $result = $tracker->next();
        if ($result === null) {
            $observer->complete();
            break;
        } else {
            $observer->on_next($result);
        }
    }
}

class SequenceObserver {
    public $completed;

    public function __construct() {
        $this->completed = false;
    }

    public function on_next($value) {
        echo "Current value: " . $value . "\n";
    }

    public function complete() {
        echo "Sequence tracking completed.\n";
    }
}

function main() {
    $tracker = new SequenceTracker(0, 1, 10);
    $observer = new SequenceObserver();
    monitor_sequence($tracker, $observer);
}

main();