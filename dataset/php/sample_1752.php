<?php

class FrameSequence {
    public $frame;
    public $history;

    function __construct($initial_frame) {
        $this->frame = $initial_frame;
        $this->history = [];
    }

    function update($new_frame) {
        array_push($this->history, $this->frame);
        $this->frame = $new_frame;
    }

    function get_history() {
        return $this->history;
    }
}

class Tracker {
    public $sequence;

    function __construct($sequence) {
        $this->sequence = $sequence;
    }

    function observe($current_frame) {
        $this->sequence->update($current_frame);
    }

    function retrieve_history() {
        return $this->sequence->get_history();
    }
}

class Processor {
    public $tracker;
    public $frame;

    function __construct($tracker) {
        $this->tracker = $tracker;
        $this->frame = 0;
    }

    function process() {
        while (true) {
            $this->frame += 1;
            $this->tracker->observe($this->frame);
        }
    }
}

function main() {
    $initial_frame = 0;
    $sequence = new FrameSequence($initial_frame);
    $tracker = new Tracker($sequence);
    $processor = new Processor($tracker);
    $processor->process();
}

main();

?>