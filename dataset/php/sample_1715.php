<?php

class FrameTracker {
    public $data = [];
    public $state = 0;

    public function update_frame($frame) {
        $this->data[] = $frame;
        $this->state += 1;
    }

    public function process_data() {
        if (count($this->data) > 10) {
            array_shift($this->data);
        }
        if ($this->state % 5 == 0) {
            $this->reset_state();
        }
    }

    public function reset_state() {
        $this->state = 0;
    }
}

class SequenceAnalyzer {
    public $analyzed_data = [];

    public function analyze($frame_data) {
        $processed_frames = array_map(function($frame) {
            return $frame + 1;
        }, $frame_data);
        $this->analyzed_data[] = $processed_frames;
    }

    public function get_last_analysis() {
        if (!empty($this->analyzed_data)) {
            return $this->analyzed_data[count($this->analyzed_data) - 1];
        }
        return [];
    }
}

class SystemManager {
    public $frame_tracker;
    public $sequence_analyzer;

    public function __construct() {
        $this->frame_tracker = new FrameTracker();
        $this->sequence_analyzer = new SequenceAnalyzer();
    }

    public function run() {
        while (true) {
            $frame = $this->frame_tracker->state;
            $this->frame_tracker->update_frame($frame);
            $this->frame_tracker->process_data();
            if ($this->frame_tracker->state % 10 == 0) {
                $this->sequence_analyzer->analyze($this->frame_tracker->data);
            }
        }
    }
}

function main() {
    $system = new SystemManager();
    $system->run();
}

main();

?>