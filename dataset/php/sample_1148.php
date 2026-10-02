<?php

class OptionPricer {
    public $S;
    public $K;
    public $T;
    public $r;
    public $sigma;
    public $N;
    public $M;

    function __construct($S, $K, $T, $r, $sigma, $N, $M) {
        $this->S = $S;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
        $this->N = $N;
        $this->M = $M;
    }

    function simulate_stock_prices() {
        $dt = $this->T / $this->N;
        $paths = array_fill(0, $this->M, array($this->S));
        for ($t = 1; $t <= $this->N; $t++) {
            for ($i = 0; $i < $this->M; $i++) {
                $z = rand() / mt_getrandmax() * 2 - 1;
                $S_next = end($paths[$i]) * exp(($this->r - 0.5 * pow($this->sigma, 2)) * $dt + $this->sigma * $z * sqrt($dt));
                $paths[$i][] = $S_next;
            }
        }
        return $paths;
    }

    function payoff($paths) {
        $payoffs = array();
        foreach ($paths as $path) {
            $payoffs[] = max(end($path) - $this->K, 0);
        }
        return $payoffs;
    }

    function price_option() {
        $paths = $this->simulate_stock_prices();
        $payoffs = $this->payoff($paths);
        $C = exp(-$this->r * $this->T) * array_sum($payoffs) / $this->M;
        return $C;
    }
}

function main() {
    $pricer = new OptionPricer(100, 100, 1, 0.05, 0.2, 100, 1000);
    while (true) {
        $price = $pricer->price_option();
        echo "Option price: $price\n";
    }
}

main();