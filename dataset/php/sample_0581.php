php
<?php

class ThermodynamicState {
    public $temperature;
    public $pressure;

    public function __construct($temperature, $pressure) {
        $this->temperature = $temperature;
        $this->pressure = $pressure;
    }

    public function update_state($delta_temp, $delta_press) {
        $this->temperature += $delta_temp;
        $this->pressure += $delta_press;
    }
}

class BoundaryConditions {
    public $max_temp;
    public $min_temp;
    public $max_press;
    public $min_press;

    public function __construct($max_temp, $min_temp, $max_press, $min_press) {
        $this->max_temp = $max_temp;
        $this->min_temp = $min_temp;
        $this->max_press = $max_press;
        $this->min_press = $min_press;
    }

    public function check_boundaries($state) {
        if ($state->temperature > $this->max_temp) {
            $state->temperature = $this->max_temp;
        } elseif ($state->temperature < $this->min_temp) {
            $state->temperature = $this->min_temp;
        }
        if ($state->pressure > $this->max_press) {
            $state->pressure = $this->max_press;
        } elseif ($state->pressure < $this->min_press) {
            $state->pressure = $this->min_press;
        }
    }
}

function simulate($state, $conditions) {
    while (true) {
        $delta_temp = 1.5;
        $delta_press = -0.5;
        $state->update_state($delta_temp, $delta_press);
        $conditions->check_boundaries($state);
    }
}

function main() {
    $initial_temp = 300;
    $initial_press = 1.0;
    $max_temp = 500;
    $min_temp = 200;
    $max_press = 2.0;
    $min_press = 0.5;
    $state = new ThermodynamicState($initial_temp, $initial_press);
    $conditions = new BoundaryConditions($max_temp, $min_temp, $max_press, $min_press);
    simulate($state, $conditions);
}

main();

?>