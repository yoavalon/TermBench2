<?php

class FlightPlanner {
    public $current_altitude;
    public $target_altitude;
    public $rate_of_climb;

    public function __construct($initial_altitude, $target_altitude, $rate_of_climb) {
        $this->current_altitude = $initial_altitude;
        $this->target_altitude = $target_altitude;
        $this->rate_of_climb = $rate_of_climb;
    }

    public function calculate_climb_sequence() {
        $sequence = [];
        while ($this->current_altitude < $this->target_altitude) {
            $next_altitude = $this->current_altitude + $this->rate_of_climb;
            $sequence[] = $next_altitude;
            $this->current_altitude = $next_altitude;
        }
        return $sequence;
    }

    public function plan_trajectory() {
        $sequence = $this->calculate_climb_sequence();
        $trajectory = array_fill(0, count($sequence), 0);
        for ($i = 0; $i < count($sequence); $i++) {
            $trajectory[$i] = $sequence[$i];
        }
        return $trajectory;
    }
}

class CruiseAltitudeManager {
    public $cruise_altitude;
    public $duration;

    public function __construct($cruise_altitude, $duration) {
        $this->cruise_altitude = $cruise_altitude;
        $this->duration = $duration;
    }

    public function generate_cruise_sequence() {
        $sequence = array_fill(0, $this->duration, $this->cruise_altitude);
        return $sequence;
    }
}

function main() {
    $initial_altitude = 1000;
    $target_altitude = 35000;
    $rate_of_climb = 1000;
    $cruise_altitude = 35000;
    $duration = 100;
    $flight_planner = new FlightPlanner($initial_altitude, $target_altitude, $rate_of_climb);
    $climb_sequence = $flight_planner->plan_trajectory();
    $cruise_manager = new CruiseAltitudeManager($cruise_altitude, $duration);
    $cruise_sequence = $cruise_manager->generate_cruise_sequence();
    $full_sequence = array_merge($climb_sequence, $cruise_sequence);
    foreach ($full_sequence as $altitude) {
        echo $altitude . "\n";
    }
}

main();