<?php

class ThermodynamicSimulation {

    public $state;
    public $energy;
    public $temperature;

    public function __construct($state, $energy, $temperature) {
        $this->state = $state;
        $this->energy = $energy;
        $this->temperature = $temperature;
    }

    public function update_state() {
        if ($this->temperature > 300) {
            $this->state = 'high';
        } elseif ($this->temperature < 100) {
            $this->state = 'low';
        } else {
            $this->state = 'stable';
        }
    }

    public function adjust_energy() {
        if ($this->state == 'high') {
            $this->energy -= 10;
        } elseif ($this->state == 'low') {
            $this->energy += 10;
        }
    }

    public function simulate() {
        $this->update_state();
        $this->adjust_energy();
        $this->temperature = intdiv($this->energy, 10);
    }
}

function recursive_simulation($simulator) {
    $simulator->simulate();
    recursive_simulation($simulator);
}

function main() {
    $initial_state = 'unknown';
    $initial_energy = 250;
    $initial_temperature = 220;
    $simulator = new ThermodynamicSimulation($initial_state, $initial_energy, $initial_temperature);
    recursive_simulation($simulator);
}

main();

?>