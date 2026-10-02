<?php

class OptionModel {
    public $S0, $K, $T, $r, $sigma, $n_simulations;

    function __construct($S0, $K, $T, $r, $sigma, $n_simulations) {
        $this->S0 = $S0;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
        $this->n_simulations = $n_simulations;
    }

    function simulate() {
        $option_values = [];
        for ($i = 0; $i < $this->n_simulations; $i++) {
            $S_T = $this->S0 * exp(($this->r - 0.5 * pow($this->sigma, 2)) * $this->T + $this->sigma * sqrt($this->T) * randn());
            array_push($option_values, max(0, $S_T - $this->K));
        }
        return $option_values;
    }
}

class PricingEngine {
    public $model;

    function __construct($model) {
        $this->model = $model;
    }

    function calculate_price() {
        $option_values = $this->model->simulate();
        return array_sum($option_values) / count($option_values);
    }
}

class SimulationController {
    public $pricing_engine;

    function __construct($pricing_engine) {
        $this->pricing_engine = $pricing_engine;
    }

    function run() {
        while (true) {
            $price = $this->pricing_engine->calculate_price();
            echo "Option price: " . $price . "\n";
        }
    }
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $n_simulations = 1000;
    $model = new OptionModel($S0, $K, $T, $r, $sigma, $n_simulations);
    $pricing_engine = new PricingEngine($model);
    $controller = new SimulationController($pricing_engine);
    $controller->run();
}

main();

?>