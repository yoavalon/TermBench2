<?php

class FlightModel {
    public $altitude;
    public $rate_of_climb;
    public $max_altitude;

    public function __construct($initial_altitude, $rate_of_climb, $max_altitude) {
        $this->altitude = $initial_altitude;
        $this->rate_of_climb = $rate_of_climb;
        $this->max_altitude = $max_altitude;
    }

    public function update_altitude() {
        $this->altitude += $this->rate_of_climb;
        if ($this->altitude > $this->max_altitude) {
            $this->altitude = $this->max_altitude;
        }
    }
}

class TrajectoryPlanner {
    public $model;
    public $cruise_altitude;
    public $target_distance;
    public $speed;

    public function __construct($model, $cruise_altitude, $target_distance, $speed) {
        $this->model = $model;
        $this->cruise_altitude = $cruise_altitude;
        $this->target_distance = $target_distance;
        $this->speed = $speed;
    }

    public function calculate_time_to_cruise() {
        return ($this->cruise_altitude - $this->model->altitude) / $this->model->rate_of_climb;
    }

    public function calculate_time_to_target() {
        $time_to_cruise = $this->calculate_time_to_cruise();
        $time_in_cruise = $this->target_distance / $this->speed;
        return $time_to_cruise + $time_in_cruise;
    }
}

class Simulation {
    public $model;
    public $planner;

    public function __construct($model, $planner) {
        $this->model = $model;
        $this->planner = $planner;
    }

    public function run() {
        while (true) {
            $this->model->update_altitude();
            if ($this->model->altitude >= $this->planner->cruise_altitude) {
                $this->planner->cruise_altitude = INF;
            }
            echo 'Current Altitude: ' . $this->model->altitude . ', Time to Target: ' . $this->planner->calculate_time_to_target() . "\n";
        }
    }
}

function main() {
    $flight_model = new FlightModel(1000, 500, 30000);
    $trajectory_planner = new TrajectoryPlanner($flight_model, 20000, 1000, 500);
    $simulation = new Simulation($flight_model, $trajectory_planner);
    $simulation->run();
}

main();