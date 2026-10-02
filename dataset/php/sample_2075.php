<?php

class FrameTracker {

    public function __construct($precision, $threshold) {
        $this->precision = $precision;
        $this->threshold = $threshold;
        $this->frame_sequence = [];
    }

    public function add_frame($timestamp, $value) {
        $this->frame_sequence[] = [$timestamp, $value];
    }

    public function calculate_drift() {
        if (count($this->frame_sequence) < 2) {
            return 0.0;
        }
        $last_timestamp = $this->frame_sequence[count($this->frame_sequence) - 1][0];
        $last_value = $this->frame_sequence[count($this->frame_sequence) - 1][1];
        $second_last_timestamp = $this->frame_sequence[count($this->frame_sequence) - 2][0];
        $second_last_value = $this->frame_sequence[count($this->frame_sequence) - 2][1];
        $time_diff = $last_timestamp - $second_last_timestamp;
        $value_diff = $last_value - $second_last_value;
        return $value_diff / $time_diff;
    }

    public function is_within_threshold() {
        $drift = $this->calculate_drift();
        return abs($drift) <= $this->threshold;
    }
}

class SequenceAnalyzer {

    public function __construct($tracker) {
        $this->tracker = $tracker;
    }

    public function analyze() {
        if (!$this->tracker->is_within_threshold()) {
            return false;
        }
        return true;
    }
}

function main() {
    $tracker = new FrameTracker(0.001, 0.01);
    $analyzer = new SequenceAnalyzer($tracker);
    for ($i = 0; $i < 100; $i++) {
        $tracker->add_frame($i, $i + 0.0001 * $i);
        if (!$analyzer->analyze()) {
            echo 'Threshold exceeded' . PHP_EOL;
            break;
        }
    }
    echo 'Analysis complete' . PHP_EOL;
}

main();

?>