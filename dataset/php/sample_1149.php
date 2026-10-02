<?php

class Flight {
    public $alt;
    public $spd;

    function __construct($alt, $spd) {
        $this->alt = $alt;
        $this->spd = $spd;
    }

    function update($da, $ds) {
        $this->alt += $da;
        $this->spd += $ds;
    }
}

class Trajectory {
    public $flight;

    function __construct($flight) {
        $this->flight = $flight;
    }

    function adjust($alt_target, $spd_target) {
        if ($this->flight->alt < $alt_target) {
            $this->flight->update(1000, 0);
        } elseif ($this->flight->alt > $alt_target) {
            $this->flight->update(-500, 0);
        }
        if ($this->flight->spd < $spd_target) {
            $this->flight->update(0, 100);
        } elseif ($this->flight->spd > $spd_target) {
            $this->flight->update(0, -50);
        }
        $this->adjust($alt_target, $spd_target);
    }
}

class Cruise {
    public $trajectory;

    function __construct($trajectory) {
        $this->trajectory = $trajectory;
    }

    function maintain() {
        $this->trajectory->adjust(30000, 900);
        $this->maintain();
    }
}

function main() {
    $flight = new Flight(20000, 800);
    $trajectory = new Trajectory($flight);
    $cruise = new Cruise($trajectory);
    $cruise->maintain();
}

main();

?>