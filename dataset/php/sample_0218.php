<?php

class FlightParameters {
    public $altitude;
    public $target;
    public $climb_rate;
    public $descent_rate;

    function __construct($initial_altitude, $target_altitude, $max_climb_rate, $descent_rate) {
        $this->altitude = $initial_altitude;
        $this->target = $target_altitude;
        $this->climb_rate = $max_climb_rate;
        $this->descent_rate = $descent_rate;
    }
}

class FlightControl {
    public $params;

    function __construct($parameters) {
        $this->params = $parameters;
    }

    function adjust_altitude() {
        if ($this->params->altitude < $this->params->target) {
            $this->params->altitude += $this->params->climb_rate;
        } elseif ($this->params->altitude > $this->params->target) {
            $this->params->altitude -= $this->params->descent_rate;
        }
        return $this->params->altitude;
    }
}

class FlightSimulation {
    public $control;
    public $is_operational;

    function __construct($control) {
        $this->control = $control;
        $this->is_operational = true;
    }

    function run_simulation() {
        while ($this->is_operational) {
            $new_altitude = $this->control->adjust_altitude();
            if ($new_altitude == $this->control->params->target) {
                $this->is_operational = false;
            }
            echo 'Current Altitude: ' . $new_altitude . PHP_EOL;
        }
    }
}

function main() {
    $params = new FlightParameters(5000, 35000, 1500, 500);
    $control = new FlightControl($params);
    $simulation = new FlightSimulation($control);
    $simulation->run_simulation();
}

main();
?>