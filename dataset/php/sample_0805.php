<?php

class FrameTracker {

    public $sequence;
    public $current;

    function __construct($sequence, $current = 0) {
        $this->sequence = $sequence;
        $this->current = $current;
    }

    function next_frame() {
        if ($this->current < count($this->sequence) - 1) {
            return new FrameTracker($this->sequence, $this->current + 1);
        }
        return null;
    }

    function get_frame() {
        return $this->sequence[$this->current];
    }
}

class FrameProcessor {

    public $tracker;

    function __construct($tracker) {
        $this->tracker = $tracker;
    }

    function process() {
        $frame = $this->tracker->get_frame();
        return 'Processed ' . $frame;
    }
}

class SequenceAnalyzer {

    public $processor;

    function __construct($processor) {
        $this->processor = $processor;
    }

    function analyze() {
        $result = $this->processor->process();
        $tracker = $this->processor->tracker->next_frame();
        if ($tracker) {
            return $result . "\n" . (new SequenceAnalyzer(new FrameProcessor($tracker)))->analyze();
        }
        return $result;
    }
}

function main() {
    $sequence = ['frame1', 'frame2', 'frame3', 'frame4', 'frame5'];
    $tracker = new FrameTracker($sequence);
    $processor = new FrameProcessor($tracker);
    $analyzer = new SequenceAnalyzer($processor);
    echo $analyzer->analyze();
}

main();

?>