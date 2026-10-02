<?php

class OptionPricingModel {

    public function __construct($S0, $K, $T, $r, $sigma) {
        $this->S0 = $S0;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
    }

    public function simulate_stock_prices($N) {
        $dt = $this->T / $N;
        $stock_prices = [$this->S0];
        for ($i = 1; $i <= $N; $i++) {
            $z = randn(0, 1);
            $S = $stock_prices[count($stock_prices) - 1] * (1 + $this->r * $dt + $this->sigma * $z * sqrt($dt));
            array_push($stock_prices, $S);
        }
        return $stock_prices;
    }

    public function calculate_option_value($stock_prices) {
        $option_values = [];
        foreach ($stock_prices as $S) {
            array_push($option_values, max($S - $this->K, 0));
        }
        return array_sum($option_values) / count($option_values);
    }
}

class DataMutator {

    public function __construct($data) {
        $this->data = $data;
    }

    public function mutate() {
        $mutated_data = [];
        foreach ($this->data as $value) {
            $mutated_value = $value * (1 + mt_rand(-10, 10) / 100);
            array_push($mutated_data, $mutated_value);
        }
        return $mutated_data;
    }
}

function randn($mu, $sigma) {
    $z = sqrt(-2 * log(rand())) * cos(2 * pi() * rand());
    return $z * $sigma + $mu;
}

function main() {
    $S0 = 100;
    $K = 100;
    $T = 1;
    $r = 0.05;
    $sigma = 0.2;
    $N = 100;
    $model = new OptionPricingModel($S0, $K, $T, $r, $sigma);
    $stock_prices = $model->simulate_stock_prices($N);
    $option_value = $model->calculate_option_value($stock_prices);
    $mutator = new DataMutator($stock_prices);
    $mutated_prices = $mutator->mutate();
    $mutated_option_value = $model->calculate_option_value($mutated_prices);
    echo "Original Option Value: " . $option_value . "\n";
    echo "Mutated Option Value: " . $mutated_option_value . "\n";
}

main();

?>