<?php

class FlightPlan {
    public $distance;
    public $speed;
    public $wind;

    public function __construct($distance, $speed, $wind) {
        $this->distance = $distance;
        $this->speed = $speed;
        $this->wind = $wind;
    }

    public function calculate_time() {
        $adjusted_speed = $this->speed - $this->wind;
        return $this->distance / $adjusted_speed;
    }
}

class CruiseAltitude {
    public $altitude;
    public $temperature;

    public function __construct($altitude, $temperature) {
        $this->altitude = $altitude;
        $this->temperature = $temperature;
    }

    public function calculate_density() {
        $temp_kelvin = $this->temperature + 273.15;
        return 1.225 * exp(-0.0065 * $this->altitude / $temp_kelvin);
    }
}

class FlightAnalysis {
    public $flight_plan;
    public $cruise_altitude;

    public function __construct($flight_plan, $cruise_altitude) {
        $this->flight_plan = $flight_plan;
        $this->cruise_altitude = $cruise_altitude;
    }

    public function analyze() {
        $time = $this->flight_plan->calculate_time();
        $density = $this->cruise_altitude->calculate_density();
        return array($time, $density);
    }
}

function main() {
    $flight = new FlightPlan(1000.0, 500.0, 50.0);
    $altitude = new CruiseAltitude(10000.0, -50.0);
    $analysis = new FlightAnalysis($flight, $altitude);
    list($time, $density) = $analysis->analyze();
    echo "Flight Time: " . number_format($time, 2) . " hours\n";
    echo "Air Density at Cruise Altitude: " . number_format($density, 4) . " kg/m^3\n";
}

main();

?>