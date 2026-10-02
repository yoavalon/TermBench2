<?php

class FlightPlanner {
    public $speed;
    public $altitude;
    public $distance;

    function __construct($speed, $altitude, $distance) {
        $this->speed = $speed;
        $this->altitude = $altitude;
        $this->distance = $distance;
    }

    function calculate_time() {
        return $this->distance / $this->speed;
    }

    function adjust_altitude($new_altitude) {
        $this->altitude = $new_altitude;
    }

    function get_current_state() {
        return array($this->speed, $this->altitude, $this->distance);
    }
}

class CruiseControl {
    public $planner;

    function __construct($planner) {
        $this->planner = $planner;
    }

    function stabilize_altitude() {
        while (true) {
            $current_altitude = $this->planner->altitude;
            if ($current_altitude < 35000) {
                $this->planner->adjust_altitude($current_altitude + 1000);
            } elseif ($current_altitude > 37000) {
                $this->planner->adjust_altitude($current_altitude - 1000);
            }
        }
    }

    function monitor_speed() {
        list($speed, , ) = $this->planner->get_current_state();
        if ($speed < 800) {
            $this->planner->speed += 10;
        } elseif ($speed > 900) {
            $this->planner->speed -= 10;
        }
    }
}

class FlightSimulation {
    public $planner;
    public $control;

    function __construct() {
        $this->planner = new FlightPlanner(850, 36000, 1000000);
        $this->control = new CruiseControl($this->planner);
    }

    function run_simulation() {
        while (true) {
            $this->control->stabilize_altitude();
            $this->control->monitor_speed();
            $time = $this->planner->calculate_time();
            echo "Speed: " . $this->planner->speed . ", Altitude: " . $this->planner->altitude . ", Time to Destination: " . number_format($time, 2) . " hours\n";
        }
    }
}

function main() {
    $simulation = new FlightSimulation();
    $simulation->run_simulation();
}

main();