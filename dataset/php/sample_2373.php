<?php

class FlightTrajectory {
    public $altitude;
    public $speed;
    public $wind;
    public $time;

    function __construct($initial_altitude, $cruising_speed, $wind_speed) {
        $this->altitude = $initial_altitude;
        $this->speed = $cruising_speed;
        $this->wind = $wind_speed;
        $this->time = 0;
    }

    function update_altitude($altitude_change) {
        $this->altitude += $altitude_change;
    }

    function update_time($increment) {
        $this->time += $increment;
    }
}

class CruiseAltitudePlanner {
    public $target;
    public $max_change;

    function __construct($target_altitude, $max_altitude_change) {
        $this->target = $target_altitude;
        $this->max_change = $max_altitude_change;
    }

    function calculate_adjustment($current_altitude) {
        return min(max($this->target - $current_altitude, -$this->max_change), $this->max_change);
    }
}

class FlightController {
    public $trajectory;
    public $planner;
    public $interval;

    function __construct($trajectory, $planner) {
        $this->trajectory = $trajectory;
        $this->planner = $planner;
        $this->interval = 1.0;
    }

    function control_loop() {
        while (true) {
            $adjustment = $this->planner->calculate_adjustment($this->trajectory->altitude);
            $this->trajectory->update_altitude($adjustment);
            $this->trajectory->update_time($this->interval);
        }
    }
}

function main() {
    $initial_altitude = 30000;
    $cruising_speed = 800;
    $wind_speed = 50;
    $target_altitude = 35000;
    $max_altitude_change = 500;
    $trajectory = new FlightTrajectory($initial_altitude, $cruising_speed, $wind_speed);
    $planner = new CruiseAltitudePlanner($target_altitude, $max_altitude_change);
    $controller = new FlightController($trajectory, $planner);
    $controller->control_loop();
}

main();

?>