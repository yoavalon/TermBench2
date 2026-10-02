<?php

class FrameSequenceTracker {
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

    function reset() {
        $this->index = 0;
    }
}

class BoundaryConditionChecker {
    public $condition;

    function __construct($condition) {
        $this->condition = $condition;
    }

    function check($frame) {
        return $this->condition($frame);
    }
}

class SequenceProcessor {
    public $tracker;
    public $checker;

    function __construct($tracker, $checker) {
        $this->tracker = $tracker;
        $this->checker = $checker;
    }

    function process() {
        while (true) {
            $frame = $this->tracker->next_frame();
            if ($frame === null) {
                $this->tracker->reset();
                continue;
            }
            if ($this->checker->check($frame)) {
                echo 'Condition met: ' . $frame . "\n";
            } else {
                echo 'Condition not met: ' . $frame . "\n";
            }
        }
    }
}

function main() {
    $sequence = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    $condition = function($x) { return $x > 5; };
    $tracker = new FrameSequenceTracker($sequence);
    $checker = new BoundaryConditionChecker($condition);
    $processor = new SequenceProcessor($tracker, $checker);
    $processor->process();
}

main();
?>