<?php

class FinancialModel {
    public $S0;
    public $K;
    public $T;
    public $r;
    public $sigma;
    public $N;
    public $M;

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
        $paths = array_fill(0, $this->N + 1, array_fill(0, $this->M, 0));
        $paths[0] = $this->S0;
        for ($i = 1; $i <= $this->N; $i++) {
            $z = array_fill(0, $this->M, 0);
            for ($j = 0; $j < $this->M; $j++) {
                $z[$j] = mt_rand() / mt_getrandmax() * 2 - 1;
            }
            for ($j = 0; $j < $this->M; $j++) {
                $paths[$i][$j] = $paths[$i - 1][$j] * exp(($this->r - 0.5 * $this->sigma ** 2) * $dt + $this->sigma * sqrt($dt) * $z[$j]);
            }
        }
        return $paths;
    }

    function option_price() {
        $paths = $this->simulate_paths();
        $payoff = array_fill(0, $this->M, 0);
        for ($j = 0; $j < $this->M; $j++) {
            $payoff[$j] = max($paths[$this->N][$j] - $this->K, 0);
        }
        $price = exp(-$this->r * $this->T) * array_sum($payoff) / $this->M;
        return $price;
    }
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $M = 10000;
    $model = new FinancialModel($S0, $K, $T, $r, $sigma, $N, $M);
    $price = $model->option_price();
    echo $price;
}

main();

?>