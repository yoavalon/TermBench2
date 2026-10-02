<?php

class FlightData {
    public $altitude;
    public $speed;
    public $distance;
    public $max_altitude;

    function __construct($altitude, $speed, $distance, $max_altitude) {
        $this->altitude = $altitude;
        $this->speed = $speed;
        $this->distance = $distance;
        $this->max_altitude = $max_altitude;
    }

    function update_altitude($new_altitude) {
        if ($new_altitude <= $this->max_altitude) {
            $this->altitude = $new_altitude;
        } else {
            $this->altitude = $this->max_altitude;
        }
    }

    function update_distance($new_distance) {
        $this->distance = $new_distance;
    }
}

class CruisePlanner {
    public $flight_data;

    function __construct($flight_data) {
        $this->flight_data = $flight_data;
    }

    function calculate_cruise_altitude() {
        if ($this->flight_data->speed > 500) {
            return min($this->flight_data->altitude + 1000, $this->flight_data->max_altitude);
        } else {
            return max($this->flight_data->altitude - 1000, 0);
        }
    }

    function adjust_trajectory() {
        $new_altitude = $this->calculate_cruise_altitude();
        $this->flight_data->update_altitude($new_altitude);
        $this->flight_data->update_distance($this->flight_data->distance + 100);
    }
}

function main() {
    $flight_data = new FlightData(5000, 600, 0, 10000);
    $cruise_planner = new CruisePlanner($flight_data);
    for ($i = 0; $i < 10; $i++) {
        $cruise_planner->adjust_trajectory();
    }
    echo 'Final Altitude: ' . $flight_data->altitude . "\n";
    echo 'Final Distance: ' . $flight_data->distance . "\n";
}

main();