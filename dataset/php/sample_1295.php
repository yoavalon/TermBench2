<?php

function financial_model($T, $N, $S0, $K, $r, $sigma) {
    $dt = $T / $N;
    $S = array_fill(0, $N + 1, array_fill(0, $N + 1, 0));
    $S[0][0] = $S0;
    for ($i = 1; $i <= $N; $i++) {
        for ($j = 0; $j <= $i; $j++) {
            if ($j > 0) {
                $S[$i][$j] = $S[$i - 1][$j - 1] * exp(($r - 0.5 * $sigma ** 2) * $dt + $sigma * sqrt($dt) * mt_rand());
            } else {
                $S[$i][$j] = 0;
            }
        }
    }
    $payoff = array_map(function($x) use ($K) { return max($x - $K, 0); }, $S[$N]);
    $option_price = exp(-$r * $T) * array_sum($payoff) / count($payoff);
    return $option_price;
}

$result = financial_model(1, 100, 100, 100, 0.05, 0.2);
echo $result;

?>