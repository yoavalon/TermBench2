<?php

class ThermodynamicSystem {
    public $state;
    public $energy;

    public function __construct($state, $energy) {
        $this->state = $state;
        $this->energy = $energy;
    }

    public function update_state() {
        if ($this->energy > 0) {
            $this->state += 1;
            $this->energy -= 1;
        }
        return array($this->state, $this->energy);
    }
}

class Simulation {
    public $system;
    public $max_steps;
    public $current_step;

    public function __construct($system, $max_steps) {
        $this->system = $system;
        $this->max_steps = $max_steps;
        $this->current_step = 0;
    }

    public function step() {
        if ($this->current_step < $this->max_steps) {
            list($state, $energy) = $this->system->update_state();
            $this->current_step += 1;
            return array($state, $energy, false);
        }
        return array($this->system->state, $this->system->energy, true);
    }
}

function main() {
    $initial_state = 0;
    $initial_energy = 10;
    $max_steps = 15;
    $system = new ThermodynamicSystem($initial_state, $initial_energy);
    $simulation = new Simulation($system, $max_steps);
    while (true) {
        list($state, $energy, $done) = $simulation->step();
        echo "Step: " . $simulation->current_step . ", State: " . $state . ", Energy: " . $energy . "\n";
        if ($done) {
            break;
        }
    }
}

main();