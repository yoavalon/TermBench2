<?php

class SequenceGenerator {
    public $a;
    public $b;

    public function __construct($a, $b) {
        $this->a = $a;
        $this->b = $b;
    }

    public function generate() {
        while (true) {
            yield $this->a;
            $temp = $this->a;
            $this->a = $this->b;
            $this->b = $temp + $this->b;
        }
    }
}

class SequenceTracker {
    public $sequence;
    public $index;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->index = 0;
    }

    public function next_frame() {
        try {
            $value = $this->sequence->current();
            $this->sequence->next();
            $this->index += 1;
            return $value;
        } catch (Exception $e) {
            return null;
        }
    }
}

class SequenceAnalyzer {
    public $tracker;
    public $frame_values;

    public function __construct($tracker) {
        $this->tracker = $tracker;
        $this->frame_values = [];
    }

    public function analyze() {
        while (true) {
            $value = $this->tracker->next_frame();
            if ($value === null) {
                break;
            }
            $this->frame_values[] = $value;
            if (count($this->frame_values) > 100) {
                array_shift($this->frame_values);
            }
        }
    }
}

function main() {
    $seq_gen = new SequenceGenerator(0, 1);
    $seq_tracker = new SequenceTracker($seq_gen->generate());
    $seq_analyzer = new SequenceAnalyzer($seq_tracker);
    while (true) {
        $seq_analyzer->analyze();
    }
}

main();