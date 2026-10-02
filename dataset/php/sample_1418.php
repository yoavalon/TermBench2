<?php
class FlightData {
    public $altitude;
    public $speed;
    public $heading;

    function __construct($altitude, $speed, $heading) {
        $this->altitude = $altitude;
        $this->speed = $speed;
        $this->heading = $heading;
    }

    function update_altitude($new_altitude) {
        $this->altitude = $new_altitude;
    }

    function update_speed($new_speed) {
        $this->speed = $new_speed;
    }

    function update_heading($new_heading) {
        $this->heading = $new_heading;
    }
}

function calculate_new_altitude($current_altitude, $target_altitude, $step) {
    if ($current_altitude < $target_altitude) {
        return min($current_altitude + $step, $target_altitude);
    }
    return max($current_altitude - $step, $target_altitude);
}

function calculate_new_speed($current_speed, $target_speed, $step) {
    if ($current_speed < $target_speed) {
        return min($current_speed + $step, $target_speed);
    }
    return max($current_speed - $step, $target_speed);
}

function cruise_altitude_planning($flight, $target_altitude, $target_speed, $step) {
    while ($flight->altitude != $target_altitude || $flight->speed != $target_speed) {
        $flight->update_altitude(calculate_new_altitude($flight->altitude, $target_altitude, $step));
        $flight->update_speed(calculate_new_speed($flight->speed, $target_speed, $step));
    }
}

function main() {
    $initial_altitude = 10000;
    $initial_speed = 800;
    $initial_heading = 90;
    $target_altitude = 30000;
    $target_speed = 900;
    $step = 1000;
    $flight = new FlightData($initial_altitude, $initial_speed, $initial_heading);
    cruise_altitude_planning($flight, $target_altitude, $target_speed, $step);
    echo 'Final altitude: ' . $flight->altitude . ', Final speed: ' . $flight->speed . "\n";
}

main();
?>