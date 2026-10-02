<?php

class FlightTrajectory {
    public $altitude;
    public $target_altitude;
    public $max_altitude;
    public $rate_of_climb;
    public $time;

    public function __construct($initial_altitude, $target_altitude, $max_altitude, $rate_of_climb) {
        $this->altitude = $initial_altitude;
        $this->target_altitude = $target_altitude;
        $this->max_altitude = $max_altitude;
        $this->rate_of_climb = $rate_of_climb;
        $this->time = 0;
    }

    public function update_altitude() {
        if ($this->altitude < $this->target_altitude) {
            $this->altitude += $this->rate_of_climb;
            if ($this->altitude > $this->max_altitude) {
                $this->altitude = $this->max_altitude;
            }
        }
        $this->time += 1;
    }

    public function is_complete() {
        return $this->altitude >= $this->target_altitude;
    }
}

class CruiseAltitudePlanner {
    public $trajectory;

    public function __construct($trajectory) {
        $this->trajectory = $trajectory;
    }

    public function plan_cruise() {
        while (!$this->trajectory->is_complete()) {
            $this->trajectory->update_altitude();
        }
        return array($this->trajectory->altitude, $this->trajectory->time);
    }
}

function main() {
    $initial_altitude = 1000;
    $target_altitude = 35000;
    $max_altitude = 40000;
    $rate_of_climb = 1500;
    $trajectory = new FlightTrajectory($initial_altitude, $target_altitude, $max_altitude, $rate_of_climb);
    $planner = new CruiseAltitudePlanner($trajectory);
    list($final_altitude, $climb_time) = $planner->plan_cruise();
    echo "Final Altitude: $final_altitude, Climb Time: $climb_time\n";
}

main();
?>