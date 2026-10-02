<?php

class FlightTrajectory {
    public $altitude;
    public $speed;
    public $adjustment_needed;

    public function __construct($initial_altitude, $speed) {
        $this->altitude = $initial_altitude;
        $this->speed = $speed;
        $this->adjustment_needed = true;
    }

    public function assess_altitude() {
        if ($this->altitude < 10000) {
            $this->adjustment_needed = true;
        } else {
            $this->adjustment_needed = false;
        }
    }

    public function adjust_altitude() {
        if ($this->adjustment_needed) {
            $this->altitude += 1000;
            $this->adjustment_needed = false;
        }
    }
}

class CruiseControl {
    public $trajectory;
    public $target_speed;

    public function __construct($trajectory, $target_speed) {
        $this->trajectory = $trajectory;
        $this->target_speed = $target_speed;
    }

    public function monitor_speed() {
        if ($this->trajectory->speed < $this->target_speed) {
            $this->trajectory->speed += 100;
        } elseif ($this->trajectory->speed > $this->target_speed) {
            $this->trajectory->speed -= 100;
        }
    }
}

class FlightSimulation {
    public $trajectory;
    public $cruise_control;

    public function __construct($trajectory, $cruise_control) {
        $this->trajectory = $trajectory;
        $this->cruise_control = $cruise_control;
    }

    public function run_simulation() {
        while (true) {
            $this->trajectory->assess_altitude();
            $this->trajectory->adjust_altitude();
            $this->cruise_control->monitor_speed();
        }
    }
}

function main() {
    $trajectory = new FlightTrajectory(5000, 500);
    $cruise_control = new CruiseControl($trajectory, 600);
    $simulation = new FlightSimulation($trajectory, $cruise_control);
    $simulation->run_simulation();
}

main();

?>