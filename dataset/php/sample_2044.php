<?php

class ThermodynamicState {
    public $temp;
    public $press;
    public $vol;

    public function __construct($temp, $press, $vol) {
        $this->temp = $temp;
        $this->press = $press;
        $this->vol = $vol;
    }

    public function update_state($delta_temp, $delta_press) {
        $this->temp += $delta_temp;
        $this->press += $delta_press;
        $this->vol = $this->press / $this->temp;
    }

    public function get_properties() {
        return array($this->temp, $this->press, $this->vol);
    }
}

function simulate_state_changes($initial_state, $changes) {
    $current_state = $initial_state;
    $results = array();
    foreach ($changes as $change) {
        $current_state->update_state($change[0], $change[1]);
        $results[] = $current_state->get_properties();
    }
    return $results;
}

function analyze_simulation_data($data) {
    $avg_temp = array_sum(array_column($data, 0)) / count($data);
    $avg_press = array_sum(array_column($data, 1)) / count($data);
    $avg_vol = array_sum(array_column($data, 2)) / count($data);
    return array($avg_temp, $avg_press, $avg_vol);
}

function main() {
    $initial_state = new ThermodynamicState(300, 1.0, 0.5);
    $changes = array(array(10, 0.1), array(-5, 0.05), array(0, -0.02));
    $simulation_data = simulate_state_changes($initial_state, $changes);
    $averages = analyze_simulation_data($simulation_data);
    echo 'Average Temperature: ' . $averages[0] . "\n";
    echo 'Average Pressure: ' . $averages[1] . "\n";
    echo 'Average Volume: ' . $averages[2] . "\n";
}

main();

?>