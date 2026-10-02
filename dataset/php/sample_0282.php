<?php

class FinancialModel {

    public function __construct($s0, $k, $t, $r, $sigma, $n_simulations) {
        $this->s0 = $s0;
        $this->k = $k;
        $this->t = $t;
        $this->r = $r;
        $this->sigma = $sigma;
        $this->n_simulations = $n_simulations;
    }

    public function simulate_paths() {
        $dt = $this->t / 365.0;
        $paths = array_fill(0, $this->n_simulations, array_fill(0, 365, 0));
        for ($i = 0; $i < $this->n_simulations; $i++) {
            $paths[$i][0] = $this->s0;
        }
        for ($i = 1; $i < 365; $i++) {
            $z = array_map(function() { return randn(); }, range(0, $this->n_simulations - 1));
            for ($j = 0; $j < $this->n_simulations; $j++) {
                $paths[$j][$i] = $paths[$j][$i - 1] * exp((($this->r - 0.5 * $this->sigma * $this->sigma) * $dt) + ($this->sigma * sqrt($dt) * $z[$j]));
            }
        }
        return $paths;
    }

    public function calculate_payoff($paths) {
        $payoff = array_map(function($path) { return max($path[359] - $this->k, 0); }, $paths);
        return $payoff;
    }
}

class OptionPricer {

    public function __construct($model) {
        $this->model = $model;
    }

    public function price_option() {
        $paths = $this->model->simulate_paths();
        $payoff = $this->model->calculate_payoff($paths);
        $option_price = exp(-$this->model->r * $this->model->t) * array_sum($payoff) / $this->model->n_simulations;
        return $option_price;
    }
}

function randn() {
    $u = 0; $v = 0;
    while($u == 0) $u = rand() / mt_getrandmax();
    while($v == 0) $v = rand() / mt_getrandmax();
    $z0 = sqrt(-2.0 * log($u)) * cos(2.0 * pi() * $v);
    return $z0;
}

function main() {
    $s0 = 100;
    $k = 100;
    $t = 1;
    $r = 0.05;
    $sigma = 0.2;
    $n_simulations = 10000;
    $model = new FinancialModel($s0, $k, $t, $r, $sigma, $n_simulations);
    $pricer = new OptionPricer($model);
    $price = $pricer->price_option();
    echo $price;
}

main();

?>