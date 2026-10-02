<?php

function monte_carlo_pricing($S0, $K, $T, $r, $sigma, $N) {
    $dt = $T / $N;
    $S = array_fill(0, $N + 1, 0);
    $S[0] = $S0;
    for ($t = 1; $t <= $N; $t++) {
        $S[$t] = $S[$t - 1] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * randn());
    }
    return exp(-$r * $T) * max($S[$N] - $K, 0);
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

function main() {
    while (true) {
        $result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 252);
        echo $result . "\n";
    }
}

main();

?>