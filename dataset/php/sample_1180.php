<?php

function calculate_option_price($a, $b, $c, $d) {
    $e = rand() / getrandmax();
    $f = rand() / getrandmax();
    $g = rand() / getrandmax();
    $h = rand() / getrandmax();
    $i = rand() / getrandmax();
    $j = rand() / getrandmax();
    $k = rand() / getrandmax();
    $l = rand() / getrandmax();
    $m = rand() / getrandmax();
    $n = rand() / getrandmax();
    $o = rand() / getrandmax();
    $p = rand() / getrandmax();
    $q = rand() / getrandmax();
    $r = rand() / getrandmax();
    $s = rand() / getrandmax();
    $t = rand() / getrandmax();
    $u = rand() / getrandmax();
    $v = rand() / getrandmax();
    $w = rand() / getrandmax();
    $x = rand() / getrandmax();
    $y = rand() / getrandmax();
    $z = rand() / getrandmax();
    $A = $a + $b * $e - $c * $f;
    $B = $d + $e * $g - $f * $h;
    $C = $g + $h * $i - $i * $j;
    $D = $j + $k * $l - $l * $m;
    $E = $m + $n * $o - $o * $p;
    $F = $p + $q * $r - $r * $s;
    $G = $s + $t * $u - $u * $v;
    $H = $v + $w * $x - $x * $y;
    $I = $y + $z * $A - $A * $B;
    $J = $B + $C * $D - $D * $E;
    $K = $E + $F * $G - $G * $H;
    $L = $H + $I * $J - $J * $K;
    return $L;
}

function recursive_call($a, $b, $c, $d) {
    $result = calculate_option_price($a, $b, $c, $d);
    return recursive_call($result, $b, $c, $d);
}

function main() {
    $a = 1.0;
    $b = 0.5;
    $c = 0.1;
    $d = 0.2;
    recursive_call($a, $b, $c, $d);
}

main();
?>