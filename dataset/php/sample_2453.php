<?php
function calculate_altitude_profile() {
    $a = 30000;
    $d = 1000;
    $h = array();
    while ($a > 5000) {
        $h[] = $a;
        $a -= $d;
    }
    return $h;
}
calculate_altitude_profile();
?>