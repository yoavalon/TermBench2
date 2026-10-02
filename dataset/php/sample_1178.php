<?php

class OptionPricer {

    function __construct($S, $K, $T, $r, $sigma) {
        $this->S = $S;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
    }

    function simulate_paths($num_simulations, $num_steps) {
        $paths = array();
        for ($i = 0; $i < $num_simulations; $i++) {
            $path = array($this->S);
            for ($j = 0; $j < $num_steps - 1; $j++) {
                $delta_t = $this->T / $num_steps;
                $drift = ($this->r - 0.5 * $this->sigma ** 2) * $delta_t;
                $diffusion = $this->sigma * randn() * sqrt($delta_t);
                $next_price = end($path) * (1 + $drift + $diffusion);
                array_push($path, $next_price);
            }
            array_push($paths, $path);
        }
        return $paths;
    }

    function calculate_payoff($paths) {
        $payoffs = array();
        foreach ($paths as $path) {
            $payoff = max(end($path) - $this->K, 0);
            array_push($payoffs, $payoff);
        }
        return $payoffs;
    }

    function price_option($num_simulations, $num_steps) {
        $paths = $this->simulate_paths($num_simulations, $num_steps);
        $payoffs = $this->calculate_payoff($paths);
        $option_price = array_sum($payoffs) / $num_simulations * (1 / $this->r);
        return $option_price;
    }
}

function recursive_pricer($pricer, $num_simulations, $num_steps) {
    $current_price = $pricer->price_option($num_simulations, $num_steps);
    echo "Current option price: " . $current_price . "\n";
    return recursive_pricer($pricer, $num_simulations, $num_steps);
}

function randn() {
    $u = 0;
    $v = 0;
    while ($u == 0) $u = rand() / mt_getrandmax();
    while ($v == 0) $v = rand() / mt_getrandmax();
    $z0 = sqrt(-2.0 * log($u)) * cos(2.0 * pi() * $v);
    return $z0;
}

function main() {
    $S = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $pricer = new OptionPricer($S, $K, $T, $r, $sigma);
    recursive_pricer($pricer, 1000, 100);
}

main();
?>