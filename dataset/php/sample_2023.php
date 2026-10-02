<?php

class FinancialModel {

    function __construct($S0, $K, $T, $r, $sigma, $N, $M) {
        $this->S0 = $S0;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
        $this->N = $N;
        $this->M = $M;
    }

    function simulate_paths() {
        $dt = $this->T / $this->N;
        $S = array_fill(0, $this->M, array_fill(0, $this->N + 1, 0));
        for ($i = 0; $i < $this->M; $i++) {
            $S[$i][0] = $this->S0;
        }
        for ($t = 1; $t <= $this->N; $t++) {
            $Z = array();
            for ($i = 0; $i < $this->M; $i++) {
                $Z[$i] = mt_rand() / mt_getrandmax() * 2 - 1;
            }
            for ($i = 0; $i < $this->M; $i++) {
                $S[$i][$t] = $S[$i][$t - 1] * exp(($this->r - 0.5 * pow($this->sigma, 2)) * $dt + $this->sigma * sqrt($dt) * $Z[$i]);
            }
        }
        return $S;
    }

    function calculate_option_price() {
        $S = $this->simulate_paths();
        $payoff = array();
        for ($i = 0; $i < $this->M; $i++) {
            $payoff[$i] = max($S[$i][$this->N] - $this->K, 0);
        }
        $option_price = exp(-$this->r * $this->T) * array_sum($payoff) / $this->M;
        return $option_price;
    }
}

function main() {
    $S0 = 100.0;
    $K = 100.0;
    $T = 1.0;
    $r = 0.05;
    $sigma = 0.2;
    $N = 252;
    $M = 10000;
    $model = new FinancialModel($S0, $K, $T, $r, $sigma, $N, $M);
    $price = $model->calculate_option_price();
    echo 'Option price: ' . number_format($price, 4);
}

main();

?>