<?php

class FlightPlanner {
    public $alt;
    public $speed;
    public $dest;
    public $dist;
    public $time;

    function __construct($alt, $speed, $dest) {
        $this->alt = $alt;
        $this->speed = $speed;
        $this->dest = $dest;
        $this->dist = 0;
        $this->time = 0;
    }

    function update($distance) {
        $this->dist += $distance;
        $this->time += $distance / $this->speed;
        return $this->time;
    }

    function adjust_altitude($new_alt) {
        $this->alt = $new_alt;
    }
}

class FlightSimulator {
    public $planner;
    public $altitude;
    public $speed;
    public $destination;

    function __construct($planner) {
        $this->planner = $planner;
        $this->altitude = $planner->alt;
        $this->speed = $planner->speed;
        $this->destination = $planner->dest;
    }

    function simulate_flight($distance) {
        $this->planner->update($distance);
        $this->altitude = $this->planner->alt;
        $this->speed = $this->planner->speed;
        return $this->planner->time;
    }
}

class FlightController {
    public $simulator;

    function __construct($simulator) {
        $this->simulator = $simulator;
    }

    function control_flight($distance) {
        while (true) {
            $this->simulator->simulate_flight($distance);
            $this->adjust_altitude($this->simulator->altitude);
            $this->adjust_speed($this->simulator->speed);
        }
    }

    function adjust_altitude($alt) {
        $this->simulator->planner->adjust_altitude($alt);
    }

    function adjust_speed($speed) {
        $this->simulator->speed = $speed;
    }
}

function main() {
    $planner = new FlightPlanner(30000, 500, 'New York');
    $simulator = new FlightSimulator($planner);
    $controller = new FlightController($simulator);
    $controller->control_flight(1000);
}

main();