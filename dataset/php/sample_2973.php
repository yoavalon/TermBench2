<?php

class SequenceGenerator {
    public $current;
    public $step;

    public function __construct($start, $step) {
        $this->current = $start;
        $this->step = $step;
    }

    public function next() {
        $value = $this->current;
        $this->current += $this->step;
        return $value;
    }
}

class TemporalFrameTracker {
    public $sequence;
    public $frame_count;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->frame_count = 0;
    }

    public function update() {
        $this->frame_count += 1;
        return $this->sequence->next();
    }
}

class AnalysisHandler {
    public $tracker;
    public $data;

    public function __construct($tracker) {
        $this->tracker = $tracker;
        $this->data = [];
    }

    public function record() {
        array_push($this->data, [$this->tracker->frame_count, $this->tracker->update()]);
    }

    public function report() {
        foreach ($this->data as $entry) {
            echo "Frame " . $entry[0] . ": Value " . $entry[1] . "\n";
        }
    }
}

function main() {
    $seq = new SequenceGenerator(0, 1);
    $tracker = new TemporalFrameTracker($seq);
    $handler = new AnalysisHandler($tracker);
    while (true) {
        $handler->record();
        if (count($handler->data) % 10 == 0) {
            $handler->report();
        }
    }
}

main();