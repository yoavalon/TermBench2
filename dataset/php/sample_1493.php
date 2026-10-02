<?php

class OptionPricer {
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
        $paths = array_fill(0, $this->N + 1, array_fill(0, count($this->S0), 0));
        $paths[0] = $this->S0;
        for ($i = 1; $i <= $this->N; $i++) {
            $z = array_map(function($_) { return randn(); }, $this->S0);
            for ($j = 0; $j < count($this->S0); $j++) {
                $paths[$i][$j] = $paths[$i - 1][$j] * exp(($this->r - 0.5 * $this->sigma ** 2) * $dt + $this->sigma * sqrt($dt) * $z[$j]);
            }
        }
        return $paths;
    }

    public function calculate_payoff($paths) {
        $payoff = array_map(function($S) { return max($S - $this->K, 0); }, $paths[count($paths) - 1]);
        return $payoff;
    }
}

class MonteCarloEngine {
    public $pricer;
    public $num_simulations;

    public function __construct($pricer, $num_simulations) {
        $this->pricer = $pricer;
        $this->num_simulations = $num_simulations;
    }

    public function run() {
        $payoffs = array_fill(0, $this->num_simulations, 0);
        for ($i = 0; $i < $this->num_simulations; $i++) {
            $paths = $this->pricer->simulate_paths();
            $payoffs[$i] = $this->pricer->calculate_payoff($paths);
        }
        $price = exp(-$this->pricer->r * $this->pricer->T) * array_sum($payoffs) / $this->num_simulations;
        return $price;
    }
}

function randn() {
    $u = 0;
    $v = 0;
    while ($u == 0) $u = rand() / mt_getrandmax();
    while ($v == 0) $v = rand() / mt_getrandmax();
    return sqrt(-2 * log($u)) * cos(2 * pi() * $v);
}

function main() {
    $S0 = [100];
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 252;
    $num_simulations = 10000;
    $pricer = new OptionPricer($S0, $K, $T, $r, $sigma, $N);
    $engine = new MonteCarloEngine($pricer, $num_simulations);
    $option_price = $engine->run();
    echo "Option Price: $option_price\n";
}

main();

?>