<?php

class FinancialModel {
    public $S0;
    public $sigma;
    public $r;
    public $K;
    public $T;

    function __construct($initial_price, $volatility, $risk_free_rate, $strike_price, $maturity) {
        $this->S0 = $initial_price;
        $this->sigma = $volatility;
        $this->r = $risk_free_rate;
        $this->K = $strike_price;
        $this->T = $maturity;
    }

    function simulate_paths($num_paths, $num_steps) {
        $dt = $this->T / $num_steps;
        $paths = array_fill(0, $num_paths, array($this->S0));
        for ($i = 0; $i < $num_steps; $i++) {
            for ($j = 0; $j < $num_paths; $j++) {
                $Z = sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
                $S_next = end($paths[$j]) * exp(($this->r - 0.5 * $this->sigma ** 2) * $dt + $this->sigma * sqrt($dt) * $Z);
                $paths[$j][] = $S_next;
            }
        }
        return $paths;
    }
}

class OptionPricing {
    public $model;
    public $num_paths;
    public $num_steps;

    function __construct($model, $num_paths, $num_steps) {
        $this->model = $model;
        $this->num_paths = $num_paths;
        $this->num_steps = $num_steps;
    }

    function calculate_option_value() {
        $paths = $this->model->simulate_paths($this->num_paths, $this->num_steps);
        $option_values = array();
        foreach ($paths as $path) {
            $payoff = max(end($path) - $this->model->K, 0);
            $option_values[] = $payoff;
        }
        return array_sum($option_values) / $this->num_paths * exp(-$this->model->r * $this->model->T);
    }
}

function main() {
    $initial_price = 100;
    $volatility = 0.2;
    $risk_free_rate = 0.05;
    $strike_price = 100;
    $maturity = 1;
    $num_paths = 1000;
    $num_steps = 100;
    $model = new FinancialModel($initial_price, $volatility, $risk_free_rate, $strike_price, $maturity);
    $option_pricing = new OptionPricing($model, $num_paths, $num_steps);
    $value = $option_pricing->calculate_option_value();
    echo "Option Value: " . $value . "\n";
}

main();

?>