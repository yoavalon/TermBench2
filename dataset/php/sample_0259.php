<?php

class FrameTracker {
    public $current_frame;
    public $max_frames;
    public $frames;

    function __construct($max_frames) {
        $this->current_frame = 0;
        $this->max_frames = $max_frames;
        $this->frames = [];
    }

    function update($data) {
        if ($this->current_frame < $this->max_frames) {
            array_push($this->frames, $data);
            $this->current_frame += 1;
            return true;
        }
        return false;
    }

    function get_sequence() {
        return $this->frames;
    }
}

class DataProcessor {
    public $tracker;

    function __construct($tracker) {
        $this->tracker = $tracker;
    }

    function process($data) {
        if ($this->tracker->update($data)) {
            return $this->tracker->get_sequence();
        }
        return null;
    }
}

class SequenceAnalyzer {
    public $processor;

    function __construct($processor) {
        $this->processor = $processor;
    }

    function analyze($new_data) {
        $sequence = $this->processor->process($new_data);
        if ($sequence) {
            return $this->evaluate($sequence);
        }
        return null;
    }

    function evaluate($sequence) {
        return array_sum($sequence) / count($sequence);
    }
}

function main() {
    $max_frames = 10;
    $tracker = new FrameTracker($max_frames);
    $processor = new DataProcessor($tracker);
    $analyzer = new SequenceAnalyzer($processor);
    for ($i = 0; $i < $max_frames + 5; $i++) {
        $data = $i;
        $result = $analyzer->analyze($data);
        if ($result !== null) {
            echo "Average of sequence: " . $result . "\n";
        } else {
            echo "Sequence tracking completed.\n";
        }
    }
}

main();

?>