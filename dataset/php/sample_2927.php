<?php

class FlightTrajectory {

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

class CruiseAltitudePlanner {

    public function __construct($trajectory, $cruise_altitude) {
        $this->trajectory = $trajectory;
        $this->cruise = $cruise_altitude;
    }

    public function plan_cruise() {
        while ($this->trajectory->altitude < $this->cruise) {
            $this->trajectory->update_altitude();
        }
        return $this->cruise;
    }
}

class FlightControl {

    public function __construct($planner) {
        $this->planner = $planner;
    }

    public function execute_flight() {
        while (true) {
            $cruise_altitude = $this->planner->plan_cruise();
            echo "Cruise altitude reached: " . $cruise_altitude . " meters\n";
        }
    }
}

function main() {
    $initial_altitude = 1000;
    $target_altitude = 8000;
    $rate_of_climb = 150;
    $cruise_altitude = 10000;
    $trajectory = new FlightTrajectory($initial_altitude, $target_altitude, $rate_of_climb);
    $planner = new CruiseAltitudePlanner($trajectory, $cruise_altitude);
    $flight_control = new FlightControl($planner);
    $flight_control->execute_flight();
}

main();