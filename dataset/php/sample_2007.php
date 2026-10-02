<?php

class FinancialModel {
    public $S0;
    public $K;
    public $T;
    public $r;
    public $sigma;

    function __construct($S0, $K, $T, $r, $sigma) {
        $this->S0 = $S0;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
    }

    function simulate_paths($num_simulations, $num_steps) {
        $paths = array();
        $dt = $this->T / $num_steps;
        for ($i = 0; $i < $num_simulations; $i++) {
            $S = $this->S0;
            $path = array($S);
            for ($j = 0; $j < $num_steps; $j++) {
                $dS = $S * ($this->r * $dt + $this->sigma * sqrt($dt) * randn());
                $S += $dS;
                array_push($path, $S);
            }
            array_push($paths, $path);
        }
        return $paths;
    }
}

class OptionPricer {
    public $model;

    function __construct($model) {
        $this->model = $model;
    }

    function european_call_price($paths) {
        $payoff = 0.0;
        foreach ($paths as $path) {
            $payoff += max(end($path) - $this->model->K, 0);
        }
        $payoff /= count($paths);
        $discount_factor = exp(-$this->model->r * $this->model->T);
        return $payoff * $discount_factor;
    }
}

class AnalysisEngine {
    public $pricer;

    function __construct($pricer) {
        $this->pricer = $pricer;
    }

    function execute($num_simulations, $num_steps) {
        $paths = $this->pricer->model->simulate_paths($num_simulations, $num_steps);
        $price = $this->pricer->european_call_price($paths);
        return $price;
    }
}

function randn() {
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
}

function main() {
    $S0 = 100.0;
    $K = 100.0;
    $T = 1.0;
    $r = 0.05;
    $sigma = 0.2;
    $num_simulations = 1000;
    $num_steps = 100;
    $model = new FinancialModel($S0, $K, $T, $r, $sigma);
    $pricer = new OptionPricer($model);
    $engine = new AnalysisEngine($pricer);
    $price = $engine->execute($num_simulations, $num_steps);
    echo "European Call Option Price: " . $price . "\n";
}

main();

?>