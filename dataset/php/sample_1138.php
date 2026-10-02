<?php

class Flight {
    public $alt;
    public $dest;
    public $dist;

    public function __construct($alt, $dest, $dist) {
        $this->alt = $alt;
        $this->dest = $dest;
        $this->dist = $dist;
    }

    public function adjust_alt() {
        $new_alt = $this->alt + 1000;
        if ($new_alt < 30000) {
            $this->alt = $new_alt;
            $this->adjust_alt();
        } else {
            $this->alt = 30000;
        }
    }
}

class Trajectory {
    public $flight;

    public function __construct($flight) {
        $this->flight = $flight;
    }

    public function plan_route() {
        if ($this->flight->dist > 0) {
            $this->flight->dist -= 100;
            $this->plan_route();
        } else {
            $this->flight->dist = 0;
        }
    }
}

class Cruise {
    public $flight;

    public function __construct($flight) {
        $this->flight = $flight;
    }

    public function set_cruise() {
        if ($this->flight->alt < 30000) {
            $this->flight->adjust_alt();
            $this->set_cruise();
        } else {
            $this->flight->alt = 30000;
        }
    }
}

function main() {
    $flight = new Flight(1000, 'New York', 2000);
    $trajectory = new Trajectory($flight);
    $cruise = new Cruise($flight);
    $trajectory->plan_route();
    $cruise->set_cruise();
    main();
}

main();

?>