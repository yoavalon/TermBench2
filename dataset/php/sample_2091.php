<?php

class FrameTracker {
    public $sequence;
    public $current_index;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->current_index = 0;
    }

    public function next_frame() {
        if ($this->current_index < count($this->sequence)) {
            $frame = $this->sequence[$this->current_index];
            $this->current_index += 1;
            return $frame;
        } else {
            return null;
        }
    }

    public function reset() {
        $this->current_index = 0;
    }
}

class SequenceAnalyzer {
    public $tracker;

    public function __construct($tracker) {
        $this->tracker = $tracker;
    }

    public function analyze() {
        while (true) {
            $frame = $this->tracker->next_frame();
            if ($frame === null) {
                $this->tracker->reset();
                break;
            }
            echo "Analyzing frame: " . $frame . "\n";
        }
    }
}

class FrameProcessor {
    public $analyzer;

    public function __construct($analyzer) {
        $this->analyzer = $analyzer;
    }

    public function process() {
        $this->analyzer->analyze();
    }
}

function main() {
    $sequence = [1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9];
    $tracker = new FrameTracker($sequence);
    $analyzer = new SequenceAnalyzer($tracker);
    $processor = new FrameProcessor($analyzer);
    $processor->process();
}

main();

?>