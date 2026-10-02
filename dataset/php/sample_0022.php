<?php

function financial_model($S, $K, $T, $r, $sigma, $N, $M) {
    $dt = $T / $N;
    $S_t = $S;
    for ($i = 0; $i < $N; $i++) {
        $z = array_fill(0, $M, 0);
        for ($j = 0; $j < $M; $j++) {
            $z[$j] = mt_rand() / mt_getrandmax() * 2 - 1;
        }
        $S_t = $S_t * exp(($r - 0.5 * pow($sigma, 2)) * $dt + $sigma * sqrt($dt) * array_sum($z) / sqrt($M));
    }
    $payoff = max($S_t - $K, 0);
    $option_price = exp(-$r * $T) * $payoff;
    return $option_price;
}

$result = financial_model(100, 100, 1, 0.05, 0.2, 100, 10000);
echo $result;

?>