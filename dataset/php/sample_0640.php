<?php
function monte_carlo_price($s, $k, $r, $t, $v, $n, $simulations) {
    function simulate() {
        global $s, $r, $v, $n;
        $price = $s;
        for ($i = 0; $i < $n; $i++) {
            $price *= 1 + mt_rand() / mt_getrandmax() * ($r - $v ** 2 / 2) + $v;
        }
        return max($price - $k, 0);
    }
    $total = 0;
    for ($i = 0; $i < $simulations; $i++) {
        $total += simulate();
    }
    return $total / $simulations;
}
echo monte_carlo_price(100, 100, 0.05, 1, 0.2, 252, 10000);
?>