<?php

class FinancialModel {
    public $S0;
    public $K;
    public $T;
    public $r;
    public $sigma;
    public $N;
    public $dt;

    function __construct($S0, $K, $T, $r, $sigma, $N) {
        $this->S0 = $S0;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
        $this->N = $N;
        $this->dt = $T / $N;
    }

    function simulate_paths() {
        $paths = array_fill(0, $this->N + 1, array_fill(0, count($this->S0), 0));
        $paths[0] = $this->S0;
        for ($t = 1; $t <= $this->N; $t++) {
            $z = array_map(function() { return randn(); }, $this->S0);
            for ($i = 0; $i < count($this->S0); $i++) {
                $paths[$t][$i] = $paths[$t - 1][$i] * exp(($this->r - 0.5 * $this->sigma ** 2) * $this->dt + $this->sigma * sqrt($this->dt) * $z[$i]);
            }
        }
        return $paths;
    }

    function payoff($paths) {
        $payoff = array_map(function($x) { return max($x - $this->K, 0); }, $paths[count($paths) - 1]);
        return $payoff;
    }
}

class OptionPricer {
    public $financial_model;
    public $M;

    function __construct($financial_model, $M) {
        $this->financial_model = $financial_model;
        $this->M = $M;
    }

    function price_option() {
        $payoffs = array_fill(0, $this->M, 0);
        for ($i = 0; $i < $this->M; $i++) {
            $paths = $this->financial_model->simulate_paths();
            $payoffs[$i] = array_sum($this->financial_model->payoff($paths)) / count($this->financial_model->payoff($paths));
        }
        $option_price = exp(-$this->financial_model->r * $this->financial_model->T) * array_sum($payoffs) / count($payoffs);
        return $option_price;
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
    $S0 = [100, 100, 100];
    $K = 100;
    $T = 1.0;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $M = 10000;
    $financial_model = new FinancialModel($S0, $K, $T, $r, $sigma, $N);
    $option_pricer = new OptionPricer($financial_model, $M);
    echo $option_pricer->price_option() . "\n";
}

main();

?>