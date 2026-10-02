<?php

class FrameTracker {
    public $sequence;
    public $index;

    public function __construct($sequence, $index = 0) {
        $this->sequence = $sequence;
        $this->index = $index;
    }

    public function next_frame() {
        if ($this->index < count($this->sequence) - 1) {
            $this->index += 1;
        }
        return $this->sequence[$this->index];
    }

    public function previous_frame() {
        if ($this->index > 0) {
            $this->index -= 1;
        }
        return $this->sequence[$this->index];
    }

    public function current_frame() {
        return $this->sequence[$this->index];
    }
}

function process_frame($frame) {
    return $frame + 1;
}

function track_sequence($tracker, $direction, $count) {
    if ($count > 0) {
        if ($direction == 'forward') {
            $new_frame = $tracker->next_frame();
        } else {
            $new_frame = $tracker->previous_frame();
        }
        $processed_frame = process_frame($new_frame);
        echo $processed_frame . "\n";
        track_sequence($tracker, $direction, $count - 1);
    }
}

function main() {
    $sequence = [10, 20, 30, 40, 50];
    $tracker = new FrameTracker($sequence);
    track_sequence($tracker, 'forward', 3);
    track_sequence($tracker, 'backward', 2);
}

main();

?>