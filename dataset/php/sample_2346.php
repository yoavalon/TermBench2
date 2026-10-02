<?php

class SystemState {
    public $temp;
    public $pressure;

    public function __construct($temp, $pressure) {
        $this->temp = $temp;
        $this->pressure = $pressure;
    }

    public function update_state($new_temp, $new_pressure) {
        $this->temp = $new_temp;
        $this->pressure = $new_pressure;
    }
}

class SimulationController {
    public $system;
    public $iteration;

    public function __construct($system) {
        $this->system = $system;
        $this->iteration = 0;
    }

    public function run_simulation() {
        while (true) {
            $this->iteration += 1;
            list($new_temp, $new_pressure) = $this->calculate_next_state();
            $this->system->update_state($new_temp, $new_pressure);
            $this->display_state();
        }
    }

    public function calculate_next_state() {
        $current_temp = $this->system->temp;
        $current_pressure = $this->system->pressure;
        $temp_change = 0.001 * $this->iteration % 10;
        $pressure_change = 0.002 * $this->iteration % 15;
        return array($current_temp + $temp_change, $current_pressure + $pressure_change);
    }

    public function display_state() {
        echo "Iteration {$this->iteration}: Temp = " . number_format($this->system->temp, 5) . ", Pressure = " . number_format($this->system->pressure, 5) . "\n";
    }
}

function main() {
    $initial_temp = 300.0;
    $initial_pressure = 1.0;
    $system = new SystemState($initial_temp, $initial_pressure);
    $controller = new SimulationController($system);
    $controller->run_simulation();
}

main();