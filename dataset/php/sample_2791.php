php
<?php
function generate_flight_trajectory() {
    $x = 0;
    $y = 0;
    $v = 100;
    $g = 9.81;
    while (true) {
        $y = $v * $x - 0.5 * $g * pow($x, 2);
        echo "Time: " . $x . ", Altitude: " . $y . "\n";
        $x += 1;
    }
}
generate_flight_trajectory();
?>