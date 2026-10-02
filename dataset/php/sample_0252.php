<?php

class FrameTracker {
    public $sequence;
    public $threshold;
    public $index;

    function __construct($sequence, $threshold) {
        $this->sequence = $sequence;
        $this->threshold = $threshold;
        $this->index = 0;
    }

    function next_frame() {
        if ($this->index < count($this->sequence)) {
            $frame = $this->sequence[$this->index];
            $this->index += 1;
            return $frame;
        }
        return null;
    }

    function check_threshold($frame) {
        return $frame > $this->threshold;
    }
}

class SequenceAnalyzer {
    public $tracker;

    function __construct($tracker) {
        $this->tracker = $tracker;
    }

    function analyze() {
        while (true) {
            $frame = $this->tracker->next_frame();
            if ($frame === null) {
                break;
            }
            if ($this->tracker->check_threshold($frame)) {
                return true;
            }
        }
        return false;
    }
}

function main() {
    $sequence = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21];
    $threshold = 10;
    $tracker = new FrameTracker($sequence, $threshold);
    $analyzer = new SequenceAnalyzer($tracker);
    $result = $analyzer->analyze();
    echo $result;
}

main();