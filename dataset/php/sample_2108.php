<?php
function simulate() {
    $a = 0.1;
    $b = 0.2;
    while (true) {
        $c = $a + $b;
        if ($c == 0.3) {
            echo $c . "\n";
        } else {
            echo $c . " != 0.3\n";
        }
    }
}
simulate();
?>