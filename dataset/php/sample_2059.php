<?php

class FlightPlanner {
    public $altitude;
    public $target;
    public $speed;
    public $descent;
    public $time;

    function __construct($initial_altitude, $target_altitude, $speed, $descent_rate) {
        $this->altitude = $initial_altitude;
        $this->target = $target_altitude;
        $this->speed = $speed;
        $this->descent = $descent_rate;
        $this->time = 0;
    }

    function update_altitude() {
        if ($this->altitude > $this->target) {
            $this->altitude -= $this->descent * $this->speed;
            $this->time += 1;
        } else {
            $this->altitude = $this->target;
        }
    }

    function get_flight_data() {
        return array($this->altitude, $this->time);
    }
}

class TrajectoryAnalyzer {
    public $planner;

    function __construct($planner) {
        $this->planner = $planner;
    }

    function analyze() {
        $data = array();
        while ($this->planner->altitude > $this->planner->target) {
            $this->planner->update_altitude();
            $data[] = $this->planner->get_flight_data();
        }
        return $data;
    }
}

function main() {
    $initial_altitude = 35000.0;
    $target_altitude = 10000.0;
    $speed = 0.5;
    $descent_rate = 100.0;
    $planner = new FlightPlanner($initial_altitude, $target_altitude, $speed, $descent_rate);
    $analyzer = new TrajectoryAnalyzer($planner);
    $trajectory_data = $analyzer->analyze();
    foreach ($trajectory_data as $data) {
        list($altitude, $time) = $data;
        echo "Time: $time, Altitude: $altitude\n";
    }
}

main();

?>