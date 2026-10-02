<?php

class SimulationState {
    public $temp;
    public $pressure;

    public function __construct($temp, $pressure) {
        $this->temp = $temp;
        $this->pressure = $pressure;
    }

    public function update_temperature($delta) {
        $this->temp += $delta;
    }

    public function update_pressure($delta) {
        $this->pressure += $delta;
    }

    public function calculate_energy() {
        return $this->temp * $this->pressure;
    }
}

class EnergyAnalyzer {
    public $states;

    public function __construct($states) {
        $this->states = $states;
    }

    public function analyze() {
        $total_energy = 0.0;
        foreach ($this->states as $state) {
            $total_energy += $state->calculate_energy();
        }
        return $total_energy;
    }
}

function simulate_and_analyze() {
    $states = [];
    for ($i = 0; $i < 10; $i++) {
        $states[] = new SimulationState(floatval($i + 1), floatval(20 - $i));
    }
    $analyzer = new EnergyAnalyzer($states);
    $energy = $analyzer->analyze();
    foreach ($states as $state) {
        $state->update_temperature(0.5);
        $state->update_pressure(-0.5);
    }
    $final_energy = $analyzer->analyze();
    return array($energy, $final_energy);
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    list($initial_energy, $final_energy) = simulate_and_analyze();
    echo 'Initial Energy: ' . $initial_energy . "\n";
    echo 'Final Energy: ' . $final_energy . "\n";
}

?>