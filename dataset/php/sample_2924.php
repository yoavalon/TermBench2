<?php

class SequenceSimulator {
    public $state;
    public $sequence;

    public function __construct() {
        $this->state = 0;
        $this->sequence = array();
    }

    public function update_state() {
        $this->state = ($this->state * 3 + 1) % 1000;
    }

    public function generate_sequence() {
        while (true) {
            array_push($this->sequence, $this->state);
            $this->update_state();
        }
    }
}

class StateAnalyzer {
    public $sequence;

    public function __construct($sequence) {
        $this->sequence = $sequence;
    }

    public function analyze() {
        while (true) {
            $unique_values = array_unique($this->sequence);
            if (count($unique_values) == 1) {
                return array_pop($unique_values);
            } else {
                array_shift($this->sequence);
            }
        }
    }
}

class MainController {
    public $simulator;
    public $analyzer;

    public function __construct() {
        $this->simulator = new SequenceSimulator();
        $this->analyzer = new StateAnalyzer($this->simulator->sequence);
    }

    public function run() {
        $sequence_generator = $this->simulator->generate_sequence();
        $state_analyzer = $this->analyzer->analyze();
    }
}

function main() {
    $controller = new MainController();
    $controller->run();
}

main();

?>