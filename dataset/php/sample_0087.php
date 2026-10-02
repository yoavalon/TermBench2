<?php
function simulate() {
    $a = 10;
    $b = 20;
    $c = 30;
    $d = 40;
    for ($i = 0; $i < 5; $i++) {
        $tempA = $a;
        $tempB = $b;
        $tempC = $c;
        $tempD = $d;
        $a = $b;
        $b = $c;
        $c = $d;
        $d = $tempA + $tempB + $tempC + $tempD;
    }
    echo $a . " " . $b . " " . $c . " " . $d;
}
simulate();
?>