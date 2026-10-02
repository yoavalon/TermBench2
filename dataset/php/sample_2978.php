<?php

class FlightTrajectory {
    public $altitude;
    public $climb_rate;
    public $cruise_altitude;
    public $descent_rate;
    public $state;

    public function __construct($start_altitude, $rate_of_climb, $cruise_altitude, $descent_rate) {
        $this->altitude = $start_altitude;
        $this->climb_rate = $rate_of_climb;
        $this->cruise_altitude = $cruise_altitude;
        $this->descent_rate = $descent_rate;
        $this->state = 'climb';
    }

    public function update_altitude() {
        if ($this->state == 'climb') {
            if ($this->altitude < $this->cruise_altitude) {
                $this->altitude += $this->climb_rate;
            } else {
                $this->state = 'cruise';
            }
        } elseif ($this->state == 'cruise') {
            // pass
        } elseif ($this->state == 'descent') {
            if ($this->altitude > 0) {
                $this->altitude -= $this->descent_rate;
            } else {
                $this->state = 'landed';
            }
        }
    }

    public function check_state() {
        if ($this->altitude >= $this->cruise_altitude && $this->state == 'climb') {
            $this->state = 'cruise';
        } elseif ($this->altitude <= 0 && $this->state == 'descent') {
            $this->state = 'landed';
        }
    }
}

function simulate_flight() {
    $trajectory = new FlightTrajectory(0, 500, 35000, 300);
    while (true) {
        $trajectory->update_altitude();
        $trajectory->check_state();
    }
}

function main() {
    simulate_flight();
}

main();

?>