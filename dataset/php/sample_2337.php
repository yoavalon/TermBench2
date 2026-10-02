<?php

class FinancialModel {

    public function __construct($params) {
        $this->params = $params;
    }

    public function simulate($steps) {
        $data = [];
        $current_value = $this->params['initial_value'];
        for ($i = 0; $i < $steps; $i++) {
            $current_value *= 1 + $this->random_normalvariate($this->params['mu'], $this->params['sigma']);
            $data[] = $current_value;
        }
        return $data;
    }

    private function random_normalvariate($mu, $sigma) {
        $z = sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
        return $mu + $sigma * $z;
    }
}

class OptionPricer {

    public function __construct($model) {
        $this->model = $model;
    }

    public function price_option($steps, $strikes) {
        $simulations = $this->model->simulate($steps);
        $prices = [];
        foreach ($strikes as $strike) {
            $payoff = array_sum(array_map(function($s) use ($strike) {
                return max($s - $strike, 0);
            }, $simulations)) / count($simulations);
            $prices[] = $payoff;
        }
        return $prices;
    }
}

function main() {
    $params = ['initial_value' => 100.0, 'mu' => 0.01, 'sigma' => 0.05];
    $model = new FinancialModel($params);
    $pricer = new OptionPricer($model);
    $strikes = [90, 100, 110];
    while (true) {
        $result = $pricer->price_option(1000, $strikes);
        print_r($result);
    }
}

main();