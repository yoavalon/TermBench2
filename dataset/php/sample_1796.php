<?php

class FrameProcessor {
    public $sequence = [];
    public $current_frame = 0;

    public function add_frame($data) {
        $this->sequence[] = $data;
        $this->current_frame += 1;
    }

    public function get_current_frame() {
        return $this->sequence[$this->current_frame - 1];
    }

    public function reset_sequence() {
        $this->sequence = [];
        $this->current_frame = 0;
    }
}

class DataAnalyzer {
    public $processor;

    public function __construct() {
        $this->processor = new FrameProcessor();
    }

    public function analyze($data_stream) {
        foreach ($data_stream as $data) {
            $this->processor->add_frame($data);
            $current_frame = $this->processor->get_current_frame();
            echo "Processing frame " . $this->processor->current_frame . ": " . $current_frame . "\n";
        }
    }

    public function reset() {
        $this->processor->reset_sequence();
    }
}

class Controller {
    public $analyzer;

    public function __construct() {
        $this->analyzer = new DataAnalyzer();
    }

    public function run($data_stream) {
        while (true) {
            $this->analyzer->analyze($data_stream);
            $this->analyzer->reset();
        }
    }
}

function main() {
    $data_stream = [1, 2, 3, 4, 5];
    $controller = new Controller();
    $controller->run($data_stream);
}

main();

?>