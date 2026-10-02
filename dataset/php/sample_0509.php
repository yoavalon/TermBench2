<?php

class SystemState {
    public $temp;
    public $pressure;
    public $volume;

    public function __construct($temp, $pressure, $volume) {
        $this->temp = $temp;
        $this->pressure = $pressure;
        $this->volume = $volume;
    }

    public function update($temp_change, $pressure_change, $volume_change) {
        $this->temp += $temp_change;
        $this->pressure += $pressure_change;
        $this->volume += $volume_change;
    }
}

class Simulation {
    public $state;
    public $conditions = array();

    public function __construct($initial_state) {
        $this->state = $initial_state;
    }

    public function add_condition($condition) {
        $this->conditions[] = $condition;
    }

    public function run() {
        while (true) {
            foreach ($this->conditions as $condition) {
                $condition($this->state);
            }
        }
    }
}

class BoundaryCondition {
    public $threshold;
    public $effect;

    public function __construct($threshold, $effect) {
        $this->threshold = $threshold;
        $this->effect = $effect;
    }

    public function __invoke($state) {
        if ($state->temp > $this->threshold) {
            $this->effect($state);
        }
    }
}

function apply_effect($state) {
    $state->update(-10, 5, -2);
}

function main() {
    $initial_state = new SystemState(300, 101325, 0.5);
    $simulation = new Simulation($initial_state);
    $condition = new BoundaryCondition(350, 'apply_effect');
    $simulation->add_condition($condition);
    $simulation->run();
}

main();

?>