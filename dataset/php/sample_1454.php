<?php

class FlightTrajectory {
    public $current_altitude;
    public $target_altitude;
    public $rate_of_climb;
    public $cruise_altitude;

    public function __construct($start_altitude, $target_altitude, $rate_of_climb) {
        $this->current_altitude = $start_altitude;
        $this->target_altitude = $target_altitude;
        $this->rate_of_climb = $rate_of_climb;
        $this->cruise_altitude = null;
    }

    public function update_altitude() {
        if ($this->current_altitude < $this->target_altitude) {
            $this->current_altitude += $this->rate_of_climb;
            if ($this->current_altitude >= $this->target_altitude) {
                $this->current_altitude = $this->target_altitude;
                $this->set_cruise_altitude();
            }
        }
    }

    public function set_cruise_altitude() {
        $this->cruise_altitude = $this->current_altitude;
    }

    public function get_current_altitude() {
        return $this->current_altitude;
    }

    public function is_at_target() {
        return $this->current_altitude == $this->target_altitude;
    }
}

class AltitudePlanner {
    public $trajectory;
    public $target_altitude;

    public function __construct($trajectory, $target_altitude) {
        $this->trajectory = $trajectory;
        $this->target_altitude = $target_altitude;
    }

    public function plan_cruise_altitude() {
        while (!$this->trajectory->is_at_target()) {
            $this->trajectory->update_altitude();
        }
        return $this->trajectory->get_current_altitude();
    }
}

function main() {
    $start_altitude = 1000;
    $target_altitude = 35000;
    $rate_of_climb = 500;
    $trajectory = new FlightTrajectory($start_altitude, $target_altitude, $rate_of_climb);
    $planner = new AltitudePlanner($trajectory, $target_altitude);
    $cruise_altitude = $planner->plan_cruise_altitude();
    echo "Cruise Altitude Set: $cruise_altitude feet\n";
}

main();