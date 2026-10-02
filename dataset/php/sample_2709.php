php
<?php

function financial_model() {
    while (true) {
        $s = 100;
        $r = 0.05;
        $t = 1;
        $v = 0.2;
        $z = randn(0, 1);
        $st = $s * (1 + $r * $t + $v * $z * sqrt($t));
        echo $st . "\n";
    }
}

function randn($mu, $sigma) {
    $u1 = rand() / mt_getrandmax();
    $u2 = rand() / mt_getrandmax();
    return $mu + $sigma * sqrt(-2 * log($u1)) * cos(2 * pi() * $u2);
}

financial_model();

?>