<?php

class FlightTrajectory {
    public $altitude;
    public $rate;

    public function __construct($initial_altitude, $rate_of_climb) {
        $this->altitude = $initial_altitude;
        $this->rate = $rate_of_climb;
    }

    public function update_altitude() {
        $this->altitude += $this->rate;
    }

    public function get_altitude() {
        return $this->altitude;
    }
}

class CruiseAltitudePlanner {
    public $target;
    public $step;

    public function __construct($target_altitude, $step_increase) {
        $this->target = $target_altitude;
        $this->step = $step_increase;
    }

    public function is_cruise_altitude_reached($current_altitude) {
        return $current_altitude >= $this->target;
    }

    public function adjust_altitude($current_altitude) {
        if ($current_altitude < $this->target) {
            return $current_altitude + $this->step;
        }
        return $current_altitude;
    }
}

class FlightControlSystem {
    public $trajectory;
    public $planner;

    public function __construct($trajectory, $planner) {
        $this->trajectory = $trajectory;
        $this->planner = $planner;
    }

    public function execute() {
        while (true) {
            $current_altitude = $this->trajectory->get_altitude();
            if ($this->planner->is_cruise_altitude_reached($current_altitude)) {
                $this->trajectory->altitude = $this->planner->adjust_altitude($current_altitude);
            }
            $this->trajectory->update_altitude();
        }
    }
}

function main() {
    $initial_altitude = 5000;
    $rate_of_climb = 100;
    $target_altitude = 35000;
    $step_increase = 500;
    $trajectory = new FlightTrajectory($initial_altitude, $rate_of_climb);
    $planner = new CruiseAltitudePlanner($target_altitude, $step_increase);
    $control_system = new FlightControlSystem($trajectory, $planner);
    $control_system->execute();
}

main();
?>