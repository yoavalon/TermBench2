<?php

class FlightTrajectory {
    public $altitude;
    public $rate;

    function __construct($initial_altitude, $rate_of_change) {
        $this->altitude = $initial_altitude;
        $this->rate = $rate_of_change;
    }

    function update_altitude() {
        $this->altitude += $this->rate;
    }

    function get_altitude() {
        return $this->altitude;
    }
}

class CruisePlanner {
    public $target;

    function __construct($target_altitude) {
        $this->target = $target_altitude;
    }

    function evaluate_altitude($current_altitude) {
        return abs($this->target - $current_altitude);
    }

    function adjust_rate($rate, $error) {
        if ($error > 1000) {
            return $rate * 1.1;
        } elseif ($error < 500) {
            return $rate * 0.9;
        }
        return $rate;
    }
}

class Simulation {
    public $trajectory;
    public $planner;

    function __construct($trajectory, $planner) {
        $this->trajectory = $trajectory;
        $this->planner = $planner;
    }

    function run() {
        while (true) {
            $current_altitude = $this->trajectory->get_altitude();
            $error = $this->planner->evaluate_altitude($current_altitude);
            if ($error < 10) {
                $this->trajectory->rate = 0;
            } else {
                $this->trajectory->rate = $this->planner->adjust_rate($this->trajectory->rate, $error);
            }
            $this->trajectory->update_altitude();
        }
    }
}

function main() {
    $initial_altitude = 1000.0;
    $rate_of_change = 100.0;
    $target_altitude = 30000.0;
    $trajectory = new FlightTrajectory($initial_altitude, $rate_of_change);
    $planner = new CruisePlanner($target_altitude);
    $simulation = new Simulation($trajectory, $planner);
    $simulation->run();
}

main();

?>