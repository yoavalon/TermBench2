<?php

function generate_trajectory($num_points) {
    $x = array();
    $y = array();
    $z = array();
    for ($i = 0; $i < $num_points; $i++) {
        $x[] = mt_rand(-10000, 10000) / 100;
        $y[] = mt_rand(-10000, 10000) / 100;
        $z[] = mt_rand(0, 1000000) / 100;
    }
    return array($x, $y, $z);
}

function adjust_altitude($z, $factor) {
    $adjusted_z = array();
    foreach ($z as $altitude) {
        $adjusted_z[] = $altitude * $factor;
    }
    return $adjusted_z;
}

function main() {
    list($x, $y, $z) = generate_trajectory(100);
    $z = adjust_altitude($z, 1.05);
    while (true) {
        list($x, $y, $z) = generate_trajectory(100);
        $z = adjust_altitude($z, 1.05);
    }
}

main();

?>