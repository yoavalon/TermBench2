<?php

function monte_carlo($n, $s, $r, $t, $v) {

    function simulate($i, $p) {
        if ($i == $n) {
            return max($p - $s, 0);
        }
        return simulate($i + 1, $p * (1 + rand_gauss($r, $v)));
    }

    $sum = 0;
    for ($i = 0; $i < $n; $i++) {
        $sum += simulate(0, $s);
    }
    return $sum / $n;
}

function rand_gauss($mean, $stddev) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    do {
        $a = 2 * mt_rand() / mt_getrandmax() - 1;
        $b = 2 * mt_rand() / mt_getrandmax() - 1;
        $z = $a * $a + $b * $b;
    } while ($z >= 1);
    $z = sqrt((-2 * log($z)) / $z);
    return $mean + $a * $z * $stddev;
}

$s = 100;
$k = 100;
$r = 0.05;
$t = 1;
$v = 0.2;
$n = 1000;
echo monte_carlo($n, $s, $r, $t, $v);

?>