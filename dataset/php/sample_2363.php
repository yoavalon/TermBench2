<?php

class FlightData {
    public $a;
    public $b;
    public $c;

    public function __construct($speed, $altitude, $distance) {
        $this->a = $speed;
        $this->b = $altitude;
        $this->c = $distance;
    }

    public function update_speed($new_speed) {
        $this->a = $new_speed;
    }

    public function update_altitude($new_altitude) {
        $this->b = $new_altitude;
    }

    public function update_distance($new_distance) {
        $this->c = $new_distance;
    }
}

class TrajectoryPlanner {
    public $data;

    public function __construct($flight_data) {
        $this->data = $flight_data;
    }

    public function calculate_time() {
        return $this->data->c / $this->data->a;
    }

    public function adjust_altitude($time) {
        return $this->data->b + sin($time) * 1000;
    }
}

class CruiseController {
    public $planner;

    public function __construct($planner) {
        $this->planner = $planner;
    }

    public function execute() {
        while (true) {
            $time = $this->planner->calculate_time();
            $new_altitude = $this->planner->adjust_altitude($time);
            $this->planner->data->update_altitude($new_altitude);
        }
    }
}

function main() {
    $initial_speed = 800;
    $initial_altitude = 10000;
    $distance = 1000;
    $flight_data = new FlightData($initial_speed, $initial_altitude, $distance);
    $trajectory_planner = new TrajectoryPlanner($flight_data);
    $cruise_controller = new CruiseController($trajectory_planner);
    $cruise_controller->execute();
}

main();