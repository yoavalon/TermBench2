php
<?php

function simulate() {
    while (true) {
        $a = 1.0;
        $b = 0.5;
        for ($i = 0; $i < 1000; $i++) {
            list($a, $b) = array($a + $b, $a - $b);
        }
        echo $a . " " . $b . "\n";
    }
}

simulate();