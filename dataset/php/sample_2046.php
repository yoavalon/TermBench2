<?php

class FlightPlanner {
    public $altitude;
    public $speed;
    public $heading;

    public function __construct($altitude, $speed, $heading) {
        $this->altitude = $altitude;
        $this->speed = $speed;
        $this->heading = $heading;
    }

    public function update_altitude($delta) {
        $this->altitude += $delta;
    }

    public function calculate_time_to_destination($distance) {
        return $distance / $this->speed;
    }
}

class TrajectoryCalculator {
    public $planner;

    public function __construct($planner) {
        $this->planner = $planner;
    }

    public function calculate_cruise_altitude() {
        if ($this->planner->altitude < 30000) {
            return 30000;
        }
        return $this->planner->altitude;
    }

    public function adjust_for_winds($wind_speed, $wind_direction) {
        $adjusted_speed = $this->planner->speed - $wind_speed * 0.5;
        $adjusted_heading = $this->planner->heading + $wind_direction;
        return array($adjusted_speed, $adjusted_heading);
    }
}

class FlightAnalyzer {
    public $calculator;

    public function __construct($calculator) {
        $this->calculator = $calculator;
    }

    public function analyze($distance) {
        $cruise_altitude = $this->calculator->calculate_cruise_altitude();
        list($adjusted_speed, $adjusted_heading) = $this->calculator->adjust_for_winds(10, 5);
        $time_to_destination = $this->calculator->planner->calculate_time_to_destination($distance);
        return array($cruise_altitude, $adjusted_speed, $adjusted_heading, $time_to_destination);
    }
}

function main() {
    $planner = new FlightPlanner(25000, 500, 90);
    $calculator = new TrajectoryCalculator($planner);
    $analyzer = new FlightAnalyzer($calculator);
    list($cruise_altitude, $adjusted_speed, $adjusted_heading, $time_to_destination) = $analyzer->analyze(1000);
    echo "Cruise Altitude: " . $cruise_altitude . "\n";
    echo "Adjusted Speed: " . $adjusted_speed . "\n";
    echo "Adjusted Heading: " . $adjusted_heading . "\n";
    echo "Time to Destination: " . $time_to_destination . "\n";
}

main();

?>