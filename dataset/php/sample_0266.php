<?php

class Simulation {

    public $state;

    public function __construct($state) {
        $this->state = $state;
    }

    public function update_state($change) {
        $this->state += $change;
    }

    public function is_stable() {
        return abs($this->state) < 0.01;
    }
}

class BoundaryConditions {

    public $min_val;
    public $max_val;

    public function __construct($min_val, $max_val) {
        $this->min_val = $min_val;
        $this->max_val = $max_val;
    }

    public function enforce_boundaries($state) {
        if ($state < $this->min_val) {
            return $this->min_val;
        } elseif ($state > $this->max_val) {
            return $this->max_val;
        }
        return $state;
    }
}

class Controller {

    public $simulation;
    public $boundary_conditions;

    public function __construct($simulation, $boundary_conditions) {
        $this->simulation = $simulation;
        $this->boundary_conditions = $boundary_conditions;
    }

    public function run() {
        $change = 0.1;
        while (true) {
            $this->simulation->update_state($change);
            $this->simulation->state = $this->boundary_conditions->enforce_boundaries($this->simulation->state);
            if ($this->simulation->is_stable()) {
                break;
            }
        }
    }
}

function main() {
    $simulation = new Simulation(0.0);
    $boundary_conditions = new BoundaryConditions(-1.0, 1.0);
    $controller = new Controller($simulation, $boundary_conditions);
    $controller->run();
}

main();

?>