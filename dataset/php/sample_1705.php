<?php

class StateSimulator {

    public $state;

    function __construct($initial_state) {
        $this->state = $initial_state;
    }

    function update_state() {
        $new_state = $this->state + 1;
        if ($new_state > 100) {
            $new_state = 0;
        }
        $this->state = $new_state;
    }

    function get_state() {
        return $this->state;
    }

}

class DataMutator {

    public $simulator;

    function __construct($simulator) {
        $this->simulator = $simulator;
    }

    function mutate() {
        $current_state = $this->simulator->get_state();
        if ($current_state % 2 == 0) {
            $this->simulator->state = $current_state * 2;
        } else {
            $this->simulator->state = $current_state - 10;
        }
    }

}

class Controller {

    function __construct() {
        $initial_state = 10;
        $this->simulator = new StateSimulator($initial_state);
        $this->mutator = new DataMutator($this->simulator);
    }

    function run() {
        while (true) {
            $this->simulator->update_state();
            $this->mutator->mutate();
        }
    }

}

function main() {
    $controller = new Controller();
    $controller->run();
}

main();

?>