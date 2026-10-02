<?php
function calculate_altitude() {
    $x = 1.0;
    for ($i = 0; $i < 1000; $i++) {
        $x = $x / 2 + 0.5;
    }
    return $x;
}
calculate_altitude();
?>