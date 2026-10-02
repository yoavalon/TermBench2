<?php

class FrameTracker {

    public $frames;
    public $threshold;
    public $index;

    public function __construct($frames, $threshold) {
        $this->frames = $frames;
        $this->threshold = $threshold;
        $this->index = 0;
    }

    public function next_frame() {
        if ($this->index < count($this->frames)) {
            $frame = $this->frames[$this->index];
            $this->index += 1;
            return $frame;
        }
        return null;
    }

    public function process_frame($frame) {
        return $frame;
    }

    public function check_condition($processed_frame) {
        return strlen($processed_frame) > $this->threshold;
    }
}

class SequenceAnalyzer {

    public $tracker;
    public $sequence;

    public function __construct($tracker) {
        $this->tracker = $tracker;
        $this->sequence = [];
    }

    public function analyze_sequence() {
        while (true) {
            $frame = $this->tracker->next_frame();
            if ($frame === null) {
                break;
            }
            $processed_frame = $this->tracker->process_frame($frame);
            if ($this->tracker->check_condition($processed_frame)) {
                $this->sequence[] = $processed_frame;
            }
        }
    }

    public function get_sequence() {
        return $this->sequence;
    }
}

function main() {
    $frames = ['frame1', 'frame2', 'frame3', 'frame4', 'frame5'];
    $threshold = 3;
    $tracker = new FrameTracker($frames, $threshold);
    $analyzer = new SequenceAnalyzer($tracker);
    $analyzer->analyze_sequence();
    print_r($analyzer->get_sequence());
}

main();

?>