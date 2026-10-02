<?php

class FlightTrajectory {
    public $current_altitude;
    public $target_altitude;
    public $rate_of_climb;
    public $rate_of_descent;

    function __construct($initial_altitude, $target_altitude, $rate_of_climb, $rate_of_descent) {
        $this->current_altitude = $initial_altitude;
        $this->target_altitude = $target_altitude;
        $this->rate_of_climb = $rate_of_climb;
        $this->rate_of_descent = $rate_of_descent;
    }

    function climb() {
        if ($this->current_altitude < $this->target_altitude) {
            $this->current_altitude += $this->rate_of_climb;
            if ($this->current_altitude > $this->target_altitude) {
                $this->current_altitude = $this->target_altitude;
            }
        }
    }

    function descend() {
        if ($this->current_altitude > $this->target_altitude) {
            $this->current_altitude -= $this->rate_of_descent;
            if ($this->current_altitude < $this->target_altitude) {
                $this->current_altitude = $this->target_altitude;
            }
        }
    }

    function adjust_altitude() {
        if ($this->current_altitude < $this->target_altitude) {
            $this->climb();
        } elseif ($this->current_altitude > $this->target_altitude) {
            $this->descend();
        }
    }
}

class CruiseAltitudeManager {
    public $trajectory;
    public $cruise_altitude;
    public $altitude_changes;

    function __construct($trajectory) {
        $this->trajectory = $trajectory;
        $this->cruise_altitude = $trajectory->target_altitude;
        $this->altitude_changes = array();
    }

    function update_cruise_altitude($new_altitude) {
        $this->cruise_altitude = $new_altitude;
        $this->trajectory->target_altitude = $new_altitude;
    }

    function log_altitude_change() {
        array_push($this->altitude_changes, $this->trajectory->current_altitude);
    }

    function manage_cruise() {
        $this->trajectory->adjust_altitude();
        $this->log_altitude_change();
    }
}

class FlightSimulation {
    public $trajectory;
    public $cruise_manager;

    function __construct($initial_altitude, $target_altitude, $rate_of_climb, $rate_of_descent) {
        $this->trajectory = new FlightTrajectory($initial_altitude, $target_altitude, $rate_of_climb, $rate_of_descent);
        $this->cruise_manager = new CruiseAltitudeManager($this->trajectory);
    }

    function simulate_flight() {
        while (true) {
            $this->cruise_manager->manage_cruise();
        }
    }
}

function main() {
    $flight_sim = new FlightSimulation(5000, 35000, 500, 300);
    $flight_sim->simulate_flight();
}

main();
?>