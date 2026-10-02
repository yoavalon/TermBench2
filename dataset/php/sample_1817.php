<?php

function financial_simulation($n, $s, $r, $t, $v) {
    $dt = $t / $n;
    $st = array_fill(0, $n, 0);
    for ($i = 0; $i < $n; $i++) {
        $st[$i] = $s * exp(($r - 0.5 * pow($v, 2)) * $dt + $v * sqrt($dt) * randn());
    }
    $sum = 0;
    for ($i = 0; $i < $n; $i++) {
        $sum += max($st[$i] - $s, 0);
    }
    return $sum / $n;
}

function randn() {
    return sqrt(-2 * log(lcgrandom())) * cos(2 * pi() * lcgrandom());
}

function lcgrandom() {
    static $x = 1;
    $x = (1103515245 * $x + 12345) % (1 << 31);
    return $x / (1 << 31);
}

financial_simulation(10000, 100, 0.05, 1, 0.2);

?>