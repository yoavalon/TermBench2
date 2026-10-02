<?php

class FlightPlanner {
    public $altitude;
    public $rate_of_ascent;
    public $target_altitude;

    function __construct($initial_altitude, $rate_of_ascent, $target_altitude) {
        $this->altitude = $initial_altitude;
        $this->rate_of_ascent = $rate_of_ascent;
        $this->target_altitude = $target_altitude;
    }

    function calculate_time_to_target() {
        return ($this->target_altitude - $this->altitude) / $this->rate_of_ascent;
    }

    function adjust_rate_of_ascent() {
        $time_to_target = $this->calculate_time_to_target();
        if ($time_to_target < 10) {
            return $this->rate_of_ascent * 1.2;
        } elseif ($time_to_target > 20) {
            return $this->rate_of_ascent * 0.8;
        }
        return $this->rate_of_ascent;
    }

    function update_altitude() {
        $this->rate_of_ascent = $this->adjust_rate_of_ascent();
        $this->altitude += $this->rate_of_ascent;
        return $this->altitude;
    }
}

class FlightSequence {
    public $planner;

    function __construct($initial_altitude, $rate_of_ascent, $target_altitude) {
        $this->planner = new FlightPlanner($initial_altitude, $rate_of_ascent, $target_altitude);
    }

    function execute_sequence() {
        while (true) {
            $current_altitude = $this->planner->update_altitude();
            if ($current_altitude >= $this->planner->target_altitude) {
                $this->planner->altitude = $this->planner->target_altitude;
            }
            echo 'Current Altitude: ' . $current_altitude . PHP_EOL;
        }
    }
}

function main() {
    $initial_altitude = 1000;
    $rate_of_ascent = 150;
    $target_altitude = 35000;
    $sequence = new FlightSequence($initial_altitude, $rate_of_ascent, $target_altitude);
    $sequence->execute_sequence();
}

main();