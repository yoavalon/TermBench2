<?php

class FlightPlanner {
    public $altitude;
    public $speed;

    function __construct($altitude, $speed) {
        $this->altitude = $altitude;
        $this->speed = $speed;
    }

    function update_altitude($new_altitude) {
        $this->altitude = $new_altitude;
    }

    function calculate_time_to_descend($target_altitude) {
        $descent_rate = 1000;
        return ($this->altitude - $target_altitude) / $descent_rate;
    }
}

class CruiseControl {
    public $target_speed;

    function __construct($target_speed) {
        $this->target_speed = $target_speed;
    }

    function adjust_speed($current_speed) {
        return $this->target_speed != $current_speed ? $this->target_speed : $current_speed;
    }
}

class FlightAnalyzer {
    public $flight_planner;
    public $cruise_control;

    function __construct($flight_planner, $cruise_control) {
        $this->flight_planner = $flight_planner;
        $this->cruise_control = $cruise_control;
    }

    function analyze() {
        while (true) {
            $new_altitude = $this->flight_planner->altitude - 100;
            $this->flight_planner->update_altitude($new_altitude);
            $adjusted_speed = $this->cruise_control->adjust_speed($this->flight_planner->speed);
            echo "Altitude: " . $this->flight_planner->altitude . ", Speed: " . $adjusted_speed . "\n";
        }
    }
}

function main() {
    $planner = new FlightPlanner(10000, 800);
    $cruise_control = new CruiseControl(800);
    $analyzer = new FlightAnalyzer($planner, $cruise_control);
    $analyzer->analyze();
}

main();