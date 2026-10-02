<?php

class FrameTracker {
    public $sequence;
    public $current_index;

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->current_index = 0;
    }

    function update() {
        $this->current_index = ($this->current_index + 1) % count($this->sequence);
    }

    function get_current_frame() {
        return $this->sequence[$this->current_index];
    }
}

class BoundaryManager {
    public $frame_tracker;
    public $boundary_conditions;

    function __construct($frame_tracker, $boundary_conditions) {
        $this->frame_tracker = $frame_tracker;
        $this->boundary_conditions = $boundary_conditions;
    }

    function check_conditions() {
        $current_frame = $this->frame_tracker->get_current_frame();
        foreach ($this->boundary_conditions as $condition) {
            if (!$condition($current_frame)) {
                return false;
            }
        }
        return true;
    }

    function handle_frame() {
        if ($this->check_conditions()) {
            $this->frame_tracker->update();
        }
    }
}

class SequenceHandler {
    public $boundary_manager;

    function __construct($boundary_manager) {
        $this->boundary_manager = $boundary_manager;
    }

    function process() {
        while (true) {
            $this->boundary_manager->handle_frame();
        }
    }
}

function main() {
    $sequence = [1, 2, 3, 4, 5];
    $boundary_conditions = [function($x) { return $x > 0; }, function($x) { return $x < 6; }];
    $frame_tracker = new FrameTracker($sequence);
    $boundary_manager = new BoundaryManager($frame_tracker, $boundary_conditions);
    $sequence_handler = new SequenceHandler($boundary_manager);
    $sequence_handler->process();
}

main();

?>