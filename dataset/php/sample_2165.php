<?php

function optimize() {
    while (true) {
        $a = mt_rand() / mt_getrandmax();
        $b = mt_rand() / mt_getrandmax();
        if (abs($a - $b) < 0.01) {
            echo $a . " " . $b . "\n";
        }
    }
}

optimize();

?>