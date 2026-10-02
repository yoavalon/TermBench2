<?php

class FinancialModel {
    public $price;
    public $volatility;
    public $strike;
    public $rate;
    public $tau;

    function __construct($initial_price, $volatility, $strike_price, $risk_free_rate, $time_to_maturity) {
        $this->price = $initial_price;
        $this->volatility = $volatility;
        $this->strike = $strike_price;
        $this->rate = $risk_free_rate;
        $this->tau = $time_to_maturity;
    }

    function simulate_step() {
        $dW = gauss(0, 1);
        $dS = $this->price * $this->volatility * $dW * pow($this->tau, 0.5);
        $this->price += $dS;
    }

    function calculate_option_value() {
        return max(0, $this->price - $this->strike);
    }
}

class BoundaryConditions {
    public $lower;
    public $upper;
    public $threshold;
    public $max_steps;

    function __construct($lower_bound, $upper_bound, $threshold, $max_steps) {
        $this->lower = $lower_bound;
        $this->upper = $upper_bound;
        $this->threshold = $threshold;
        $this->max_steps = $max_steps;
    }

    function check_conditions($price, $step_count) {
        if ($step_count >= $this->max_steps || $price <= $this->lower || $price >= $this->upper) {
            return true;
        }
        return false;
    }
}

function gauss($mu, $sigma) {
    $z = 0.0;
    for ($i = 0; $i < 12; $i++) {
        $z += mt_rand() / mt_getrandmax();
    }
    return $mu + $sigma * ($z - 6);
}

function main() {
    $initial_price = 100;
    $volatility = 0.2;
    $strike_price = 100;
    $risk_free_rate = 0.05;
    $time_to_maturity = 1;
    $lower_bound = 80;
    $upper_bound = 120;
    $threshold = 0.01;
    $max_steps = 1000;
    $financial_model = new FinancialModel($initial_price, $volatility, $strike_price, $risk_free_rate, $time_to_maturity);
    $boundary_conditions = new BoundaryConditions($lower_bound, $upper_bound, $threshold, $max_steps);
    $step_count = 0;
    while (!$boundary_conditions->check_conditions($financial_model->price, $step_count)) {
        $financial_model->simulate_step();
        $step_count++;
    }
    $option_value = $financial_model->calculate_option_value();
    echo 'Option Value: ' . $option_value . "\n";
}

main();
?>