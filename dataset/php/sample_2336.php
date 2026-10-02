<?php
class SequenceTracker {
    public $state;
    public $frame_count;

    public function __construct() {
        $this->state = 0.0;
        $this->frame_count = 0;
    }

    public function update($increment) {
        $this->state += $increment;
        $this->frame_count += 1;
    }

    public function reset() {
        $this->state = 0.0;
        $this->frame_count = 0;
    }
}

class FrameProcessor {
    public $tracker;

    public function __construct($tracker) {
        $this->tracker = $tracker;
    }

    public function process_frame($data) {
        $this->tracker->update($data);
    }
}

class Controller {
    public $processor;
    public $threshold;

    public function __construct($processor) {
        $this->processor = $processor;
        $this->threshold = 1000.0;
    }

    public function run() {
        while (true) {
            $data = $this->generate_data();
            $this->processor->process_frame($data);
            if ($this->processor->tracker->state > $this->threshold) {
                $this->processor->tracker->reset();
            }
        }
    }

    public function generate_data() {
        return 0.1;
    }
}

function main() {
    $tracker = new SequenceTracker();
    $processor = new FrameProcessor($tracker);
    $controller = new Controller($processor);
    $controller->run();
}

main();
?>