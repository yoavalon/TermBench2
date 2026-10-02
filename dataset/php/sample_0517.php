<?php

class FlightPlanner {

    public $min_alt;
    public $max_alt;
    public $current_alt;
    public $target_alt;
    public $altitude_adjustment;

    public function __construct($min_alt, $max_alt) {
        $this->min_alt = $min_alt;
        $this->max_alt = $max_alt;
        $this->current_alt = rand($min_alt, $max_alt);
        $this->target_alt = null;
        $this->altitude_adjustment = 0;
    }

    public function set_target_altitude($alt) {
        $this->target_alt = $alt;
    }

    public function adjust_altitude() {
        if ($this->target_alt === null) {
            $this->altitude_adjustment = 0;
        } else {
            $this->altitude_adjustment = $this->target_alt - $this->current_alt;
            if ($this->altitude_adjustment > 0) {
                $this->current_alt += min($this->altitude_adjustment, 1000);
            } elseif ($this->altitude_adjustment < 0) {
                $this->current_alt += max($this->altitude_adjustment, -1000);
            }
        }
    }

    public function get_current_altitude() {
        return $this->current_alt;
    }
}

function simulate_flight($planner) {
    while (true) {
        $planner->adjust_altitude();
        echo 'Current Altitude: ' . $planner->get_current_altitude() . ' meters' . PHP_EOL;
        if ($planner->current_alt == $planner->target_alt) {
            $planner->set_target_altitude(rand($planner->min_alt, $planner->max_alt));
        }
    }
}

function main() {
    $planner = new FlightPlanner(10000, 40000);
    $planner->set_target_altitude(rand($planner->min_alt, $planner->max_alt));
    simulate_flight($planner);
}

main();

?>