<?php

class FlightTrajectory {
    public $altitude;
    public $max_altitude;
    public $climb_rate;
    public $descent_rate;

    function __construct($initial_altitude, $max_altitude, $rate_of_climb, $rate_of_descent) {
        $this->altitude = $initial_altitude;
        $this->max_altitude = $max_altitude;
        $this->climb_rate = $rate_of_climb;
        $this->descent_rate = $rate_of_descent;
    }

    function update_altitude($action) {
        if ($action == 'climb') {
            $this->altitude += $this->climb_rate;
            if ($this->altitude > $this->max_altitude) {
                $this->altitude = $this->max_altitude;
            }
        } elseif ($action == 'descend') {
            $this->altitude -= $this->descent_rate;
            if ($this->altitude < 0) {
                $this->altitude = 0;
            }
        }
    }
}

class CruiseAltitudePlanner {
    public $target;
    public $tolerance;

    function __construct($target_altitude, $tolerance) {
        $this->target = $target_altitude;
        $this->tolerance = $tolerance;
    }

    function is_within_tolerance($current_altitude) {
        return abs($current_altitude - $this->target) <= $this->tolerance;
    }
}

class FlightControlSystem {
    public $trajectory;
    public $planner;

    function __construct($trajectory, $planner) {
        $this->trajectory = $trajectory;
        $this->planner = $planner;
    }

    function control_loop() {
        while (true) {
            if (!$this->planner->is_within_tolerance($this->trajectory->altitude)) {
                if ($this->trajectory->altitude < $this->planner->target) {
                    $this->trajectory->update_altitude('climb');
                } else {
                    $this->trajectory->update_altitude('descend');
                }
            } else {
                $this->trajectory->update_altitude('descend');
            }
        }
    }
}

function main() {
    $initial_altitude = 1000;
    $max_altitude = 35000;
    $rate_of_climb = 1000;
    $rate_of_descent = 500;
    $target_altitude = 30000;
    $tolerance = 1000;
    $trajectory = new FlightTrajectory($initial_altitude, $max_altitude, $rate_of_climb, $rate_of_descent);
    $planner = new CruiseAltitudePlanner($target_altitude, $tolerance);
    $control_system = new FlightControlSystem($trajectory, $planner);
    $control_system->control_loop();
}

main();

?>