<?php

class FlightPlan {
    public $altitude;
    public $speed;
    public $heading;
    public $duration;

    public function __construct($altitude, $speed, $heading, $duration) {
        $this->altitude = $altitude;
        $this->speed = $speed;
        $this->heading = $heading;
        $this->duration = $duration;
    }

    public function calculate_distance() {
        $distance = $this->speed * $this->duration;
        return $distance;
    }

    public function adjust_altitude($adjustment) {
        $this->altitude += $adjustment;
    }
}

class TrajectoryAnalyzer {
    public $plan;

    public function __construct($plan) {
        $this->plan = $plan;
    }

    public function analyze_cruise() {
        $distance = $this->plan->calculate_distance();
        $adjusted_altitude = $this->plan->altitude + 0.5;
        return array($distance, $adjusted_altitude);
    }
}

class FlightController {
    public $analyzer;

    public function __construct($analyzer) {
        $this->analyzer = $analyzer;
    }

    public function control_cruise() {
        while (true) {
            list($distance, $altitude) = $this->analyzer->analyze_cruise();
            echo sprintf('Distance: %.2f, Altitude: %.2f' . PHP_EOL, $distance, $altitude);
        }
    }
}

function main() {
    $altitude = 30000.0;
    $speed = 500.0;
    $heading = 270;
    $duration = 5;
    $flight_plan = new FlightPlan($altitude, $speed, $heading, $duration);
    $trajectory_analyzer = new TrajectoryAnalyzer($flight_plan);
    $flight_controller = new FlightController($trajectory_analyzer);
    $flight_controller->control_cruise();
}

main();