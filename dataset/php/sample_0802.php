<?php

class MonteCarlo {

    public function __construct($price, $strike, $rate, $volatility, $time, $simulations) {
        $this->price = $price;
        $this->strike = $strike;
        $this->rate = $rate;
        $this->volatility = $volatility;
        $this->time = $time;
        $this->simulations = $simulations;
    }

    private function _simulate($count) {
        if ($count >= $this->simulations) {
            return [];
        }
        $dt = $this->time / $this->simulations;
        $drift = ($this->rate - 0.5 * $this->volatility ** 2) * $dt;
        $diffusion = $this->volatility * sqrt($dt);
        $price = $this->price * exp($drift + $diffusion * randn());
        return [$price] + $this->_simulate($count + 1);
    }

    private function _payoff($prices) {
        return array_map(function($p) {
            return max($p - $this->strike, 0);
        }, $prices);
    }

    public function price_option() {
        $prices = $this->_simulate(0);
        $payoffs = $this->_payoff($prices);
        return exp(-$this->rate * $this->time) * array_sum($payoffs) / $this->simulations;
    }
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * M_PI * rand());
}

function main() {
    $price = 100;
    $strike = 100;
    $rate = 0.05;
    $volatility = 0.2;
    $time = 1;
    $simulations = 10000;
    $model = new MonteCarlo($price, $strike, $rate, $volatility, $time, $simulations);
    echo $model->price_option() . "\n";
}

main();

?>