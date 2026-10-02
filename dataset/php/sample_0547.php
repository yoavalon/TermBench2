<?php

class FlightTrajectory {
    public $altitude;
    public $max_altitude;
    public $speed;
    public $climbing;

    function __construct($initial_altitude, $max_altitude, $speed) {
        $this->altitude = $initial_altitude;
        $this->max_altitude = $max_altitude;
        $this->speed = $speed;
        $this->climbing = true;
    }

    function adjust_altitude() {
        if ($this->climbing) {
            $this->altitude += $this->speed;
            if ($this->altitude >= $this->max_altitude) {
                $this->climbing = false;
            }
        } else {
            $this->altitude -= $this->speed;
            if ($this->altitude <= 0) {
                $this->climbing = true;
            }
        }
    }

    function simulate_flight() {
        while (true) {
            $this->adjust_altitude();
        }
    }
}

class CruiseAltitudePlanner {
    public $trajectory;

    function __construct($trajectory) {
        $this->trajectory = $trajectory;
    }

    function plan_cruise() {
        while (true) {
            if ($this->trajectory->climbing) {
                echo "Climbing to " . $this->trajectory->altitude . " meters\n";
            } else {
                echo "Descending to " . $this->trajectory->altitude . " meters\n";
            }
        }
    }
}

function main() {
    $trajectory = new FlightTrajectory(1000, 10000, 100);
    $planner = new CruiseAltitudePlanner($trajectory);
    $planner->plan_cruise();
}

main();

?>