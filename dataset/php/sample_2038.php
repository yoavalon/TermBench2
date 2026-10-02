<?php

class ThermodynamicState {
    public $temp;
    public $pressure;

    function __construct($temp, $pressure) {
        $this->temp = $temp;
        $this->pressure = $pressure;
    }

    function update_state($temp_change, $pressure_change) {
        $this->temp += $temp_change;
        $this->pressure += $pressure_change;
    }

    function calculate_entropy() {
        if ($this->temp <= 0) {
            return NaN;
        }
        return $this->pressure / $this->temp;
    }
}

class SimulationController {
    public $state;
    public $iterations;
    public $data;

    function __construct($initial_state, $iterations) {
        $this->state = $initial_state;
        $this->iterations = $iterations;
        $this->data = [];
    }

    function run_simulation() {
        for ($i = 0; $i < $this->iterations; $i++) {
            $this->state->update_state(0.1, -0.05);
            $this->data[] = $this->state->calculate_entropy();
        }
    }

    function get_results() {
        return $this->data;
    }
}

function analyze_data($data) {
    $total = 0;
    $count = 0;
    foreach ($data as $value) {
        if (!is_nan($value)) {
            $total += $value;
            $count += 1;
        }
    }
    return $count > 0 ? $total / $count : NaN;
}

function main() {
    $initial_state = new ThermodynamicState(300, 100);
    $controller = new SimulationController($initial_state, 50);
    $controller->run_simulation();
    $results = $controller->get_results();
    $average_entropy = analyze_data($results);
    echo "Average Entropy: " . $average_entropy . "\n";
}

main();

?>