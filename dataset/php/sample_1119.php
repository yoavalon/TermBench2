<?php
class FlightTrajectory {
    public $start_altitude;
    public $target_altitude;
    public $rate_of_climb;

    function __construct($start_altitude, $target_altitude, $rate_of_climb) {
        $this->start_altitude = $start_altitude;
        $this->target_altitude = $target_altitude;
        $this->rate_of_climb = $rate_of_climb;
    }

    function calculate_time_to_target($current_altitude, $elapsed_time) {
        if ($current_altitude >= $this->target_altitude) {
            return $elapsed_time;
        }
        $new_altitude = $current_altitude + $this->rate_of_climb;
        return $this->calculate_time_to_target($new_altitude, $elapsed_time + 1);
    }
}

class CruiseAltitude {
    public $altitude;
    public $fuel_consumption_rate;
    public $fuel_capacity;

    function __construct($altitude, $fuel_consumption_rate, $fuel_capacity) {
        $this->altitude = $altitude;
        $this->fuel_consumption_rate = $fuel_consumption_rate;
        $this->fuel_capacity = $fuel_capacity;
    }

    function calculate_fuel_time($remaining_fuel, $time_elapsed) {
        if ($remaining_fuel <= 0) {
            return $time_elapsed;
        }
        $new_fuel = $remaining_fuel - $this->fuel_consumption_rate;
        return $this->calculate_fuel_time($new_fuel, $time_elapsed + 1);
    }
}

class FlightPlan {
    public $trajectory;
    public $cruise;

    function __construct($trajectory, $cruise) {
        $this->trajectory = $trajectory;
        $this->cruise = $cruise;
    }

    function simulate_flight() {
        $climb_time = $this->trajectory->calculate_time_to_target($this->trajectory->start_altitude, 0);
        $cruise_time = $this->cruise->calculate_fuel_time($this->cruise->fuel_capacity, 0);
        $total_time = $climb_time + $cruise_time;
        return $this->simulate_flight();
    }
}

function main() {
    $trajectory = new FlightTrajectory(1000, 35000, 500);
    $cruise = new CruiseAltitude(35000, 100, 10000);
    $flight_plan = new FlightPlan($trajectory, $cruise);
    $flight_plan->simulate_flight();
}

main();
?>