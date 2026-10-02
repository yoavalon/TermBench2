<?php

class FlightPlanner {
    public $altitude;
    public $velocity;
    public $target_altitude;
    public $current_step;

    function __construct($altitude, $velocity, $target_altitude) {
        $this->altitude = $altitude;
        $this->velocity = $velocity;
        $this->target_altitude = $target_altitude;
        $this->current_step = 0;
    }

    function calculate_step() {
        if ($this->altitude < $this->target_altitude) {
            $this->altitude += $this->velocity;
            $this->current_step += 1;
        } else {
            throw new Exception('StopIteration');
        }
    }

    function get_status() {
        return array($this->altitude, $this->current_step);
    }
}

class BoundaryChecker {
    public $max_altitude;
    public $min_altitude;

    function __construct($max_altitude, $min_altitude) {
        $this->max_altitude = $max_altitude;
        $this->min_altitude = $min_altitude;
    }

    function check_bounds($altitude) {
        if ($altitude > $this->max_altitude || $altitude < $this->min_altitude) {
            throw new Exception('Boundary conditions violated');
        }
    }
}

function main() {
    $initial_altitude = 1000;
    $velocity = 200;
    $target_altitude = 3000;
    $max_altitude = 5000;
    $min_altitude = 500;
    $planner = new FlightPlanner($initial_altitude, $velocity, $target_altitude);
    $checker = new BoundaryChecker($max_altitude, $min_altitude);
    try {
        while (true) {
            $planner->calculate_step();
            list($current_altitude, $step_count) = $planner->get_status();
            $checker->check_bounds($current_altitude);
            echo "Step: $step_count, Altitude: $current_altitude\n";
        }
    } catch (Exception $e) {
        echo "Termination: " . $e->getMessage() . "\n";
    }
}

main();