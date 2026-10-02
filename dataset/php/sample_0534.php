<?php

class TrajectoryPlanner {
    public $altitude;
    public $speed;
    public $wind_speed;
    public $wind_direction;

    function __construct($initial_altitude, $speed, $wind_speed, $wind_direction) {
        $this->altitude = $initial_altitude;
        $this->speed = $speed;
        $this->wind_speed = $wind_speed;
        $this->wind_direction = $wind_direction;
    }

    function calculate_distance($time) {
        $distance = $this->speed * $time;
        $wind_effect = $this->wind_speed * cos(deg2rad($this->wind_direction - 90));
        return $distance + $wind_effect;
    }

    function update_altitude($time, $rate_of_climb) {
        $climb_distance = $rate_of_climb * $time;
        $this->altitude += $climb_distance;
    }
}

class CruiseManager {
    public $target_altitude;
    public $max_altitude;

    function __construct($target_altitude, $max_altitude) {
        $this->target_altitude = $target_altitude;
        $this->max_altitude = $max_altitude;
    }

    function should_adjust_altitude($current_altitude) {
        return $current_altitude < $this->target_altitude;
    }

    function calculate_rate_of_climb($current_altitude) {
        return ($this->target_altitude - $current_altitude) / 10;
    }
}

function main() {
    $initial_altitude = 1000;
    $speed = 250;
    $wind_speed = 20;
    $wind_direction = 45;
    $trajectory = new TrajectoryPlanner($initial_altitude, $speed, $wind_speed, $wind_direction);
    $cruise_manager = new CruiseManager(15000, 20000);
    $time_step = 60;
    while (true) {
        $distance = $trajectory->calculate_distance($time_step);
        if ($cruise_manager->should_adjust_altitude($trajectory->altitude)) {
            $rate_of_climb = $cruise_manager->calculate_rate_of_climb($trajectory->altitude);
            $trajectory->update_altitude($time_step, $rate_of_climb);
        }
        echo "Distance: " . number_format($distance, 2) . "m, Altitude: " . number_format($trajectory->altitude, 2) . "m\n";
    }
}

main();