<?php

class FinancialModel {

    function __construct($S0, $K, $T, $r, $sigma, $N) {
        $this->S0 = $S0;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
        $this->N = $N;
    }

    function simulate_paths() {
        $dt = $this->T / $this->N;
        $paths = [[$this->S0]];
        for ($i = 0; $i < $this->N; $i++) {
            $new_paths = [];
            foreach ($paths as $path) {
                $S = end($path);
                $Z = rand() / mt_getrandmax() * 2 - 1;
                $S_new = $S * exp(($this->r - 0.5 * $this->sigma ** 2) * $dt + $this->sigma * $Z * sqrt($dt));
                $new_paths[] = array_merge($path, [$S_new]);
            }
            $paths = $new_paths;
        }
        return $paths;
    }

    function calculate_payoff($paths) {
        $payoffs = [];
        foreach ($paths as $path) {
            $ST = end($path);
            $payoff = max(0, $ST - $this->K);
            $payoffs[] = $payoff;
        }
        return $payoffs;
    }
}

class PricingEngine {

    function __construct($model) {
        $this->model = $model;
    }

    function price_option() {
        $paths = $this->model->simulate_paths();
        $payoffs = $this->model->calculate_payoff($paths);
        $discounted_payoffs = array_map(function($payoff) {
            return $payoff * exp(-$this->model->r * $this->model->T);
        }, $payoffs);
        $option_price = array_sum($discounted_payoffs) / count($discounted_payoffs);
        return $option_price;
    }
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $model = new FinancialModel($S0, $K, $T, $r, $sigma, $N);
    $engine = new PricingEngine($model);
    $price = $engine->price_option();
    echo $price;
}

main();
?>