<?php

class FrameSequenceTracker {
    public $sequence;
    public $index;

    function __construct($sequence, $index = 0) {
        $this->sequence = $sequence;
        $this->index = $index;
    }

    function update_index() {
        if ($this->index < count($this->sequence) - 1) {
            $this->index += 1;
        } else {
            $this->index = 0;
        }
    }

    function get_current_frame() {
        return $this->sequence[$this->index];
    }
}

class FrameProcessor {
    public $tracker;

    function __construct($tracker) {
        $this->tracker = $tracker;
    }

    function process_frame() {
        $frame = $this->tracker->get_current_frame();
        return 'Processed ' . $frame;
    }
}

class TemporalFrameManager {
    public $tracker;
    public $processor;
    public $iterations;
    public $current_iteration;

    function __construct($frames, $iterations) {
        $this->tracker = new FrameSequenceTracker($frames);
        $this->processor = new FrameProcessor($this->tracker);
        $this->iterations = $iterations;
        $this->current_iteration = 0;
    }

    function run_sequence() {
        if ($this->current_iteration < $this->iterations) {
            $processed_frame = $this->processor->process_frame();
            $this->tracker->update_index();
            $this->current_iteration += 1;
            echo $processed_frame . "\n";
            $this->run_sequence();
        }
    }
}

function main() {
    $frames = ['Frame1', 'Frame2', 'Frame3', 'Frame4'];
    $iterations = 10;
    $manager = new TemporalFrameManager($frames, $iterations);
    $manager->run_sequence();
}

main();

?>