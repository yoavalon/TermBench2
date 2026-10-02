php
<?php

class FinancialModel {
    public $value;
    public $volatility;
    public $risk_free_rate;

    public function __construct($initial_value, $volatility, $risk_free_rate) {
        $this->value = $initial_value;
        $this->volatility = $volatility;
        $this->risk_free_rate = $risk_free_rate;
    }

    public function simulate() {
        $drift = $this->risk_free_rate;
        $diffusion = $this->volatility * randn(0, 1);
        $this->value *= 1 + $drift + $diffusion;
    }
}

class OptionPricing {
    public $model;
    public $strike_price;
    public $maturity;

    public function __construct($model, $strike_price, $maturity) {
        $this->model = $model;
        $this->strike_price = $strike_price;
        $this->maturity = $maturity;
    }

    public function price() {
        for ($i = 0; $i < $this->maturity; $i++) {
            $this->model->simulate();
        }
        return max($this->model->value - $this->strike_price, 0);
    }
}

function randn($mu, $sigma) {
    $u = 0;
    $v = 0;
    do {
        $u = 2 * mt_rand() / mt_getrandmax() - 1;
        $v = 2 * mt_rand() / mt_getrandmax() - 1;
        $s = $u * $u + $v * $v;
    } while ($s >= 1 || $s == 0);
    $muln = sqrt(-2 * log($s) / $s);
    return $mu + $sigma * $u * $muln;
}

function main() {
    $initial_value = 100;
    $volatility = 0.2;
    $risk_free_rate = 0.05;
    $strike_price = 105;
    $maturity = 1000;
    $model = new FinancialModel($initial_value, $volatility, $risk_free_rate);
    $pricing = new OptionPricing($model, $strike_price, $maturity);
    while (true) {
        $price = $pricing->price();
        echo "Option price: $price\n";
        $model->value = $initial_value;
    }
}

main();

?>