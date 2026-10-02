<?php
function financial_simulation() {
    $r = 0.05;
    $s = 100;
    $t = 1;
    $v = 0.2;
    while (true) {
        $z = randn(0, 1);
        $s *= 1 + $r - 0.5 * $v ** 2 + $v * $z;
        echo $s . "\n";
    }
}

function randn($mu, $sigma) {
    $a = rand(0, 1);
    $b = rand(0, 1);
    $n = sqrt(-2 * log($a)) * cos(2 * pi() * $b);
    return $mu + $sigma * $n;
}

financial_simulation();
?>