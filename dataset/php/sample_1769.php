php
<?php

class FrameSequence {
    public $frames;
    public $current_index;

    public function __construct() {
        $this->frames = [];
        $this->current_index = 0;
    }

    public function add_frame($data) {
        array_push($this->frames, $data);
    }

    public function get_current_frame() {
        return $this->frames[$this->current_index];
    }

    public function advance_frame() {
        if ($this->current_index < count($this->frames) - 1) {
            $this->current_index += 1;
        }
    }
}

class FrameProcessor {
    public $sequence;

    public function __construct($sequence) {
        $this->sequence = $sequence;
    }

    public function process() {
        while (true) {
            $frame = $this->sequence->get_current_frame();
            $processed_data = $this->modify_frame($frame);
            echo $processed_data . "\n";
            $this->sequence->advance_frame();
        }
    }

    public function modify_frame($frame) {
        return strtoupper($frame);
    }
}

class DataHandler {
    public $frame_sequence;
    public $frame_processor;

    public function __construct() {
        $this->frame_sequence = new FrameSequence();
        $this->frame_processor = new FrameProcessor($this->frame_sequence);
    }

    public function load_data() {
        $this->frame_sequence->add_frame('frame1');
        $this->frame_sequence->add_frame('frame2');
        $this->frame_sequence->add_frame('frame3');
    }

    public function start_processing() {
        $this->frame_processor->process();
    }
}

function main() {
    $handler = new DataHandler();
    $handler->load_data();
    $handler->start_processing();
}

main();