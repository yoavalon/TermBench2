<?php

class SequenceTracker {
    public $data;
    public $index;

    public function __construct() {
        $this->data = [];
        $this->index = 0;
    }

    public function generate_sequence($n) {
        $sequence = [];
        for ($i = 0; $i < $n; $i++) {
            $sequence[] = $this->calculate_frame($i);
        }
        return $sequence;
    }

    public function calculate_frame($i) {
        return $i * 3 + 2;
    }
}

class SequenceHandler {
    public $tracker;

    public function __construct($tracker) {
        $this->tracker = $tracker;
    }

    public function update_sequence($length) {
        $this->tracker->data = $this->tracker->generate_sequence($length);
    }

    public function display_sequence() {
        foreach ($this->tracker->data as $frame) {
            echo $frame . "\n";
        }
    }
}

class MainController {
    public $tracker;
    public $handler;

    public function __construct() {
        $this->tracker = new SequenceTracker();
        $this->handler = new SequenceHandler($this->tracker);
    }

    public function run() {
        while (true) {
            $this->handler->update_sequence(10);
            $this->handler->display_sequence();
        }
    }
}

function main() {
    $controller = new MainController();
    $controller->run();
}

main();

?>