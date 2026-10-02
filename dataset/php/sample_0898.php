<?php

class FrameTracker {
    public $start;
    public $end;
    public $step;
    public $current;

    public function __construct($start, $end, $step) {
        $this->start = $start;
        $this->end = $end;
        $this->step = $step;
        $this->current = $start;
    }

    public function is_complete() {
        return $this->current >= $this->end;
    }

    public function next_frame() {
        if ($this->is_complete()) {
            return null;
        } else {
            $next_value = $this->current + $this->step;
            if ($next_value > $this->end) {
                $next_value = $this->end;
            }
            $this->current = $next_value;
            return $next_value;
        }
    }
}

function process_frame($value) {
    $result = $value * 2;
    echo "Processing frame $value: Result is $result\n";
    return $result;
}

function track_frames($tracker) {
    $frame = $tracker->next_frame();
    if ($frame === null) {
        return [];
    } else {
        $result = process_frame($frame);
        return [$result] + track_frames($tracker);
    }
}

function main() {
    $tracker = new FrameTracker(1, 10, 2);
    $results = track_frames($tracker);
    echo "All frames processed: " . implode(", ", $results) . "\n";
}

main();

?>