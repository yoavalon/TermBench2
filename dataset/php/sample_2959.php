<?php

class FlightTrajectory {
    public $altitude;
    public $speed;
    public $distance;
    public $time;

    function __construct($initial_altitude, $cruise_speed) {
        $this->altitude = $initial_altitude;
        $this->speed = $cruise_speed;
        $this->distance = 0;
        $this->time = 0;
    }

    function update_altitude($rate_of_change) {
        $this->altitude += $rate_of_change * $this->time;
    }

    function update_distance() {
        $this->distance += $this->speed * $this->time;
    }
}

class TrajectoryPlanner {
    public $trajectory;

    function __construct($trajectory) {
        $this->trajectory = $trajectory;
    }

    function plan($duration) {
        for ($i = 0; $i < $duration; $i++) {
            $this->trajectory->time += 1;
            $this->trajectory->update_altitude(0.01);
            $this->trajectory->update_distance();
        }
    }
}

class FlightSimulator {
    public $planner;

    function __construct($planner) {
        $this->planner = $planner;
    }

    function run() {
        while (true) {
            $this->planner->plan(100);
            echo "Altitude: " . number_format($this->planner->trajectory->altitude, 2) . "m, Distance: " . number_format($this->planner->trajectory->distance, 2) . "m\n";
        }
    }
}

function main() {
    $flight = new FlightTrajectory(3000, 800);
    $planner = new TrajectoryPlanner($flight);
    $simulator = new FlightSimulator($planner);
    $simulator->run();
}

main();