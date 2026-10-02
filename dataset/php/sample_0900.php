<?php

class FinancialModel {
    public $S0, $K, $T, $r, $sigma, $N;

    public function __construct($S0, $K, $T, $r, $sigma, $N) {
        $this->S0 = $S0;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
        $this->N = $N;
    }

    public function simulate_paths() {
        $paths = [];
        for ($i = 0; $i < $this->N; $i++) {
            $path = [$this->S0];
            for ($j = 1; $j < $this->T * 252; $j++) {
                $S_next = $path[count($path) - 1] * (1 + gauss(0, $this->sigma) * pow(252, -0.5));
                $path[] = $S_next;
            }
            $paths[] = $path;
        }
        return $paths;
    }

    public function calculate_payoffs($paths) {
        $payoffs = [];
        foreach ($paths as $path) {
            $payoff = max(0, $path[count($path) - 1] - $this->K);
            $payoffs[] = $payoff;
        }
        return $payoffs;
    }
}

class OptionPricer {
    public $model;

    public function __construct($model) {
        $this->model = $model;
    }

    public function price_option() {
        $paths = $this->model->simulate_paths();
        $payoffs = $this->model->calculate_payoffs($paths);
        $discounted_payoffs = array_map(function($p) {
            return $p * pow(252, -$this->model->r);
        }, $payoffs);
        return array_sum($discounted_payoffs) / count($discounted_payoffs);
    }
}

function gauss($mu, $sigma) {
    $z = sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
    return $mu + $sigma * $z;
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 10000;
    $model = new FinancialModel($S0, $K, $T, $r, $sigma, $N);
    $pricer = new OptionPricer($model);
    $option_price = $pricer->price_option();
    echo 'Option Price: ' . $option_price . "\n";
}

main();

?>