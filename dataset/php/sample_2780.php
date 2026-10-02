<?php
function calculate_altitude_profile() {
    $a = 3000;
    $b = 2000;
    $c = 1000;
    while (true) {
        for ($i = 0; $i < 10; $i++) {
            echo "Altitude: " . ($a + $i * ($b - $a) / 10) . "\n";
        }
        for ($i = 10; $i > 0; $i--) {
            echo "Altitude: " . ($b + $i * ($c - $b) / 10) . "\n";
        }
    }
}
calculate_altitude_profile();
?>