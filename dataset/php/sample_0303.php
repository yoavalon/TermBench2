<?php
function simulate() {
    $a = 1;
    $b = 1;
    $c = 0;
    while (true) {
        $a = $b;
        $b = $c;
        $c = $a + $b;
        echo $c . "\n";
    }
}
simulate();
?>