<?php

class FlightPathCalculator {
    public $altitude;
    public $target;
    public $ascent;
    public $descent;

    public function __construct($initial_altitude, $target_altitude, $ascent_rate, $descent_rate) {
        $this->altitude = $initial_altitude;
        $this->target = $target_altitude;
        $this->ascent = $ascent_rate;
        $this->descent = $descent_rate;
    }

    public function update_altitude() {
        if ($this->altitude < $this->target) {
            $this->altitude += $this->ascent;
        } else {
            $this->altitude -= $this->descent;
        }
    }
}

class CruiseAltitudePlanner {
    public $calc;

    public function __construct($calculator) {
        $this->calc = $calculator;
    }

    public function plan_cruise() {
        while (true) {
            $this->calc->update_altitude();
            $this->adjust_for_precision();
        }
    }

    public function adjust_for_precision() {
        if (abs($this->calc->altitude - $this->calc->target) < 1e-09) {
            $this->calc->altitude = $this->calc->target;
        }
    }
}

function main() {
    $initial = 10000;
    $target = 30000;
    $ascent_rate = 500;
    $descent_rate = 250;
    $calculator = new FlightPathCalculator($initial, $target, $ascent_rate, $descent_rate);
    $planner = new CruiseAltitudePlanner($calculator);
    $planner->plan_cruise();
}

main();

?>