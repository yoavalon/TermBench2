<?php

class FlightParameters {
    public $altitude;
    public $cruise_altitude;
    public $rate_of_climb;
    public $rate_of_descent;

    function __construct($initial_altitude, $cruise_altitude, $rate_of_climb, $rate_of_descent) {
        $this->altitude = $initial_altitude;
        $this->cruise_altitude = $cruise_altitude;
        $this->rate_of_climb = $rate_of_climb;
        $this->rate_of_descent = $rate_of_descent;
    }

    function update_altitude($action) {
        if ($action == 'climb') {
            $this->altitude += $this->rate_of_climb;
        } elseif ($action == 'descend') {
            $this->altitude -= $this->rate_of_descent;
        }
    }

    function is_at_cruise() {
        return $this->altitude >= $this->cruise_altitude;
    }
}

class BoundaryConditions {
    public $min_altitude;
    public $max_altitude;

    function __construct($min_altitude, $max_altitude) {
        $this->min_altitude = $min_altitude;
        $this->max_altitude = $max_altitude;
    }

    function is_within_bounds($altitude) {
        return $this->min_altitude <= $altitude && $altitude <= $this->max_altitude;
    }

    function adjust_boundary($altitude) {
        if ($altitude < $this->min_altitude) {
            return $this->min_altitude;
        } elseif ($altitude > $this->max_altitude) {
            return $this->max_altitude;
        }
        return $altitude;
    }
}

function flight_control_system($flight, $boundaries) {
    while (true) {
        if (!$boundaries->is_within_bounds($flight->altitude)) {
            $flight->altitude = $boundaries->adjust_boundary($flight->altitude);
        }
        if (!$flight->is_at_cruise()) {
            $action = $flight->altitude < $flight->cruise_altitude ? 'climb' : 'descend';
            $flight->update_altitude($action);
        }
    }
}

function main() {
    $flight = new FlightParameters(5000, 35000, 1000, 500);
    $boundaries = new BoundaryConditions(5000, 40000);
    flight_control_system($flight, $boundaries);
}

main();

?>