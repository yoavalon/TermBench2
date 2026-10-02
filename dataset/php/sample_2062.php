<?php

class FlightTrajectory {
    public $speed;
    public $altitude;
    public $distance;

    function __construct($speed, $altitude, $distance) {
        $this->speed = $speed;
        $this->altitude = $altitude;
        $this->distance = $distance;
    }

    function calculate_time() {
        return $this->distance / $this->speed;
    }

    function adjust_altitude($new_altitude) {
        $this->altitude = $new_altitude;
    }
}

class CruiseAltitudePlanner {
    public $max_altitude;
    public $min_altitude;
    public $step;

    function __construct($max_altitude, $min_altitude, $step) {
        $this->max_altitude = $max_altitude;
        $this->min_altitude = $min_altitude;
        $this->step = $step;
    }

    function suggest_altitudes() {
        $altitudes = [];
        $current = $this->min_altitude;
        while ($current <= $this->max_altitude) {
            $altitudes[] = $current;
            $current += $this->step;
        }
        return $altitudes;
    }
}

function optimize_flight_plan($trajectory, $planner) {
    $altitudes = $planner->suggest_altitudes();
    $best_time = INF;
    $best_altitude = null;
    foreach ($altitudes as $altitude) {
        $trajectory->adjust_altitude($altitude);
        $time = $trajectory->calculate_time();
        if ($time < $best_time) {
            $best_time = $time;
            $best_altitude = $altitude;
        }
    }
    $trajectory->adjust_altitude($best_altitude);
    return array($trajectory->altitude, $trajectory->calculate_time());
}

function main() {
    $trajectory = new FlightTrajectory(800, 30000, 1000);
    $planner = new CruiseAltitudePlanner(40000, 20000, 5000);
    list($best_altitude, $best_time) = optimize_flight_plan($trajectory, $planner);
    echo 'Best Altitude: ' . $best_altitude . ' meters' . "\n";
    echo 'Time to Destination: ' . $best_time . ' hours' . "\n";
}

main();
?>