<?php

class FlightTrajectory {
    public $altitude;
    public $max_altitude;
    public $speed;

    public function __construct($initial_altitude, $max_altitude, $speed) {
        $this->altitude = $initial_altitude;
        $this->max_altitude = $max_altitude;
        $this->speed = $speed;
    }

    public function update_altitude($time) {
        $this->altitude += $this->speed * $time;
        if ($this->altitude > $this->max_altitude) {
            $this->altitude = $this->max_altitude;
        }
    }
}

class CruiseAltitudePlanner {
    public $trajectory;
    public $target_altitude;

    public function __construct($trajectory) {
        $this->trajectory = $trajectory;
        $this->target_altitude = $trajectory->max_altitude;
    }

    public function adjust_altitude($current_time) {
        if ($this->trajectory->altitude < $this->target_altitude) {
            $time_to_adjust = ($this->target_altitude - $this->trajectory->altitude) / $this->trajectory->speed;
            if ($current_time >= $time_to_adjust) {
                $this->trajectory->update_altitude($time_to_adjust);
            }
        }
    }
}

class TerminationChecker {
    public $trajectory;
    public $target_altitude;

    public function __construct($trajectory, $target_altitude) {
        $this->trajectory = $trajectory;
        $this->target_altitude = $target_altitude;
    }

    public function check() {
        return $this->trajectory->altitude >= $this->target_altitude;
    }
}

function main() {
    $initial_altitude = 1000;
    $max_altitude = 30000;
    $speed = 1500;
    $trajectory = new FlightTrajectory($initial_altitude, $max_altitude, $speed);
    $planner = new CruiseAltitudePlanner($trajectory);
    $checker = new TerminationChecker($trajectory, $max_altitude);
    $current_time = 0;
    $time_step = 10;
    while (!$checker->check()) {
        $planner->adjust_altitude($current_time);
        $current_time += $time_step;
    }
    echo 'Cruise altitude reached.';
}

main();

?>