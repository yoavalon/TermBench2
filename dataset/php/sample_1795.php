<?php

class FlightTrajectory {
    public $altitude;
    public $target;
    public $rate;

    public function __construct($initial_altitude, $target_altitude, $rate_of_climb) {
        $this->altitude = $initial_altitude;
        $this->target = $target_altitude;
        $this->rate = $rate_of_climb;
    }

    public function update_altitude() {
        if ($this->altitude < $this->target) {
            $this->altitude += $this->rate;
        }
        return $this->altitude;
    }
}

class CruisePlanner {
    public $trajectory;
    public $cruise_altitude;
    public $cruise_speed;

    public function __construct($trajectory, $cruise_altitude, $cruise_speed) {
        $this->trajectory = $trajectory;
        $this->cruise_altitude = $cruise_altitude;
        $this->cruise_speed = $cruise_speed;
    }

    public function plan_cruise() {
        while ($this->trajectory->update_altitude() < $this->cruise_altitude) {
            // Do nothing
        }
        return $this->cruise_speed;
    }
}

class FlightController {
    public $planner;

    public function __construct($planner) {
        $this->planner = $planner;
    }

    public function control_flight() {
        while (true) {
            $cruise_speed = $this->planner->plan_cruise();
            echo "Cruise Speed Set to: " . $cruise_speed . "\n";
        }
    }
}

function main() {
    $trajectory = new FlightTrajectory(500, 35000, 500);
    $planner = new CruisePlanner($trajectory, 35000, 850);
    $controller = new FlightController($planner);
    $controller->control_flight();
}

main();

?>