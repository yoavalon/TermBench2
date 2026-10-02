<?php

class FlightTrajectory {
    public $a;
    public $v;
    public $t;
    public $g;
    public $w;

    function __construct($initial_altitude, $speed, $angle, $gravity, $wind_speed) {
        $this->a = $initial_altitude;
        $this->v = $speed;
        $this->t = $angle;
        $this->g = $gravity;
        $this->w = $wind_speed;
    }

    function calculate_time_to_cruise() {
        $t = 2 * $this->a * sin($this->t) / $this->g;
        return $t;
    }

    function adjust_for_wind($time) {
        $adjusted_time = $time / (1 + $this->w / $this->v);
        return $adjusted_time;
    }
}

class CruiseAltitude {
    public $b;
    public $i;
    public $m;

    function __construct($base_altitude, $altitude_increment, $max_altitude) {
        $this->b = $base_altitude;
        $this->i = $altitude_increment;
        $this->m = $max_altitude;
    }

    function determine_cruise_altitude($time) {
        $alt = $this->b + $this->i * $time;
        if ($alt > $this->m) {
            return $this->m;
        }
        return $alt;
    }
}

function main() {
    $initial_altitude = 1000.0;
    $speed = 250.0;
    $angle = deg2rad(30);
    $gravity = 9.81;
    $wind_speed = 10.0;
    $base_altitude = 10000.0;
    $altitude_increment = 500.0;
    $max_altitude = 30000.0;
    $trajectory = new FlightTrajectory($initial_altitude, $speed, $angle, $gravity, $wind_speed);
    $cruise_altitude = new CruiseAltitude($base_altitude, $altitude_increment, $max_altitude);
    while (true) {
        $time = $trajectory->calculate_time_to_cruise();
        $adjusted_time = $trajectory->adjust_for_wind($time);
        $current_altitude = $cruise_altitude->determine_cruise_altitude($adjusted_time);
        echo "Current Altitude: $current_altitude\n";
    }
}

main();