<?php

class OptionPricing {

    function __construct($S, $K, $T, $r, $sigma) {
        $this->S = $S;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
    }

    function calculate_price($n_simulations, $depth) {
        if ($depth == 0) {
            return $this->black_scholes($this->S, $this->K, $this->T, $this->r, $this->sigma);
        } else {
            return $this->monte_carlo($n_simulations, $depth);
        }
    }

    function black_scholes($S, $K, $T, $r, $sigma) {
        $d1 = (log($S / $K) + ($r + 0.5 * $sigma ** 2) * $T) / ($sigma * sqrt($T));
        $d2 = $d1 - $sigma * sqrt($T);
        return $S * exp(-$r * $T) * $this->norm_cdf($d1) - $K * exp(-$r * $T) * $this->norm_cdf($d2);
    }

    function norm_cdf($x) {
        return (1.0 + erf($x / sqrt(2.0))) / 2.0;
    }

    function monte_carlo($n_simulations, $depth) {
        $payoff_sum = 0;
        for ($i = 0; $i < $n_simulations; $i++) {
            $price_path = $this->price_path_simulation();
            $payoff_sum += max($price_path[count($price_path) - 1] - $this->K, 0);
        }
        return $payoff_sum / $n_simulations * exp(-$this->r * $this->T);
    }

    function price_path_simulation() {
        $path = [$this->S];
        for ($i = 0; $i < int($this->T); $i++) {
            $drift = $this->r * $path[count($path) - 1] * (1 / 252);
            $diffusion = $path[count($path) - 1] * $this->sigma * sqrt(1 / 252) * randn();
            $path[] = $path[count($path) - 1] + $drift + $diffusion;
        }
        return $path;
    }
}

function randn() {
    $u = 0;
    $v = 0;
    while ($u == 0) $u = rand() / mt_getrandmax();
    while ($v == 0) $v = rand() / mt_getrandmax();
    return sqrt(-2.0 * log($u)) * cos(2.0 * pi() * $v);
}

function main() {
    $S = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $n_simulations = 1000;
    $depth = 2;
    $pricing_model = new OptionPricing($S, $K, $T, $r, $sigma);
    $option_price = $pricing_model->calculate_price($n_simulations, $depth);
    echo 'Option Price: ' . $option_price . "\n";
}

main();