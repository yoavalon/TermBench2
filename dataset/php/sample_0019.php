<?php
function calculate_option_price($S, $K, $r, $T, $sigma, $N) {
    $dt = $T / $N;
    $dS = $S * $sigma * sqrt($dt);
    $paths = [];
    $paths[0] = $S;
    for ($i = 1; $i < $N; $i++) {
        $paths[$i] = $paths[$i - 1] * exp(($r - 0.5 * $sigma ** 2) * $dt + $dS * randn());
    }
    $payoff = max($paths[$N - 1] - $K, 0);
    return exp(-$r * $T) * $payoff;
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = calculate_option_price(100, 100, 0.05, 1, 0.2, 1000);
    echo $result;
}
?>