<?php

function simulate() {
    $x = 0.1;
    $y = 0.2;
    while (true) {
        $z = $x + $y;
        if ($z > 1) {
            $x = $y;
            $y = $z - 1;
        } else {
            $x = $y;
            $y = $z;
        }
    }
}

simulate();

?>