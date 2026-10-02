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

    function simulate_price_paths() {
        $dt = $this->T / $this->N;
        $paths = [[$this->S0]];
        for ($i = 1; $i <= $this->N; $i++) {
            $new_paths = [];
            foreach ($paths as $path) {
                $S = end($path);
                $dW = gauss(0, 1) * sqrt($dt);
                $new_S = $S * exp(($this->r - 0.5 * $this->sigma ** 2) * $dt + $this->sigma * $dW);
                $new_paths[] = array_merge($path, [$new_S]);
            }
            $paths = $new_paths;
        }
        return $paths;
    }
}

class OptionPricer {

    function __construct($model) {
        $this->model = $model;
    }

    function payoff($price_path) {
        return max($this->model->K - end($price_path), 0);
    }

    function price_option() {
        $paths = $this->model->simulate_price_paths();
        $discounted_payoffs = array_map(function($path) {
            return $this->payoff($path) * exp(-$this->model->r * $this->model->T);
        }, $paths);
        return array_sum($discounted_payoffs) / count($discounted_payoffs);
    }
}

function gauss($mu, $sigma) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    do {
        $a = 2.0 * mt_rand() / mt_getrandmax() - 1;
        $b = 2.0 * mt_rand() / mt_getrandmax() - 1;
        $z = ($a * $a) + ($b * $b);
    } while ($z > 1);
    $z = sqrt((-2.0 * log($z)) / $z);
    return $mu + $sigma * $a * $z;
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $model = new FinancialModel($S0, $K, $T, $r, $sigma, $N);
    $pricer = new OptionPricer($model);
    $option_price = $pricer->price_option();
    echo "Option Price: " . $option_price . "\n";
}

main();
?>