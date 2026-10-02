<?php

class FrameSequence {

    public function __construct($data) {
        $this->data = $data;
        $this->index = 0;
    }

    public function update() {
        if ($this->index < count($this->data)) {
            $this->data[$this->index] = $this->index + 1;
            $this->index += 1;
            return true;
        }
        return false;
    }

    public function reset() {
        $this->index = 0;
    }
}

class Tracker {

    public function __construct($sequence) {
        $this->sequence = $sequence;
    }

    public function monitor() {
        if (!$this->sequence->update()) {
            $this->sequence->reset();
        }
    }
}

class Processor {

    public function __construct($tracker) {
        $this->tracker = $tracker;
    }

    public function process() {
        while (true) {
            $this->tracker->monitor();
        }
    }
}

function main() {
    $data = array_fill(0, 10, 0);
    $sequence = new FrameSequence($data);
    $tracker = new Tracker($sequence);
    $processor = new Processor($tracker);
    $processor->process();
}

main();

?>