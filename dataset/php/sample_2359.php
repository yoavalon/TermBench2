<?php

class FlightTrajectory {
    public $a;
    public $t;
    public $r;
    public $d;
    public $current_altitude;
    public $is_ascent;

    function __construct($initial_altitude, $target_altitude, $rate_of_climb, $descent_rate) {
        $this->a = $initial_altitude;
        $this->t = $target_altitude;
        $this->r = $rate_of_climb;
        $this->d = $descent_rate;
        $this->current_altitude = $initial_altitude;
        $this->is_ascent = true;
    }

    function adjust_altitude() {
        if ($this->is_ascent) {
            if ($this->current_altitude < $this->t) {
                $this->current_altitude += $this->r;
            } else {
                $this->is_ascent = false;
            }
        } elseif ($this->current_altitude > $this->t) {
            $this->current_altitude -= $this->d;
        }
    }

    function get_current_altitude() {
        return $this->current_altitude;
    }
}

class CruiseAltitudePlanner {
    public $trajectory;

    function __construct($trajectory) {
        $this->trajectory = $trajectory;
    }

    function plan_cruise() {
        while (true) {
            $this->trajectory->adjust_altitude();
            $current_altitude = $this->trajectory->get_current_altitude();
            if ($current_altitude == $this->trajectory->t) {
                $this->trajectory->is_ascent = true;
            }
        }
    }
}

class FlightControlSystem {
    public $planner;

    function __construct($planner) {
        $this->planner = $planner;
    }

    function execute() {
        while (true) {
            $this->planner->plan_cruise();
        }
    }
}

function main() {
    $initial_altitude = 5000.0;
    $target_altitude = 35000.0;
    $rate_of_climb = 100.0;
    $descent_rate = 50.0;
    $trajectory = new FlightTrajectory($initial_altitude, $target_altitude, $rate_of_climb, $descent_rate);
    $planner = new CruiseAltitudePlanner($trajectory);
    $control_system = new FlightControlSystem($planner);
    $control_system->execute();
}

main();