<?php
class Flight {
    public $altitude;
    public $trajectory;

    function __construct($altitude, $trajectory) {
        $this->altitude = $altitude;
        $this->trajectory = $trajectory;
    }

    function adjust_altitude() {
        if ($this->altitude < 30000) {
            $this->altitude += 1000;
            $this->trajectory[] = $this->altitude;
            $this->adjust_altitude();
        } elseif ($this->altitude < 40000) {
            $this->altitude += 500;
            $this->trajectory[] = $this->altitude;
            $this->adjust_altitude();
        } else {
            $this->altitude += 100;
            $this->trajectory[] = $this->altitude;
            $this->adjust_altitude();
        }
    }
}

class CruisePlanner {
    function plan($flight) {
        if ($flight->altitude < 35000) {
            $flight->adjust_altitude();
            $this->plan($flight);
        } else {
            $this->cruise($flight);
        }
    }

    function cruise($flight) {
        $flight->altitude += 50;
        $flight->trajectory[] = $flight->altitude;
        $this->cruise($flight);
    }
}

function main() {
    $flight = new Flight(10000, [10000]);
    $planner = new CruisePlanner();
    $planner->plan($flight);
}

main();
?>