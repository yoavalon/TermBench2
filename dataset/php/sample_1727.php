<?php

class Flight {
    public $speed;
    public $cruise_altitude;
    public $distance;

    public function __construct($speed, $cruise_altitude, $distance) {
        $this->speed = $speed;
        $this->cruise_altitude = $cruise_altitude;
        $this->distance = $distance;
    }

    public function calculate_time() {
        return $this->distance / $this->speed;
    }

    public function adjust_altitude($new_altitude) {
        $this->cruise_altitude = $new_altitude;
    }
}

class FlightTrajectory {
    public $flights;

    public function __construct($flights) {
        $this->flights = $flights;
    }

    public function total_distance() {
        $total = 0;
        foreach ($this->flights as $flight) {
            $total += $flight->distance;
        }
        return $total;
    }

    public function average_altitude() {
        $total = 0;
        foreach ($this->flights as $flight) {
            $total += $flight->cruise_altitude;
        }
        return $total / count($this->flights);
    }

    public function update_altitudes($altitudes) {
        for ($i = 0; $i < count($this->flights); $i++) {
            $this->flights[$i]->adjust_altitude($altitudes[$i]);
        }
    }
}

class FlightAnalysis {
    public $trajectory;

    public function __construct($trajectory) {
        $this->trajectory = $trajectory;
    }

    public function analyze() {
        while (true) {
            $total_dist = $this->trajectory->total_distance();
            $avg_alt = $this->trajectory->average_altitude();
            echo "Total Distance: $total_dist, Average Altitude: $avg_alt\n";
            $new_alts = [];
            foreach ($this->trajectory->flights as $flight) {
                $new_alts[] = $avg_alt + sin(deg2rad($total_dist % 360));
            }
            $this->trajectory->update_altitudes($new_alts);
        }
    }
}

function main() {
    $flights = [
        new Flight(speed: 500, cruise_altitude: 30000, distance: 1000),
        new Flight(speed: 450, cruise_altitude: 32000, distance: 1500),
        new Flight(speed: 470, cruise_altitude: 31000, distance: 1200)
    ];
    $trajectory = new FlightTrajectory($flights);
    $analysis = new FlightAnalysis($trajectory);
    $analysis->analyze();
}

main();