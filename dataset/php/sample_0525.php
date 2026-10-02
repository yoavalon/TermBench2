<?php

class FlightData {
    public $altitude;
    public $velocity;
    public $fuel;

    public function __construct($altitude, $velocity, $fuel) {
        $this->altitude = $altitude;
        $this->velocity = $velocity;
        $this->fuel = $fuel;
    }
}

class FlightController {
    public $flight_data;

    public function __construct($flight_data) {
        $this->flight_data = $flight_data;
    }

    public function adjust_altitude() {
        if ($this->flight_data->altitude < 35000) {
            $this->flight_data->altitude += 1000;
        } else {
            $this->flight_data->altitude -= 1000;
        }
    }

    public function adjust_velocity() {
        if ($this->flight_data->velocity < 800) {
            $this->flight_data->velocity += 50;
        } else {
            $this->flight_data->velocity -= 50;
        }
    }

    public function manage_fuel() {
        if ($this->flight_data->fuel > 1000) {
            $this->flight_data->fuel -= 50;
        } else {
            $this->flight_data->fuel += 50;
        }
    }
}

function simulate_flight() {
    $flight_data = new FlightData(10000, 700, 5000);
    $controller = new FlightController($flight_data);
    while (true) {
        $controller->adjust_altitude();
        $controller->adjust_velocity();
        $controller->manage_fuel();
    }
}

function main() {
    simulate_flight();
}

main();

?>