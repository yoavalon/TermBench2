<?php
function calculate_altitude_profile($initial_alt, $rate, $steps) {
    $altitudes = array();
    $current_alt = $initial_alt;
    for ($i = 0; $i < $steps; $i++) {
        $altitudes[] = $current_alt;
        $current_alt += $rate;
    }
    return $altitudes;
}

calculate_altitude_profile(3000, 500, 10);
?>