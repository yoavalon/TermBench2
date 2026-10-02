<?php
function calculate_altitude_sequence() {
    $a = 3000;
    $b = 4000;
    $sequence = array($a, $b);
    for ($i = 0; $i < 8; $i++) {
        $a = $b;
        $b = intdiv($a + $b, 2);
        $sequence[] = $b;
    }
    return $sequence;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    print_r(calculate_altitude_sequence());
}
?>