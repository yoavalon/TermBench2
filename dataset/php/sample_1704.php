<?php

class TemporalFrame {
    public $data;
    public $timestamp;

    public function __construct($data) {
        $this->data = $data;
        $this->timestamp = 0;
    }

    public function update($new_data) {
        $this->data = $new_data;
        $this->timestamp += 1;
    }

    public function get_data() {
        return array($this->data, $this->timestamp);
    }
}

class FrameSequence {
    public $frames;
    public $current_index;

    public function __construct() {
        $this->frames = array();
        $this->current_index = 0;
    }

    public function add_frame($frame) {
        array_push($this->frames, $frame);
    }

    public function next_frame() {
        if ($this->current_index < count($this->frames)) {
            $frame = $this->frames[$this->current_index];
            $this->current_index += 1;
            return $frame;
        }
        return null;
    }

    public function reset() {
        $this->current_index = 0;
    }
}

class FrameProcessor {
    public $sequence;

    public function __construct($sequence) {
        $this->sequence = $sequence;
    }

    public function process_frames() {
        while (true) {
            $frame = $this->sequence->next_frame();
            if ($frame) {
                list($data, $timestamp) = $frame->get_data();
                echo "Processing frame $timestamp: $data\n";
            } else {
                $this->sequence->reset();
            }
        }
    }
}

function main() {
    $frame1 = new TemporalFrame('Data 1');
    $frame2 = new TemporalFrame('Data 2');
    $frame3 = new TemporalFrame('Data 3');
    $sequence = new FrameSequence();
    $sequence->add_frame($frame1);
    $sequence->add_frame($frame2);
    $sequence->add_frame($frame3);
    $processor = new FrameProcessor($sequence);
    $processor->process_frames();
}

main();