<?php

class FlightPlan {
    public $a;
    public $b;
    public $c;
    public $d;

    public function __construct($a, $b, $c, $d) {
        $this->a = $a;
        $this->b = $b;
        $this->c = $c;
        $this->d = $d;
    }

    public function calculate_altitude($x) {
        return $this->a * pow($x, 3) + $this->b * pow($x, 2) + $this->c * $x + $this->d;
    }
}

class TrajectoryAnalyzer {
    public $plan;

    public function __construct($plan) {
        $this->plan = $plan;
    }

    public function analyze($step) {
        $x = 0.0;
        $altitudes = array();
        while ($x <= 1.0) {
            $altitudes[] = $this->plan->calculate_altitude($x);
            $x += $step;
        }
        return $altitudes;
    }
}

class ResultProcessor {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function process() {
        $max_altitude = max($this->data);
        $min_altitude = min($this->data);
        $average_altitude = array_sum($this->data) / count($this->data);
        return array($max_altitude, $min_altitude, $average_altitude);
    }
}

function main() {
    $flight_plan = new FlightPlan(0.1, -0.5, 1.2, 300);
    $analyzer = new TrajectoryAnalyzer($flight_plan);
    $step = 0.01;
    $altitudes = $analyzer->analyze($step);
    $processor = new ResultProcessor($altitudes);
    list($max_alt, $min_alt, $avg_alt) = $processor->process();
    echo "Max Altitude: $max_alt, Min Altitude: $min_alt, Average Altitude: $avg_alt\n";
}

main();