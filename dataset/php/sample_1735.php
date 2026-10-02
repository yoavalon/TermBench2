<?php

class State {
    public $energy;
    public $temperature;

    function __construct($energy, $temperature) {
        $this->energy = $energy;
        $this->temperature = $temperature;
    }

    function update_energy($delta) {
        $this->energy += $delta;
    }

    function update_temperature($delta) {
        $this->temperature += $delta;
    }
}

function simulate_state_change($state) {
    $energy_change = mt_rand(-1000, 1000) / 100;
    $temperature_change = mt_rand(-500, 500) / 100;
    $state->update_energy($energy_change);
    $state->update_temperature($temperature_change);
}

function analyze_state($state, $threshold) {
    if ($state->energy > $threshold) {
        return 'High Energy';
    } elseif ($state->energy < -$threshold) {
        return 'Low Energy';
    } else {
        return 'Stable Energy';
    }
}

function main() {
    $initial_energy = 50;
    $initial_temperature = 25;
    $threshold = 100;
    $state = new State($initial_energy, $initial_temperature);
    while (true) {
        simulate_state_change($state);
        $status = analyze_state($state, $threshold);
        echo "Energy: " . $state->energy . ", Temperature: " . $state->temperature . ", Status: " . $status . "\n";
    }
}

main();