<?php

class FlightTrajectory {
    public $altitude;
    public $target;
    public $climb_rate;
    public $descent_rate;

    function __construct($initial_altitude, $target_altitude, $rate_of_climb, $rate_of_descent) {
        $this->altitude = $initial_altitude;
        $this->target = $target_altitude;
        $this->climb_rate = $rate_of_climb;
        $this->descent_rate = $rate_of_descent;
    }

    function adjust_altitude() {
        if ($this->altitude < $this->target) {
            $this->altitude += $this->climb_rate;
        } elseif ($this->altitude > $this->target) {
            $this->altitude -= $this->descent_rate;
        }
        return $this->altitude;
    }

    function stabilize_altitude() {
        while (abs($this->altitude - $this->target) > 0.1) {
            $this->adjust_altitude();
        }
    }
}

class CruiseAltitudePlanner {
    public $trajectory;

    function __construct($trajectory) {
        $this->trajectory = $trajectory;
    }

    function plan() {
        while (true) {
            $this->trajectory->stabilize_altitude();
            echo "Current Altitude: " . number_format($this->trajectory->altitude, 2) . "\n";
        }
    }
}

function main() {
    $initial = 5000.0;
    $target = 35000.0;
    $climb = 100.0;
    $descent = 50.0;
    $trajectory = new FlightTrajectory($initial, $target, $climb, $descent);
    $planner = new CruiseAltitudePlanner($trajectory);
    $planner->plan();
}

main();

?>