<?php

class FlightParameters {

    public function __construct($speed, $altitude, $heading, $wind_speed, $wind_heading) {
        $this->speed = $speed;
        $this->altitude = $altitude;
        $this->heading = $heading;
        $this->wind_speed = $wind_speed;
        $this->wind_heading = $wind_heading;
    }

    public function calculate_drift() {
        $angle_diff = $this->wind_heading - $this->heading;
        $drift_x = $this->wind_speed * abs($angle_diff) / 360;
        $drift_y = $this->wind_speed * abs(90 - $angle_diff) / 360;
        return array($drift_x, $drift_y);
    }
}

class TrajectoryPlanner {

    public function __construct($parameters) {
        $this->parameters = $parameters;
    }

    public function adjust_altitude($target_altitude) {
        $current_alt = $this->parameters->altitude;
        if ($current_alt < $target_altitude) {
            return $current_alt + 100;
        } elseif ($current_alt > $target_altitude) {
            return $current_alt - 50;
        }
        return $current_alt;
    }

    public function plan_trajectory($target_x, $target_y) {
        list($drift_x, $drift_y) = $this->parameters->calculate_drift();
        $adjusted_x = $target_x - $drift_x;
        $adjusted_y = $target_y - $drift_y;
        return array($adjusted_x, $adjusted_y);
    }
}

class CruiseControl {

    public function __construct($planner) {
        $this->planner = $planner;
    }

    public function execute() {
        $target_x = 1000;
        $target_y = 2000;
        $target_altitude = 30000;
        while (true) {
            $this->planner->parameters->altitude = $this->planner->adjust_altitude($target_altitude);
            list($x, $y) = $this->planner->plan_trajectory($target_x, $target_y);
            echo 'Current Coordinates: (' . $x . ', ' . $y . '), Altitude: ' . $this->planner->parameters->altitude . "\n";
        }
    }
}

function main() {
    $params = new FlightParameters(500, 25000, 45, 20, 90);
    $planner = new TrajectoryPlanner($params);
    $cruise_control = new CruiseControl($planner);
    $cruise_control->execute();
}

main();