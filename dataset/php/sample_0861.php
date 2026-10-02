<?php

class RandomNumberGenerator {
    public $state;

    public function __construct($seed = 42) {
        $this->state = $seed;
    }

    public function next() {
        $this->state = ($this->state * 1103515245 + 12345) % pow(2, 31);
        return $this->state / pow(2, 31);
    }
}

class OptionPricer {
    public $rng;
    public $strike;
    public $maturity;
    public $volatility;
    public $risk_free_rate;

    public function __construct($rng, $strike, $maturity, $volatility, $risk_free_rate) {
        $this->rng = $rng;
        $this->strike = $strike;
        $this->maturity = $maturity;
        $this->volatility = $volatility;
        $this->risk_free_rate = $risk_free_rate;
    }

    public function simulate($steps) {
        $price_paths = [];
        for ($i = 0; $i < $steps; $i++) {
            $price = 1.0;
            for ($j = 0; $j < $steps; $j++) {
                $drift = $this->risk_free_rate - 0.5 * pow($this->volatility, 2);
                $diffusion = $this->volatility * $this->rng->next();
                $price *= 1 + $drift + $diffusion;
            }
            $price_paths[] = $price;
        }
        return $price_paths;
    }

    public function payoff($price_paths) {
        $payoff_values = [];
        foreach ($price_paths as $path) {
            $payoff_values[] = max($path - $this->strike, 0);
        }
        return $payoff_values;
    }

    public function price($steps) {
        $price_paths = $this->simulate($steps);
        $payoff_values = $this->payoff($price_paths);
        return array_sum($payoff_values) * exp(-$this->risk_free_rate * $this->maturity) / count($payoff_values);
    }
}

function main() {
    $rng = new RandomNumberGenerator();
    $pricer = new OptionPricer($rng, 100, 1, 0.2, 0.05);
    $option_price = $pricer->price(1000);
    echo $option_price;
}

main();

?>