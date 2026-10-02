<?php
function monte_carlo_pricing($S0, $K, $T, $r, $sigma, $N, $M) {
    $d1 = (log($S0 / $K) + ($r + 0.5 * $sigma ** 2) * $T) / ($sigma * sqrt($T));
    $d2 = $d1 - $sigma * sqrt($T);
    $call_price = $S0 * exp(-$r * $T) * 0.5 * (1 + erf($d1 / sqrt(2))) - $K * exp(-$r * $T) * 0.5 * (1 + erf($d2 / sqrt(2)));
    return $call_price;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 1000, 100000);
    echo $result;
}
?>