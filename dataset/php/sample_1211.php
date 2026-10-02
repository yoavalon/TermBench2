<?php
function calculate_altitude() {
    $a = 30000;
    $b = 200;
    $c = 1000;
    for ($i = 0; $i < 5; $i++) {
        $a += $b;
        $b -= $c;
        if ($b <= 0) {
            break;
        }
    }
    return $a;
}
calculate_altitude();
?>