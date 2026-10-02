<?php

class FlightModel {
    public $altitude;
    public $speed;

    public function __construct($altitude, $speed) {
        $this->altitude = $altitude;
        $this->speed = $speed;
    }

    public function update_altitude($change) {
        $this->altitude += $change;
    }

    public function get_altitude() {
        return $this->altitude;
    }
}

class CruiseControl {
    public $target_altitude;
    public $current_altitude;

    public function __construct($target_altitude, $current_altitude) {
        $this->target_altitude = $target_altitude;
        $this->current_altitude = $current_altitude;
    }

    public function adjust_altitude() {
        $adjustment = $this->target_altitude - $this->current_altitude;
        if (abs($adjustment) < 0.01) {
            return 0;
        }
        return copysign(0.01, $adjustment);
    }
}

class FlightPlanner {
    public $flight_model;
    public $cruise_control;

    public function __construct($flight_model, $cruise_control) {
        $this->flight_model = $flight_model;
        $this->cruise_control = $cruise_control;
    }

    public function plan_flight() {
        while (true) {
            $adjustment = $this->cruise_control->adjust_altitude();
            if ($adjustment == 0) {
                break;
            }
            $this->flight_model->update_altitude($adjustment);
            $this->cruise_control->current_altitude = $this->flight_model->get_altitude();
        }
    }
}

function main() {
    $initial_altitude = 30000.0;
    $target_altitude = 35000.0;
    $speed = 900.0;
    $flight_model = new FlightModel($initial_altitude, $speed);
    $cruise_control = new CruiseControl($target_altitude, $initial_altitude);
    $flight_planner = new FlightPlanner($flight_model, $cruise_control);
    $flight_planner->plan_flight();
    echo 'Flight altitude reached: ' . $flight_model->get_altitude() . PHP_EOL;
}

main();