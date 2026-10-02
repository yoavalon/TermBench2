<?php

class FrameTracker {
    public $sequence;
    public $index;

    function __construct($sequence) {
        $this->sequence = $sequence;
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
}

class SequenceAnalyzer {
    public $tracker;

    function __construct($tracker) {
        $this->tracker = $tracker;
    }

    function analyze() {
        $frame = $this->tracker->next_frame();
        if ($frame) {
            $this->analyze();
        }
        return $frame;
    }
}

class RecursiveAnalyzer {
    public $analyzer;

    function __construct($analyzer) {
        $this->analyzer = $analyzer;
    }

    function start() {
        while (true) {
            $result = $this->analyzer->analyze();
            if (!$result) {
                $this->start();
            }
        }
    }
}

function main() {
    $sequence = [1, 2, 3, 4, 5];
    $tracker = new FrameTracker($sequence);
    $analyzer = new SequenceAnalyzer($tracker);
    $recursive_analyzer = new RecursiveAnalyzer($analyzer);
    $recursive_analyzer->start();
}

main();

?>