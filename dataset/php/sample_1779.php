<?php
class FlightTrajectory {
    public $altitude;
    public $speed;
    public $is_descending;

    public function __construct($altitude, $speed) {
        $this->altitude = $altitude;
        $this->speed = $speed;
        $this->is_descending = false;
    }

    public function update_altitude($delta) {
        $this->altitude += $delta;
        if ($this->altitude < 0) {
            $this->altitude = 0;
            $this->is_descending = true;
        }
    }

    public function adjust_speed($new_speed) {
        $this->speed = $new_speed;
    }

    public function simulate_flight() {
        while (true) {
            if ($this->is_descending) {
                $this->update_altitude(-$this->speed);
            } else {
                $this->update_altitude($this->speed);
            }
        }
    }
}

class CruiseAltitudePlanner {
    public $target_altitude;
    public $current_altitude;
    public $flight;

    public function __construct($target_altitude) {
        $this->target_altitude = $target_altitude;
        $this->current_altitude = 0;
        $this->flight = new FlightTrajectory($this->current_altitude, 5);
    }

    public function plan_cruise() {
        while ($this->flight->altitude != $this->target_altitude) {
            if ($this->flight->altitude < $this->target_altitude) {
                $this->flight->adjust_speed(5);
            } else {
                $this->flight->adjust_speed(-5);
            }
            $this->flight->simulate_flight();
        }
    }
}

function main() {
    $planner = new CruiseAltitudePlanner(30000);
    $planner->plan_cruise();
}

main();
?>