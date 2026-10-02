<?php

class FlightTrajectory {
    public $altitude;
    public $rate_of_climb;
    public $cruise_altitude;
    public $descent_rate;
    public $status;

    public function __construct($initial_altitude, $rate_of_climb, $cruise_altitude, $descent_rate) {
        $this->altitude = $initial_altitude;
        $this->rate_of_climb = $rate_of_climb;
        $this->cruise_altitude = $cruise_altitude;
        $this->descent_rate = $descent_rate;
        $this->status = 'climbing';
    }

    public function update_altitude() {
        if ($this->status == 'climbing') {
            if ($this->altitude + $this->rate_of_climb < $this->cruise_altitude) {
                $this->altitude += $this->rate_of_climb;
            } else {
                $this->altitude = $this->cruise_altitude;
                $this->status = 'cruising';
            }
        } elseif ($this->status == 'cruising') {
        } elseif ($this->status == 'descending') {
            if ($this->altitude - $this->descent_rate > 0) {
                $this->altitude -= $this->descent_rate;
            } else {
                $this->altitude = 0;
                $this->status = 'landed';
            }
        }
    }

    public function is_landed() {
        return $this->status == 'landed';
    }
}

class FlightPlanner {
    public $trajectory;

    public function __construct($trajectory) {
        $this->trajectory = $trajectory;
    }

    public function plan_flight() {
        while (!$this->trajectory->is_landed()) {
            $this->trajectory->update_altitude();
            $this->log_status();
        }
    }

    public function log_status() {
        echo "Altitude: " . $this->trajectory->altitude . ", Status: " . $this->trajectory->status . "\n";
    }
}

function main() {
    $initial_altitude = 0;
    $rate_of_climb = 1000;
    $cruise_altitude = 30000;
    $descent_rate = 500;
    $trajectory = new FlightTrajectory($initial_altitude, $rate_of_climb, $cruise_altitude, $descent_rate);
    $planner = new FlightPlanner($trajectory);
    $planner->plan_flight();
}

main();