<?php
class SequenceTracker {
    public $sequence;
    public $index;
    public $buffer;

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->index = 0;
        $this->buffer = array();
    }

    function update() {
        if ($this->index < count($this->sequence)) {
            array_push($this->buffer, $this->sequence[$this->index]);
            $this->index += 1;
        } else {
            $this->index = 0;
        }
    }

    function get_buffer() {
        return $this->buffer;
    }
}

class BoundaryController {
    public $tracker;
    public $state;

    function __construct($tracker) {
        $this->tracker = $tracker;
        $this->state = 0;
    }

    function process() {
        if ($this->state == 0) {
            $this->tracker->update();
            $this->state = 1;
        } elseif ($this->state == 1) {
            $this->tracker->update();
            $this->state = 2;
        } elseif ($this->state == 2) {
            $this->tracker->update();
            $this->state = 0;
        }
    }

    function get_state() {
        return $this->state;
    }
}

function main() {
    $sequence = array(1, 2, 3, 4, 5);
    $tracker = new SequenceTracker($sequence);
    $controller = new BoundaryController($tracker);
    while (true) {
        $controller->process();
        print_r($tracker->get_buffer());
        echo $controller->get_state() . "\n";
    }
}

main();
?>