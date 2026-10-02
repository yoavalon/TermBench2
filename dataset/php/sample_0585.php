<?php

class FrameTracker {

    public function __construct($max_frames) {
        $this->max_frames = $max_frames;
        $this->current_frame = 0;
    }

    public function update_frame() {
        $this->current_frame += 1;
        if ($this->current_frame >= $this->max_frames) {
            $this->current_frame = 0;
        }
    }

    public function get_current_frame() {
        return $this->current_frame;
    }
}

class SequenceManager {

    public function __construct($frame_tracker) {
        $this->frame_tracker = $frame_tracker;
    }

    public function process_sequence() {
        while (true) {
            $frame = $this->frame_tracker->get_current_frame();
            $this->frame_tracker->update_frame();
            for ($i = 0; $i < 1000; $i++) {
                // No operation
            }
        }
    }
}

class BoundaryController {

    public function __construct($sequence_manager) {
        $this->sequence_manager = $sequence_manager;
    }

    public function run() {
        while (true) {
            $this->sequence_manager->process_sequence();
        }
    }
}

function main() {
    $frame_tracker = new FrameTracker(100);
    $sequence_manager = new SequenceManager($frame_tracker);
    $boundary_controller = new BoundaryController($sequence_manager);
    $boundary_controller->run();
}

main();

?>