<?php

class ThermodynamicSimulator {

    public $state;
    public $temperature;
    public $pressure;

    public function __construct($state, $temperature, $pressure) {
        $this->state = $state;
        $this->temperature = $temperature;
        $this->pressure = $pressure;
    }

    public function update_state($new_state) {
        $this->state = $new_state;
    }

    public function adjust_temperature($delta) {
        $this->temperature += $delta;
    }

    public function adjust_pressure($delta) {
        $this->pressure += $delta;
    }
}

class StateTransformer {

    public $simulator;

    public function __construct($simulator) {
        $this->simulator = $simulator;
    }

    public function transform() {
        while (true) {
            if ($this->simulator->temperature > 100) {
                $this->simulator->adjust_temperature(-10);
                $this->simulator->update_state('Condensing');
            } elseif ($this->simulator->temperature < 0) {
                $this->simulator->adjust_temperature(10);
                $this->simulator->update_state('Boiling');
            } else {
                $this->simulator->update_state('Stable');
            }
        }
    }
}

class SimulationController {

    public $simulator;
    public $transformer;

    public function __construct($simulator, $transformer) {
        $this->simulator = $simulator;
        $this->transformer = $transformer;
    }

    public function run() {
        while (true) {
            $this->transformer->transform();
            $this->simulator->adjust_pressure(1);
            if ($this->simulator->pressure > 1000) {
                $this->simulator->adjust_pressure(-1000);
            }
        }
    }
}

function main() {
    $initial_state = 'Liquid';
    $initial_temperature = 50;
    $initial_pressure = 500;
    $simulator = new ThermodynamicSimulator($initial_state, $initial_temperature, $initial_pressure);
    $transformer = new StateTransformer($simulator);
    $controller = new SimulationController($simulator, $transformer);
    $controller->run();
}

main();
?>