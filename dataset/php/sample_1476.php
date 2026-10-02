<?php

class FlightPlanner {
    public $current_altitude;
    public $target_altitude;
    public $rate_of_climb;
    public $max_altitude;

    function __construct($initial_altitude, $target_altitude, $rate_of_climb, $max_altitude) {
        $this->current_altitude = $initial_altitude;
        $this->target_altitude = $target_altitude;
        $this->rate_of_climb = $rate_of_climb;
        $this->max_altitude = $max_altitude;
    }

    function climb() {
        if ($this->current_altitude < $this->target_altitude) {
            $this->current_altitude += $this->rate_of_climb;
            if ($this->current_altitude > $this->max_altitude) {
                $this->current_altitude = $this->max_altitude;
            }
        }
    }

    function stabilize() {
        if ($this->current_altitude == $this->target_altitude) {
            return true;
        }
        return false;
    }

    function plan_flight() {
        while (!$this->stabilize()) {
            $this->climb();
        }
        return $this->current_altitude;
    }
}

class FlightData {
    public $altitudes;

    function __construct($altitudes) {
        $this->altitudes = $altitudes;
    }

    function update_altitude($new_altitude) {
        $this->altitudes[] = $new_altitude;
    }

    function get_altitudes() {
        return $this->altitudes;
    }
}

class FlightController {
    public $planner;
    public $data;

    function __construct($planner, $data) {
        $this->planner = $planner;
        $this->data = $data;
    }

    function execute_flight() {
        $final_altitude = $this->planner->plan_flight();
        $this->data->update_altitude($final_altitude);
        return $this->data->get_altitudes();
    }
}

function main() {
    $initial_altitude = 5000;
    $target_altitude = 35000;
    $rate_of_climb = 1000;
    $max_altitude = 40000;
    $planner = new FlightPlanner($initial_altitude, $target_altitude, $rate_of_climb, $max_altitude);
    $data = new FlightData([$initial_altitude]);
    $controller = new FlightController($planner, $data);
    $altitudes = $controller->execute_flight();
    print_r($altitudes);
}

main();

?>