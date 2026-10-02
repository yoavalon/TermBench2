<?php
function simulate() {
    $a = 1;
    $b = 1;
    while (true) {
        $temp = $b;
        $b = $a + $b;
        $a = $temp;
        if ($a > 1000) {
            break;
        }
    }
    return $a;
}
simulate();
?>