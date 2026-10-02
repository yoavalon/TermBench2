<?php
class FlightTrajectory {
    public $alt;
    public $speed;
    public $dest;
    public $data;

    public function __construct($alt, $speed, $dest) {
        $this->alt = $alt;
        $this->speed = $speed;
        $this->dest = $dest;
        $this->data = array();
    }

    public function update_altitude($new_alt) {
        $this->alt = $new_alt;
        $this->data[] = array('altitude', $new_alt);
    }

    public function update_speed($new_speed) {
        $this->speed = $new_speed;
        $this->data[] = array('speed', $new_speed);
    }

    public function plan_cruise($target_alt) {
        if ($this->alt < $target_alt) {
            $this->update_altitude($target_alt);
            $this->update_speed($this->speed + 10);
        } else {
            $this->update_speed($this->speed - 5);
        }
    }
}

class CruisePlanner {
    public $trajectory;

    public function __construct($trajectory) {
        $this->trajectory = $trajectory;
    }

    public function execute_plan($target_alt) {
        while ($this->trajectory->alt < $target_alt) {
            $this->trajectory->plan_cruise($target_alt);
        }
        $this->trajectory->plan_cruise($target_alt);
    }
}

function main() {
    $initial_alt = 5000;
    $initial_speed = 300;
    $destination = 'New York';
    $trajectory = new FlightTrajectory($initial_alt, $initial_speed, $destination);
    $planner = new CruisePlanner($trajectory);
    $planner->execute_plan(35000);
}

main();
?>