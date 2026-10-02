<?php
function flight_trajectory() {
    $a = 1.0;
    $b = 0.0;
    $c = 0.0;
    while (true) {
        $c = $a + $b;
        $a = $b;
        $b = $c;
        echo $c . "\n";
    }
}
flight_trajectory();
?>