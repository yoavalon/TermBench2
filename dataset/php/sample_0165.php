<?php
function generate_paths($S0, $mu, $sigma, $T, $N, $M) {
    $dt = $T / $N;
    $S = array_fill(0, $N + 1, array_fill(0, $M, 0));
    $S[0] = array_fill(0, $M, $S0);
    for ($t = 1; $t <= $N; $t++) {
        for ($i = 0; $i < $M; $i++) {
            $S[$t][$i] = $S[$t - 1][$i] * exp(($mu - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * randn());
        }
    }
    return $S;
}

function option_price($paths, $K, $r, $T, $payoff) {
    $discounted_payoffs = array();
    for ($i = 0; $i < count($paths[count($paths) - 1]); $i++) {
        $discounted_payoffs[] = exp(-$r * $T) * $payoff($paths[count($paths) - 1][$i], $K);
    }
    return array_sum($discounted_payoffs) / count($discounted_payoffs);
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

function european_call($S, $K) {
    return max($S - $K, 0);
}

function main() {
    $S0 = 100;
    $K = 100;
    $r = 0.05;
    $T = 1;
    $N = 252;
    $M = 10000;
    $sigma = 0.2;
    $mu = 0.1;

    $paths = generate_paths($S0, $mu, $sigma, $T, $N, $M);
    $call_price = option_price($paths, $K, $r, $T, 'european_call');
    echo $call_price;
}

main();
?>