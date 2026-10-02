<?php

class SequenceGenerator {
    public $current;
    public $end;
    public $step;

    function __construct($start, $end, $step) {
        $this->current = $start;
        $this->end = $end;
        $this->step = $step;
    }

    function generate() {
        $sequence = [];
        while ($this->current <= $this->end) {
            $sequence[] = $this->current;
            $this->current += $this->step;
        }
        return $sequence;
    }
}

class FrameTracker {
    public $sequence;
    public $index;

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->index = 0;
    }

    function next_frame() {
        if ($this->index < count($this->sequence)) {
            $value = $this->sequence[$this->index];
            $this->index += 1;
            return $value;
        }
        return null;
    }
}

class TemporalAnalysis {
    public $tracker;

    function __construct($tracker) {
        $this->tracker = $tracker;
    }

    function analyze() {
        $result = [];
        while (true) {
            $frame = $this->tracker->next_frame();
            if ($frame === null) {
                break;
            }
            $result[] = $frame;
        }
        return $result;
    }
}

function main() {
    $start = 1;
    $end = 100;
    $step = 5;
    $generator = new SequenceGenerator($start, $end, $step);
    $sequence = $generator->generate();
    $tracker = new FrameTracker($sequence);
    $analysis = new TemporalAnalysis($tracker);
    $result = $analysis->analyze();
    print_r($result);
}

main();

?>