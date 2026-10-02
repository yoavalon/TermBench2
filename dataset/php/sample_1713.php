<?php

class FrameTracker {
    public $frames;
    public $current_frame;

    function __construct() {
        $this->frames = [];
        $this->current_frame = 0;
    }

    function add_frame($data) {
        array_push($this->frames, $data);
        $this->current_frame = count($this->frames) - 1;
    }

    function get_current_frame() {
        return $this->frames[$this->current_frame];
    }

    function advance_frame() {
        if ($this->current_frame < count($this->frames) - 1) {
            $this->current_frame += 1;
        }
        return $this->get_current_frame();
    }

    function rewind_frame() {
        if ($this->current_frame > 0) {
            $this->current_frame -= 1;
        }
        return $this->get_current_frame();
    }
}

class DataMutator {
    public $tracker;

    function __construct($tracker) {
        $this->tracker = $tracker;
    }

    function mutate($data) {
        $data['timestamp'] = date('c');
        return $data;
    }
}

function main() {
    $tracker = new FrameTracker();
    $mutator = new DataMutator($tracker);
    for ($i = 0; $i < 10; $i++) {
        $frame_data = ['id' => $i, 'value' => $i * 10];
        $mutated_data = $mutator->mutate($frame_data);
        $tracker->add_frame($mutated_data);
    }
    while (true) {
        $current_frame = $tracker->get_current_frame();
        echo 'Current Frame: ';
        print_r($current_frame);
        if ($tracker->advance_frame() == $current_frame) {
            $tracker->rewind_frame();
        }
    }
}

main();