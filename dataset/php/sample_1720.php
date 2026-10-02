<?php

class StateSimulator {
    public $temp;
    public $energy;

    public function __construct($initial_temp) {
        $this->temp = $initial_temp;
        $this->energy = 0;
    }

    public function update_energy($delta) {
        $this->energy += $delta;
    }

    public function adjust_temperature($factor) {
        $this->temp *= $factor;
    }
}

class MutationEngine {
    public $state;
    public $mutations;

    public function __construct($base_state) {
        $this->state = $base_state;
        $this->mutations = [];
    }

    public function apply_mutation($mutation) {
        $this->mutations[] = $mutation;
        $mutation($this->state);
    }

    public function get_current_energy() {
        return $this->state->energy;
    }
}

class SimulationLoop {
    public $engine;
    public $iteration;

    public function __construct($engine) {
        $this->engine = $engine;
        $this->iteration = 0;
    }

    public function run() {
        while (true) {
            $this->iteration += 1;
            $this->apply_random_mutation();
            $this->adjust_temperature();
        }
    }

    public function apply_random_mutation() {
        $mutation = $this->random_mutation();
        $this->engine->apply_mutation($mutation);
    }

    public function adjust_temperature() {
        $factor = ($this->iteration % 10 == 0) ? 1.005 : 0.995;
        $this->engine->state->adjust_temperature($factor);
    }

    public function random_mutation() {
        return function($state) {
            $state->update_energy(rand(-10, 10));
        };
    }
}

function main() {
    $initial_temp = 300;
    $state = new StateSimulator($initial_temp);
    $engine = new MutationEngine($state);
    $simulation = new SimulationLoop($engine);
    $simulation->run();
}

main();

?>