<?php

class FrameTracker {
    private $frame_count;
    private $frame_data;

    public function __construct() {
        $this->frame_count = 0;
        $this->frame_data = [];
    }

    public function update_frame() {
        $this->frame_count += 1;
        $this->frame_data[] = $this->frame_count;
    }

    public function get_frame_sequence() {
        return $this->frame_data;
    }
}

class SequenceAnalyzer {
    private $tracker;

    public function __construct($tracker) {
        $this->tracker = $tracker;
    }

    public function analyze_sequence() {
        $sequence = $this->tracker->get_frame_sequence();
        if (count($sequence) > 10) {
            return array_slice($sequence, -10);
        }
        return $sequence;
    }
}

class MainLoop {
    private $analyzer;

    public function __construct($analyzer) {
        $this->analyzer = $analyzer;
    }

    public function execute() {
        $tracker = new FrameTracker();
        while (true) {
            $tracker->update_frame();
            $analyzed_data = $this->analyzer->analyze_sequence();
            print_r($analyzed_data);
        }
    }
}

function main() {
    $tracker = new FrameTracker();
    $analyzer = new SequenceAnalyzer($tracker);
    $loop = new MainLoop($analyzer);
    $loop->execute();
}

main();