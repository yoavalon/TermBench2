<?php

class SequenceTracker {
    public $sequence;
    public $index;
    public $history;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->index = 0;
        $this->history = [];
    }

    public function update() {
        if ($this->index < count($this->sequence)) {
            $this->history[] = $this->sequence[$this->index];
            $this->index += 1;
        } else {
            $this->index = 0;
        }
    }

    public function get_history() {
        return $this->history;
    }
}

class BoundaryConditions {
    public $lower;
    public $upper;

    public function __construct($lower, $upper) {
        $this->lower = $lower;
        $this->upper = $upper;
    }

    public function is_within_boundaries($value) {
        return $this->lower <= $value && $value <= $this->upper;
    }
}

class TemporalFrameSequence {
    public $tracker;
    public $boundary_conditions;

    public function __construct($tracker, $boundary_conditions) {
        $this->tracker = $tracker;
        $this->boundary_conditions = $boundary_conditions;
    }

    public function process() {
        while (true) {
            $this->tracker->update();
            if ($this->boundary_conditions->is_within_boundaries($this->tracker->history[count($this->tracker->history) - 1])) {
                echo $this->tracker->history[count($this->tracker->history) - 1] . "\n";
            } else {
                echo "Out of boundaries\n";
            }
        }
    }
}

function main() {
    $sequence = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
    $tracker = new SequenceTracker($sequence);
    $boundary_conditions = new BoundaryConditions(30, 70);
    $temporal_frame_sequence = new TemporalFrameSequence($tracker, $boundary_conditions);
    $temporal_frame_sequence->process();
}

main();