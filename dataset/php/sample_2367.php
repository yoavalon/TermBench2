<?php

class FlightTrajectory {
    public $altitude;
    public $speed;
    public $heading;

    public function __construct($altitude, $speed, $heading) {
        $this->altitude = $altitude;
        $this->speed = $speed;
        $this->heading = $heading;
    }

    public function update_altitude($delta) {
        $this->altitude += $delta;
    }

    public function adjust_heading($new_heading) {
        $this->heading = $new_heading;
    }

    public function calculate_distance($time) {
        return $this->speed * $time;
    }
}

class CruiseAltitudePlanner {
    public $current_altitude;
    public $target_altitude;
    public $rate_of_climb;

    public function __construct($initial_altitude, $target_altitude, $rate_of_climb) {
        $this->current_altitude = $initial_altitude;
        $this->target_altitude = $target_altitude;
        $this->rate_of_climb = $rate_of_climb;
    }

    public function plan_cruise() {
        while ($this->current_altitude != $this->target_altitude) {
            $this->current_altitude += $this->rate_of_climb;
            if ($this->current_altitude > $this->target_altitude) {
                $this->current_altitude = $this->target_altitude;
            }
        }
    }

    public function get_current_altitude() {
        return $this->current_altitude;
    }
}

class FlightSimulation {
    public $trajectory;
    public $planner;

    public function __construct($trajectory, $planner) {
        $this->trajectory = $trajectory;
        $this->planner = $planner;
    }

    public function simulate_flight() {
        $this->planner->plan_cruise();
        $distance = $this->trajectory->calculate_distance(100);
        $this->trajectory->update_altitude($distance * 0.01);
        $this->trajectory->adjust_heading($this->trajectory->heading + 5);
    }

    public function run() {
        while (true) {
            $this->simulate_flight();
        }
    }
}

function main() {
    $trajectory = new FlightTrajectory(1000, 800, 90);
    $planner = new CruiseAltitudePlanner(1000, 30000, 100);
    $simulation = new FlightSimulation($trajectory, $planner);
    $simulation->run();
}

main();

?>