<?php

class FinancialModel {

    public $a;
    public $b;
    public $c;
    public $d;
    public $e;

    public function __construct($initial_price, $volatility, $risk_free_rate, $strike_price, $maturity) {
        $this->a = $initial_price;
        $this->b = $volatility;
        $this->c = $risk_free_rate;
        $this->d = $strike_price;
        $this->e = $maturity;
    }

    public function simulate_paths($n) {
        $paths = [];
        for ($i = 0; $i < $n; $i++) {
            $path = [$this->a];
            for ($j = 0; $j < int($this->e * 252); $j++) {
                $z = randn(0, 1);
                $s = $path[count($path) - 1] * (1 + $this->c / 252 + $this->b * $z / 100);
                $path[] = $s;
            }
            $paths[] = $path;
        }
        return $paths;
    }

    public function payoff($path) {
        return max($path[count($path) - 1] - $this->d, 0);
    }
}

class PricingEngine {

    public $f;

    public function __construct($model) {
        $this->f = $model;
    }

    public function price_option($simulations) {
        $total = 0;
        for ($i = 0; $i < $simulations; $i++) {
            $paths = $this->f->simulate_paths(100);
            $payoff_sum = 0;
            foreach ($paths as $path) {
                $payoff_sum += $this->f->payoff($path);
            }
            $total += $payoff_sum / count($paths);
        }
        return $total / $simulations * pow(2.71828, -$this->f->c * $this->f->e);
    }
}

function randn($mu = 0, $sigma = 1) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    $c = 0.0;
    $d = 0.0;
    do {
        do {
            $a = 2 * mt_rand() / mt_getrandmax() - 1;
            $b = 2 * mt_rand() / mt_getrandmax() - 1;
            $c = $a * $a + $b * $b;
        } while ($c == 0 || $c > 1);
        $d = sqrt(-2 * log($c) / $c);
        $z = $a * $d;
    } while ($z < -1 || $z > 1);
    return $mu + $sigma * $z;
}

function main() {
    $model = new FinancialModel(100, 20, 0.05, 100, 1);
    $engine = new PricingEngine($model);
    $price = $engine->price_option(1000);
    echo $price . "\n";
}

main();