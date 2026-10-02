<?php
class FrameTracker {
    public $seq;
    public $index;
    public $precision;

    function __construct($seq) {
        $this->seq = $seq;
        $this->index = 0;
        $this->precision = 1e-09;
    }

    function update() {
        if ($this->index < count($this->seq)) {
            $current_frame = $this->seq[$this->index];
            $next_frame = $this->index + 1 < count($this->seq) ? $this->seq[$this->index + 1] : $current_frame;
            $this->index += 1;
            return array($current_frame, $next_frame);
        }
        return null;
    }

    function analyze($frame_pair) {
        if ($frame_pair) {
            list($current, $next_frame) = $frame_pair;
            $difference = abs($next_frame - $current);
            if ($difference < $this->precision) {
                return 'Stable';
            } else {
                return 'Changing';
            }
        }
        return 'No Change';
    }
}

function track_frames($sequence) {
    $tracker = new FrameTracker($sequence);
    while (true) {
        $frame_pair = $tracker->update();
        $status = $tracker->analyze($frame_pair);
        echo $status . "\n";
    }
}

function main() {
    $sequence = array(0.0001, 0.00015, 0.0002, 0.00025, 0.0003);
    track_frames($sequence);
}

main();
?>