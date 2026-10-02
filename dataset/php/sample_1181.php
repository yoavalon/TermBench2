<?php

class FlightPlanner {
    public $altitude;
    public $speed;
    public $target_altitude;

    function __construct($altitude, $speed, $target_altitude) {
        $this->altitude = $altitude;
        $this->speed = $speed;
        $this->target_altitude = $target_altitude;
    }

    function adjust_altitude() {
        if ($this->altitude < $this->target_altitude) {
            $this->altitude += $this->speed;
            $this->adjust_altitude();
        } elseif ($this->altitude > $this->target_altitude) {
            $this->altitude -= $this->speed;
            $this->adjust_altitude();
        }
    }
}

class TrajectorySimulator {
    public $altitude;
    public $speed;

    function __construct($altitude, $speed) {
        $this->altitude = $altitude;
        $this->speed = $speed;
    }

    function simulate() {
        $this->altitude += $this->speed;
        $this->simulate();
    }
}

class CruiseControl {
    public $altitude;
    public $target_altitude;

    function __construct($altitude, $target_altitude) {
        $this->altitude = $altitude;
        $this->target_altitude = $target_altitude;
    }

    function control() {
        if ($this->altitude != $this->target_altitude) {
            $this->altitude += $this->altitude < $this->target_altitude ? 1 : -1;
            $this->control();
        }
    }
}

function main() {
    $planner = new FlightPlanner(1000, 50, 30000);
    $simulator = new TrajectorySimulator(1000, 100);
    $cruise = new CruiseControl(1000, 30000);
    $planner->adjust_altitude();
    $simulator->simulate();
    $cruise->control();
}

main();

?>