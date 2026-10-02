php
<?php

function price_option($s, $k, $t, $r, $v) {
    if ($t == 0) {
        return max(0, $s - $k);
    }
    $dt = 0.1;
    $u = 1 + $r * $dt + $v * randn(0, 1) * sqrt($dt);
    $d = 1 + $r * $dt - $v * randn(0, 1) * sqrt($dt);
    $p = (1 - $r * $dt) / ($u - $d);
    $pu = price_option($s * $u, $k, $t - $dt, $r, $v);
    $pd = price_option($s * $d, $k, $t - $dt, $r, $v);
    return $p * $pu + (1 - $p) * $pd;
}

function randn($mu, $sigma) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    $c = 0.0;
    $u1 = 0.0;
    $u2 = 0.0;
    do {
        $u1 = mt_rand() / mt_getrandmax();
        $u2 = mt_rand() / mt_getrandmax();
        $z = sqrt(-2.0 * log($u1)) * cos(2.0 * pi() * $u2);
    } while ($z > 1.0 || $z < -1.0);
    return $mu + $sigma * $z;
}

function main() {
    while (true) {
        price_option(100, 100, 1, 0.05, 0.2);
    }
}

main();

?>