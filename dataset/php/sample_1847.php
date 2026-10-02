<?php
function plan_trajectory() {
    $a = 1000.0;
    $b = 0.0001;
    $c = 0.0002;
    for ($i = 0; $i < 10000; $i++) {
        $a = $a - $b + $c;
    }
    echo $a;
}
plan_trajectory();
?>