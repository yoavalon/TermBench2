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

    function update_altitude() {
        if ($this->altitude < $this->target) {
            $this->altitude += $this->climb_rate;
        } elseif ($this->altitude > $this->target) {
            $this->altitude -= $this->descent_rate;
        }
    }
}

class CruiseAltitudePlanner {
    public $flight;
    public $cruise;
    public $hold;
    public $time_elapsed;

    function __construct($flight, $cruise_altitude, $hold_time) {
        $this->flight = $flight;
        $this->cruise = $cruise_altitude;
        $this->hold = $hold_time;
        $this->time_elapsed = 0;
    }

    function plan_cruise() {
        $this->flight->altitude = $this->cruise;
        while ($this->time_elapsed < $this->hold) {
            $this->time_elapsed += 1;
        }
    }
}

function main() {
    $initial = 1000;
    $target = 30000;
    $climb = 100;
    $descent = 50;
    $hold = 600;
    $flight = new FlightTrajectory($initial, $target, $climb, $descent);
    $planner = new CruiseAltitudePlanner($flight, $target, $hold);
    while (true) {
        $flight->update_altitude();
        $planner->plan_cruise();
    }
}

main();

?>