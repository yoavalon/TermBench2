<?php

class Option {
    public $strike;
    public $maturity;

    public function __construct($strike, $maturity) {
        $this->strike = $strike;
        $this->maturity = $maturity;
    }

    public function payoff($spot) {
        return max($spot - $this->strike, 0);
    }
}

class MonteCarloPricer {
    public $option;
    public $initial_price;
    public $volatility;
    public $risk_free_rate;
    public $steps;
    public $simulations;
    public $dt;

    public function __construct($option, $initial_price, $volatility, $risk_free_rate, $steps, $simulations) {
        $this->option = $option;
        $this->initial_price = $initial_price;
        $this->volatility = $volatility;
        $this->risk_free_rate = $risk_free_rate;
        $this->steps = $steps;
        $this->simulations = $simulations;
        $this->dt = $option->maturity / $steps;
    }

    public function simulate_paths() {
        $paths = array_fill(0, $this->simulations, array($this->initial_price));
        for ($i = 1; $i < $this->steps; $i++) {
            for ($j = 0; $j < $this->simulations; $j++) {
                $paths[$j][] = $paths[$j][$i - 1] * exp(($this->risk_free_rate - 0.5 * $this->volatility ** 2) * $this->dt + $this->volatility * sqrt($this->dt) * (2 * (mt_rand() / mt_getrandmax() - 0.5)));
            }
        }
        return $paths;
    }

    public function price_option() {
        $paths = $this->simulate_paths();
        $payoffs = array_map(function($path) {
            return $this->option->payoff($path[count($path) - 1]);
        }, $paths);
        return exp(-$this->risk_free_rate * $this->option->maturity) * array_sum($payoffs) / $this->simulations;
    }
}

function main() {
    $strike = 100;
    $maturity = 1.0;
    $initial_price = 100;
    $volatility = 0.2;
    $risk_free_rate = 0.05;
    $steps = 100;
    $simulations = 1000;
    $option = new Option($strike, $maturity);
    $pricer = new MonteCarloPricer($option, $initial_price, $volatility, $risk_free_rate, $steps, $simulations);
    $price = $pricer->price_option();
    echo 'Option price: ' . $price;
}

main();