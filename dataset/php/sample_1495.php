<?php

class OptionPricer {

    public $S;
    public $K;
    public $T;
    public $r;
    public $sigma;

    public function __construct($S, $K, $T, $r, $sigma) {
        $this->S = $S;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
    }

    public function d1() {
        return (log($this->S / $this->K) + ($this->r + 0.5 * $this->sigma ** 2) * $this->T) / ($this->sigma * sqrt($this->T));
    }

    public function d2() {
        return $this->d1() - $this->sigma * sqrt($this->T);
    }

    public function call_price() {
        return $this->S * exp(-$this->r * $this->T) * $this->cdf($this->d1()) - $this->K * exp(-$this->r * $this->T) * $this->cdf($this->d2());
    }

    public function put_price() {
        return $this->K * exp(-$this->r * $this->T) * $this->cdf(-$this->d2()) - $this->S * exp(-$this->r * $this->T) * $this->cdf(-$this->d1());
    }

    public function cdf($x) {
        return 0.5 * (1 + erf($x / sqrt(2)));
    }
}

class MonteCarloSimulator {

    public $pricer;
    public $simulations;

    public function __construct($pricer, $simulations) {
        $this->pricer = $pricer;
        $this->simulations = $simulations;
    }

    public function simulate() {
        $call_values = [];
        $put_values = [];
        for ($i = 0; $i < $this->simulations; $i++) {
            $S_T = $this->pricer->S * exp(($this->pricer->r - 0.5 * $this->pricer->sigma ** 2) * $this->pricer->T + $this->pricer->sigma * sqrt($this->pricer->T) * randn());
            $call_values[] = max($S_T - $this->pricer->K, 0);
            $put_values[] = max($this->pricer->K - $S_T, 0);
        }
        return (array_sum($call_values) / $this->simulations, array_sum($put_values) / $this->simulations);
    }
}

function randn() {
    $u = 0.0;
    $v = 0.0;
    while ($u == 0.0) {
        $u = rand() / mt_getrandmax();
    }
    while ($v == 0.0) {
        $v = rand() / mt_getrandmax();
    }
    return sqrt(-2.0 * log($u)) * cos(2.0 * pi() * $v);
}

function main() {
    $S = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $simulations = 10000;
    $pricer = new OptionPricer($S, $K, $T, $r, $sigma);
    $simulator = new MonteCarloSimulator($pricer, $simulations);
    list($call_price, $put_price) = $simulator->simulate();
    echo 'Call Price: ' . $call_price . "\n";
    echo 'Put Price: ' . $put_price . "\n";
}

main();
?>