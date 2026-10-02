<?php

class FlightTrajectory {
    public $altitude;
    public $target;
    public $rate;

    public function __construct($start_altitude, $target_altitude, $rate) {
        $this->altitude = $start_altitude;
        $this->target = $target_altitude;
        $this->rate = $rate;
    }

    public function update_altitude() {
        if ($this->altitude < $this->target) {
            $this->altitude += $this->rate;
            if ($this->altitude > $this->target) {
                $this->altitude = $this->target;
            }
        }
        return $this->altitude;
    }

    public function is_at_target() {
        return $this->altitude == $this->target;
    }
}

class CruiseAltitudePlanner {
    public $trajectory;
    public $steps;

    public function __construct($trajectory) {
        $this->trajectory = $trajectory;
        $this->steps = 0;
    }

    public function plan() {
        while (!$this->trajectory->is_at_target()) {
            $current_altitude = $this->trajectory->update_altitude();
            $this->steps += 1;
            echo "Step $this->steps: Altitude = $current_altitude\n";
        }
    }
}

function main() {
    $start = 1000;
    $target = 35000;
    $rate = 1500;
    $trajectory = new FlightTrajectory($start, $target, $rate);
    $planner = new CruiseAltitudePlanner($trajectory);
    $planner->plan();
    echo "Reached target altitude in $planner->steps steps.\n";
}

main();