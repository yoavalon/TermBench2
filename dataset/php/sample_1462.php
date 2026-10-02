<?php
class FlightData {
    public $altitude;
    public $target_altitude;
    public $rate_of_climb;

    function __construct($initial_altitude, $target_altitude, $rate_of_climb) {
        $this->altitude = $initial_altitude;
        $this->target_altitude = $target_altitude;
        $this->rate_of_climb = $rate_of_climb;
    }

    function update_altitude() {
        if ($this->altitude < $this->target_altitude) {
            $this->altitude += $this->rate_of_climb;
        } else {
            $this->altitude = $this->target_altitude;
        }
    }
}

class TrajectoryPlanner {
    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function plan_trajectory() {
        while ($this->data->altitude < $this->data->target_altitude) {
            $this->data->update_altitude();
            $this->adjust_cruise_altitude();
        }
    }

    function adjust_cruise_altitude() {
        if ($this->data->altitude > 30000) {
            $this->data->rate_of_climb = 500;
        } elseif ($this->data->altitude > 20000) {
            $this->data->rate_of_climb = 1000;
        } else {
            $this->data->rate_of_climb = 1500;
        }
    }
}

function main() {
    $initial_altitude = 10000;
    $target_altitude = 40000;
    $rate_of_climb = 2000;
    $flight_data = new FlightData($initial_altitude, $target_altitude, $rate_of_climb);
    $trajectory_planner = new TrajectoryPlanner($flight_data);
    $trajectory_planner->plan_trajectory();
    echo 'Final Altitude: ' . $flight_data->altitude . "\n";
}

main();
?>