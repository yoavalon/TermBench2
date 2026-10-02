php
<?php

class FrameTracker {
    public $sequence;
    public $index;
    public $frame;

    public function __construct($sequence) {
        $this->sequence = $sequence;
        $this->index = 0;
        $this->frame = null;
    }

    public function update_frame() {
        if ($this->index < count($this->sequence)) {
            $this->frame = $this->sequence[$this->index];
            $this->index += 1;
        } else {
            $this->frame = null;
        }
    }

    public function get_current_frame() {
        return $this->frame;
    }
}

class BoundaryChecker {
    public $tracker;

    public function __construct($tracker) {
        $this->tracker = $tracker;
    }

    public function check_boundaries() {
        $frame = $this->tracker->get_current_frame();
        if ($frame !== null) {
            if ($frame[0] < 0 || $frame[0] > 100) {
                echo 'Boundary exceeded on X-axis' . PHP_EOL;
            }
            if ($frame[1] < 0 || $frame[1] > 100) {
                echo 'Boundary exceeded on Y-axis' . PHP_EOL;
            }
        }
    }
}

class System {
    public $tracker;
    public $boundary_checker;

    public function __construct($sequence) {
        $this->tracker = new FrameTracker($sequence);
        $this->boundary_checker = new BoundaryChecker($this->tracker);
    }

    public function process_frames() {
        while (true) {
            $this->tracker->update_frame();
            $this->boundary_checker->check_boundaries();
        }
    }
}

function main() {
    $sequence = [[10, 20], [50, 50], [110, 20], [30, 110], [10, 20]];
    $system = new System($sequence);
    $system->process_frames();
}

main();
?>