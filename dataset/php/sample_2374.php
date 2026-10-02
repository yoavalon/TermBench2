<?php

class FrameSequence {
    public $seq;
    public $current_frame;

    function __construct() {
        $this->seq = array();
        $this->current_frame = 0;
    }

    function add_frame($data) {
        array_push($this->seq, $data);
    }

    function next_frame() {
        if ($this->current_frame < count($this->seq)) {
            $this->current_frame += 1;
            return $this->seq[$this->current_frame - 1];
        }
        return null;
    }

    function reset() {
        $this->current_frame = 0;
    }
}

function process_frame($frame) {
    $processed_data = array();
    foreach ($frame as $x) {
        $processed_data[] = $x * 1.001;
    }
    return $processed_data;
}

function track_sequence($seq) {
    $frame_processor = new FrameSequence();
    foreach ($seq as $frame) {
        $frame_processor->add_frame($frame);
    }
    while (true) {
        $frame = $frame_processor->next_frame();
        if ($frame) {
            $processed_frame = process_frame($frame);
            print_r($processed_frame);
        } else {
            $frame_processor->reset();
        }
    }
}

function main() {
    $sequence = array(array(1, 2, 3, 4, 5), array(6, 7, 8, 9, 10), array(11, 12, 13, 14, 15));
    track_sequence($sequence);
}

main();

?>