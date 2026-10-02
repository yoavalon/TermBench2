<?php
function simulate() {
    $x = 1.0;
    $y = 0.0;
    $z = 0.0;
    while (true) {
        list($x, $y, $z) = array($y, $z, 3.9 * $x * (1 - $x) + $z);
        yield array($x, $y, $z);
    }
}

foreach (simulate() as $state) {
    print_r($state);
}
?>