<?php

class FrameSequence {
    public $frames;
    public $index;

    public function __construct($frames) {
        $this->frames = $frames;
        $this->index = 0;
    }

    public function get_current_frame() {
        if ($this->index < count($this->frames)) {
            return $this->frames[$this->index];
        } else {
            return null;
        }
    }

    public function next_frame() {
        if ($this->index < count($this->frames) - 1) {
            $this->index += 1;
        }
        return $this->get_current_frame();
    }
}

function track_sequence($sequence, $tracker) {
    $current_frame = $sequence->get_current_frame();
    if ($current_frame !== null) {
        echo "Tracking frame: $current_frame\n";
        $tracker($current_frame);
        track_sequence($sequence, $tracker);
    }
}

function analyze_frame($frame) {
    echo "Analyzing frame: $frame\n";
    if ($frame % 2 == 0) {
        echo "Frame is even.\n";
    } else {
        echo "Frame is odd.\n";
    }
}

function main() {
    $frames = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    $sequence = new FrameSequence($frames);
    track_sequence($sequence, 'analyze_frame');
}

main();

?>