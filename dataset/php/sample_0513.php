<?php

class FlightPath {
    public $altitude;
    public $target_altitude;
    public $rate_of_climb;

    public function __construct($start_altitude, $target_altitude, $rate_of_climb) {
        $this->altitude = $start_altitude;
        $this->target_altitude = $target_altitude;
        $this->rate_of_climb = $rate_of_climb;
    }

    public function climb() {
        $this->altitude += $this->rate_of_climb;
        if ($this->altitude > $this->target_altitude) {
            $this->altitude = $this->target_altitude;
        }
    }

    public function get_status() {
        return array($this->altitude, $this->target_altitude);
    }
}

class CruiseAltitude {
    public $altitude;
    public $max_speed;
    public $wind_speed;

    public function __construct($altitude, $max_speed, $wind_speed) {
        $this->altitude = $altitude;
        $this->max_speed = $max_speed;
        $this->wind_speed = $wind_speed;
    }

    public function adjust_speed() {
        $this->max_speed = $this->max_speed - $this->wind_speed * 0.5;
    }

    public function get_speed() {
        return $this->max_speed;
    }
}

function main() {
    $flight = new FlightPath(1000, 35000, 100);
    $cruise = new CruiseAltitude(35000, 800, 20);
    while (true) {
        $flight->climb();
        $cruise->adjust_speed();
        list($current_alt, $target_alt) = $flight->get_status();
        $current_speed = $cruise->get_speed();
        if ($current_alt == $target_alt) {
            echo "Reached target altitude: $current_alt\n";
            echo "Cruise speed adjusted to: $current_speed\n";
        } else {
            echo "Current altitude: $current_alt, Target altitude: $target_alt\n";
            echo "Current speed: $current_speed\n";
        }
    }
}

main();

?>