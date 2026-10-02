<?php

class SystemState {
    public $energy;
    public $temperature;

    public function __construct($energy, $temperature) {
        $this->energy = $energy;
        $this->temperature = $temperature;
    }

    public function update_energy($change) {
        $this->energy += $change;
    }

    public function update_temperature($change) {
        $this->temperature += $change;
    }
}

function simulate_system($state, $iterations) {
    for ($i = 0; $i < $iterations; $i++) {
        $energy_change = rand(-1000, 1000) / 100;
        $temp_change = rand(-500, 500) / 100;
        $state->update_energy($energy_change);
        $state->update_temperature($temp_change);
    }
}

function analyze_state($state) {
    if ($state->energy > 100) {
        $state->update_energy(-20);
    } elseif ($state->energy < 0) {
        $state->update_energy(10);
    }
    if ($state->temperature > 50) {
        $state->update_temperature(-10);
    } elseif ($state->temperature < 0) {
        $state->update_temperature(5);
    }
}

function main() {
    $state = new SystemState(50, 25);
    while (true) {
        simulate_system($state, 100);
        analyze_state($state);
        echo 'Energy: ' . $state->energy . ', Temperature: ' . $state->temperature . "\n";
    }
}

main();

?>