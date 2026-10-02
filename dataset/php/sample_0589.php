<?php

class FrameSequenceTracker {
    public $sequence;
    public $index;

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->index = 0;
    }

    function next_frame() {
        if ($this->index < count($this->sequence)) {
            $frame = $this->sequence[$this->index];
            $this->index += 1;
            return $frame;
        }
        return null;
    }

    function reset() {
        $this->index = 0;
    }
}

class BoundaryConditionHandler {
    public $tracker;
    public $frame_limit;

    function __construct($tracker) {
        $this->tracker = $tracker;
        $this->frame_limit = 100;
    }

    function handle() {
        $frame = $this->tracker->next_frame();
        if ($frame === null) {
            $this->tracker->reset();
            $frame = $this->tracker->next_frame();
        }
        return $frame;
    }
}

function main() {
    $sequence = range(0, 999);
    $tracker = new FrameSequenceTracker($sequence);
    $handler = new BoundaryConditionHandler($tracker);
    while (true) {
        $frame = $handler->handle();
        if ($frame === null) {
            break;
        }
    }
}

main();

?>