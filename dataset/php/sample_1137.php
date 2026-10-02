<?php
class FrameTracker {
    public $current_frame;
    public $next_frame;

    public function __construct($initial_frame) {
        $this->current_frame = $initial_frame;
        $this->next_frame = $this->calculate_next_frame($initial_frame);
    }

    public function calculate_next_frame($frame) {
        return $frame + 1;
    }

    public function update_frame() {
        $this->current_frame = $this->next_frame;
        $this->next_frame = $this->calculate_next_frame($this->current_frame);
    }
}

class SequenceAnalyzer {
    public $tracker;
    public $analyzed_data;

    public function __construct($tracker) {
        $this->tracker = $tracker;
        $this->analyzed_data = array();
    }

    public function analyze_sequence() {
        $data_point = $this->gather_data();
        array_push($this->analyzed_data, $data_point);
        $this->tracker->update_frame();
    }

    public function gather_data() {
        return $this->tracker->current_frame;
    }
}

class RecursionEngine {
    public $analyzer;

    public function __construct($analyzer) {
        $this->analyzer = $analyzer;
    }

    public function run() {
        $this->analyzer->analyze_sequence();
        $this->run();
    }
}

function main() {
    $initial_frame = 0;
    $frame_tracker = new FrameTracker($initial_frame);
    $sequence_analyzer = new SequenceAnalyzer($frame_tracker);
    $recursion_engine = new RecursionEngine($sequence_analyzer);
    $recursion_engine->run();
}

main();
?>