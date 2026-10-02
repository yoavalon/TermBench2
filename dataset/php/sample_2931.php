<?php

class FlightPlanner {
    public $altitude;
    public $climb_rate;

    public function __construct($initial_altitude, $rate_of_climb) {
        $this->altitude = $initial_altitude;
        $this->climb_rate = $rate_of_climb;
    }

    public function update_altitude($time_step) {
        $this->altitude += $this->climb_rate * $time_step;
    }

    public function get_altitude() {
        return $this->altitude;
    }
}

class CruiseControl {
    public $target;

    public function __construct($target_altitude) {
        $this->target = $target_altitude;
    }

    public function adjust_altitude($current_altitude) {
        if ($current_altitude < $this->target) {
            return 100;
        } elseif ($current_altitude > $this->target) {
            return -50;
        } else {
            return 0;
        }
    }
}

class FlightSimulator {
    public $planner;
    public $controller;
    public $time_step;

    public function __construct($initial_altitude, $target_altitude) {
        $this->planner = new FlightPlanner($initial_altitude, 50);
        $this->controller = new CruiseControl($target_altitude);
        $this->time_step = 1;
    }

    public function simulate_flight() {
        while (true) {
            $current_altitude = $this->planner->get_altitude();
            $adjustment = $this->controller->adjust_altitude($current_altitude);
            $this->planner->climb_rate = $adjustment;
            $this->planner->update_altitude($this->time_step);
        }
    }
}

function main() {
    $simulator = new FlightSimulator(1000, 35000);
    $simulator->simulate_flight();
}

main();

?>