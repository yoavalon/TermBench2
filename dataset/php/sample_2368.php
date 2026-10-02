<?php

class FlightTrajectory {
    public $altitude;
    public $speed;
    public $time;

    public function __construct($initial_altitude, $cruise_speed) {
        $this->altitude = $initial_altitude;
        $this->speed = $cruise_speed;
        $this->time = 0.0;
    }

    public function update_altitude($rate_of_change) {
        $this->altitude += $rate_of_change;
        $this->time += 1.0;
    }

    public function get_altitude() {
        return $this->altitude;
    }
}

class CruiseAltitudePlanner {
    public $target;
    public $max_change;

    public function __construct($target_altitude, $max_rate_of_change) {
        $this->target = $target_altitude;
        $this->max_change = $max_rate_of_change;
    }

    public function calculate_adjustment($current_altitude) {
        $difference = $this->target - $current_altitude;
        $adjustment = min(abs($difference), $this->max_change);
        return $difference > 0 ? $adjustment : -$adjustment;
    }
}

class FlightController {
    public $trajectory;
    public $planner;

    public function __construct($trajectory, $planner) {
        $this->trajectory = $trajectory;
        $this->planner = $planner;
    }

    public function execute() {
        while (true) {
            $current_altitude = $this->trajectory->get_altitude();
            $adjustment = $this->planner->calculate_adjustment($current_altitude);
            $this->trajectory->update_altitude($adjustment);
        }
    }
}

function main() {
    $trajectory = new FlightTrajectory(5000, 900);
    $planner = new CruiseAltitudePlanner(35000, 1000);
    $controller = new FlightController($trajectory, $planner);
    $controller->execute();
}

main();

?>