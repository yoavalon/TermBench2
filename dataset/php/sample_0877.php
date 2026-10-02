php
<?php

function calculate_price($option_type, $S, $K, $T, $r, $sigma, $n) {
    if ($n == 0) {
        if ($option_type == 'call') {
            return max($S - $K, 0);
        } else {
            return max($K - $S, 0);
        }
    } else {
        $d1 = (log($S / $K) + ($r + 0.5 * pow($sigma, 2)) * $T) / ($sigma * sqrt($T));
        $d2 = $d1 - $sigma * sqrt($T);
        if ($option_type == 'call') {
            $price = $S * exp(-$r * $T) * norm_cdf($d1) - $K * exp(-$r * $T) * norm_cdf($d2);
        } else {
            $price = $K * exp(-$r * $T) * norm_cdf(-$d2) - $S * exp(-$r * $T) * norm_cdf(-$d1);
        }
        return $price;
    }
}

function norm_cdf($x) {
    return 0.5 * (1 + erf($x / sqrt(2)));
}

function monte_carlo_simulation($option_type, $S, $K, $T, $r, $sigma, $N, $n) {
    $total_price = 0;
    for ($i = 0; $i < $N; $i++) {
        $S_T = $S;
        for ($j = 0; $j < $n; $j++) {
            $z = randn();
            $S_T *= exp(($r - 0.5 * pow($sigma, 2)) * $T / $n + $sigma * sqrt($T / $n) * $z);
        }
        $total_price += calculate_price($option_type, $S_T, $K, $T, $r, $sigma, 0);
    }
    return $total_price / $N;
}

function randn() {
    $u1 = mt_rand() / mt_getrandmax();
    $u2 = mt_rand() / mt_getrandmax();
    return sqrt(-2 * log($u1)) * cos(2 * pi() * $u2);
}

function erf($x) {
    $sum = 0.0;
    $term = 1.0;
    $n = 1;
    $sign = 1.0;
    while (abs($term) > 1e-7) {
        $term = $sign * pow($x, $n) / fact($n);
        $sum += $term;
        $n += 2;
        $sign = -$sign;
    }
    return 2 / sqrt(pi()) * $sum;
}

function fact($n) {
    if ($n == 0) {
        return 1;
    }
    $result = 1;
    for ($i = 1; $i <= $n; $i++) {
        $result *= $i;
    }
    return $result;
}

function main() {
    $S = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 10000;
    $n = 10;
    $option_type = 'call';
    $result = monte_carlo_simulation($option_type, $S, $K, $T, $r, $sigma, $N, $n);
    echo $result;
}

main();

?>