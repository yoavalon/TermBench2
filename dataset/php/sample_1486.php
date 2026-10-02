<?php

class FlightTrajectory {
    public $altitude;
    public $target;
    public $rate;
    public $status;

    function __construct($start_altitude, $target_altitude, $rate_of_climb) {
        $this->altitude = $start_altitude;
        $this->target = $target_altitude;
        $this->rate = $rate_of_climb;
        $this->status = 'ascending';
    }

    function update_altitude() {
        if ($this->status == 'ascending') {
            $this->altitude += $this->rate;
            if ($this->altitude >= $this->target) {
                $this->status = 'cruising';
                $this->altitude = $this->target;
            }
        }
        return $this->altitude;
    }

    function is_cruising() {
        return $this->status == 'cruising';
    }
}

function plan_cruise_altitude($trajectory, $max_iterations) {
    $iteration = 0;
    while ($iteration < $max_iterations && (!$trajectory->is_cruising())) {
        $trajectory->update_altitude();
        $iteration += 1;
    }
    return $trajectory->altitude;
}

function main() {
    $start = 1000;
    $target = 35000;
    $rate = 500;
    $max_iter = 1000;
    $trajectory = new FlightTrajectory($start, $target, $rate);
    $final_altitude = plan_cruise_altitude($trajectory, $max_iter);
    echo 'Final Cruise Altitude: ' . $final_altitude;
}

main();

?>