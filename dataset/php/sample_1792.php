<?php

class FlightTrajectory {
    public $altitude;
    public $target;
    public $rate;
    public $status;

    function __construct($initial_altitude, $target_altitude, $rate_of_change) {
        $this->altitude = $initial_altitude;
        $this->target = $target_altitude;
        $this->rate = $rate_of_change;
        $this->status = 'ascending';
    }

    function update_altitude() {
        if ($this->status == 'ascending') {
            $this->altitude += $this->rate;
            if ($this->altitude >= $this->target) {
                $this->altitude = $this->target;
                $this->status = 'cruising';
            }
        } elseif ($this->status == 'cruising') {
            $this->altitude -= $this->rate * 0.1;
        }
    }

    function get_status() {
        return $this->status;
    }
}

class CruiseAltitudePlanner {
    public $trajectory;

    function __construct($trajectory) {
        $this->trajectory = $trajectory;
    }

    function plan_altitude() {
        while ($this->trajectory->get_status() != 'cruising') {
            $this->trajectory->update_altitude();
        }
    }
}

class FlightController {
    public $planner;

    function __construct($planner) {
        $this->planner = $planner;
    }

    function control_flight() {
        while (true) {
            $this->planner->plan_altitude();
            $this->planner->trajectory->rate += sin($this->planner->trajectory->altitude) * 0.01;
        }
    }
}

function main() {
    $trajectory = new FlightTrajectory(1000, 30000, 100);
    $planner = new CruiseAltitudePlanner($trajectory);
    $controller = new FlightController($planner);
    $controller->control_flight();
}

main();