<?php

class FinancialModel {
    public $S0;
    public $K;
    public $T;
    public $r;
    public $sigma;
    public $N;

    public function __construct($S0, $K, $T, $r, $sigma, $N) {
        $this->S0 = $S0;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
        $this->N = $N;
    }

    public function simulate_paths() {
        $dt = $this->T / $this->N;
        $S = array_fill(0, $this->N, array_fill(0, $this->N, 0));
        $S[0] = $this->S0;
        for ($t = 1; $t < $this->N; $t++) {
            $Z = array_map(function() { return sqrt(rand()) * cos(2 * pi() * rand()); }, range(0, $this->N - 1));
            foreach ($Z as $i => $z) {
                $S[$t][$i] = $S[$t - 1][$i] * exp(($this->r - 0.5 * $this->sigma ** 2) * $dt + $this->sigma * sqrt($dt) * $z);
            }
        }
        return $S;
    }
}

class OptionPricer {
    public $model;

    public function __construct($model) {
        $this->model = $model;
    }

    public function european_call() {
        $S = $this->model->simulate_paths();
        $payoff = array_map(function($s) { return max($s - $this->model->K, 0); }, $S[count($S) - 1]);
        $option_price = exp(-$this->model->r * $this->model->T) * array_sum($payoff) / count($payoff);
        return $option_price;
    }

    public function european_put() {
        $S = $this->model->simulate_paths();
        $payoff = array_map(function($s) { return max($this->model->K - $s, 0); }, $S[count($S) - 1]);
        $option_price = exp(-$this->model->r * $this->model->T) * array_sum($payoff) / count($payoff);
        return $option_price;
    }
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 1000;
    $model = new FinancialModel($S0, $K, $T, $r, $sigma, $N);
    $pricer = new OptionPricer($model);
    $call_price = $pricer->european_call();
    $put_price = $pricer->european_put();
    echo 'European Call Price: ' . $call_price . "\n";
    echo 'European Put Price: ' . $put_price . "\n";
}

main();

?>