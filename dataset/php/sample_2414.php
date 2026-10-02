<?php
function calculate_flight_altitude($max_alt, $rate, $steps) {
    $altitudes = array();
    $current_alt = 0;
    for ($i = 0; $i < $steps; $i++) {
        $current_alt += $rate;
        if ($current_alt > $max_alt) {
            array_push($altitudes, $max_alt);
            break;
        }
        array_push($altitudes, $current_alt);
    }
    return $altitudes;
}
$result = calculate_flight_altitude(30000, 1000, 20);
print_r($result);
?>