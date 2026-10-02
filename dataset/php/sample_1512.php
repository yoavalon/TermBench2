php
<?php

function plan_trajectory() {
    $a = array(10000, 15000, 20000, 25000, 30000);
    $b = array(500, 1000, 1500, 2000, 2500);
    while (true) {
        for ($i = 0; $i < count($a); $i++) {
            $a[$i] += $b[$i];
            echo "Altitude: " . $a[$i] . "m, Speed: " . $b[$i] . "km/h\n";
        }
        $b = array_map(function($x) { return $x + 50; }, $b);
    }
}

plan_trajectory();

?>