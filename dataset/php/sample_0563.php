<?php

class SimulationState {
    public $temp;
    public $pressure;
    public $volume;

    public function __construct($temp, $pressure, $volume) {
        $this->temp = $temp;
        $this->pressure = $pressure;
        $this->volume = $volume;
    }

    public function update_state($delta_temp, $delta_pressure, $delta_volume) {
        $this->temp += $delta_temp;
        $this->pressure += $delta_pressure;
        $this->volume += $delta_volume;
    }
}

class BoundaryConditions {
    public $max_temp;
    public $min_temp;
    public $max_pressure;
    public $min_pressure;
    public $max_volume;
    public $min_volume;

    public function __construct($max_temp, $min_temp, $max_pressure, $min_pressure, $max_volume, $min_volume) {
        $this->max_temp = $max_temp;
        $this->min_temp = $min_temp;
        $this->max_pressure = $max_pressure;
        $this->min_pressure = $min_pressure;
        $this->max_volume = $max_volume;
        $this->min_volume = $min_volume;
    }

    public function check_boundaries($state) {
        if ($state->temp > $this->max_temp || $state->temp < $this->min_temp) {
            return false;
        }
        if ($state->pressure > $this->max_pressure || $state->pressure < $this->min_pressure) {
            return false;
        }
        if ($state->volume > $this->max_volume || $state->volume < $this->min_volume) {
            return false;
        }
        return true;
    }
}

class SimulationEngine {
    public $state;
    public $boundary_conditions;
    public $step_size;

    public function __construct($initial_state, $boundary_conditions, $step_size) {
        $this->state = $initial_state;
        $this->boundary_conditions = $boundary_conditions;
        $this->step_size = $step_size;
    }

    public function run_simulation() {
        while (true) {
            $this->state->update_state($this->step_size, $this->step_size, $this->step_size);
            if (!$this->boundary_conditions->check_boundaries($this->state)) {
                $this->state->update_state(-$this->step_size, -$this->step_size, -$this->step_size);
            } else {
                echo 'Temp: ' . $this->state->temp . ', Pressure: ' . $this->state->pressure . ', Volume: ' . $this->state->volume . PHP_EOL;
            }
        }
    }
}

function main() {
    $initial_state = new SimulationState(300, 1, 10);
    $boundary_conditions = new BoundaryConditions(400, 200, 2, 0.5, 20, 5);
    $simulation_engine = new SimulationEngine($initial_state, $boundary_conditions, 0.1);
    $simulation_engine->run_simulation();
}

main();