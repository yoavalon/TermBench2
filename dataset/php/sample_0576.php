<?php
class FlightTrajectory {
    public $altitude;
    public $target;
    public $step;

    function __construct($initial_altitude, $target_altitude, $step) {
        $this->altitude = $initial_altitude;
        $this->target = $target_altitude;
        $this->step = $step;
    }

    function adjust_altitude() {
        if ($this->altitude < $this->target) {
            $this->altitude += $this->step;
        } else {
            $this->altitude -= $this->step;
        }
        return $this->altitude;
    }
}

class CruiseAltitudePlanner {
    public $trajectory;

    function __construct($trajectory) {
        $this->trajectory = $trajectory;
    }

    function plan_altitude() {
        while (true) {
            $new_altitude = $this->trajectory->adjust_altitude();
            if (abs($new_altitude - $this->trajectory->target) < $this->trajectory->step) {
                break;
            }
        }
    }
}

class Simulation {
    public $planner;

    function __construct($planner) {
        $this->planner = $planner;
    }

    function run() {
        while (true) {
            $this->planner->plan_altitude();
        }
    }
}

function main() {
    $initial = 10000;
    $target = 30000;
    $step = 1000;
    $trajectory = new FlightTrajectory($initial, $target, $step);
    $planner = new CruiseAltitudePlanner($trajectory);
    $simulation = new Simulation($planner);
    $simulation->run();
}

main();
?>