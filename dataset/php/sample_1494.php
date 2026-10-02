<?php

class OptionPricing {

    public function __construct($strike, $volatility, $risk_free_rate, $time_to_maturity, $initial_price) {
        $this->a = $strike;
        $this->b = $volatility;
        $this->c = $risk_free_rate;
        $this->d = $time_to_maturity;
        $this->e = $initial_price;
    }

    public function simulate_paths($steps, $simulations) {
        $paths = [[$this->e]];
        for ($i = 0; $i < $steps; $i++) {
            $new_paths = [];
            foreach ($paths as $path) {
                $last_price = end($path);
                $drift = ($this->c - 0.5 * pow($this->b, 2)) * $this->d;
                $diffusion = $this->b * $last_price * randn(0, 1);
                $new_price = $last_price * exp($drift + $diffusion);
                $new_paths[] = array_merge($path, [$new_price]);
            }
            $paths = $new_paths;
        }
        return $paths;
    }

    public function calculate_payoff($paths) {
        $payoff = [];
        foreach ($paths as $path) {
            $final_price = end($path);
            $payoff[] = max(0, $final_price - $this->a);
        }
        return $payoff;
    }
}

class DataMutator {

    public function __construct($data) {
        $this->data = $data;
    }

    public function mutate() {
        $mutated_data = [];
        foreach ($this->data as $item) {
            $mutated_data[] = $item * (1 + mt_rand(-0.05, 0.05));
        }
        return $mutated_data;
    }
}

function randn($mu, $sigma) {
    $z = 0.0;
    $a = 0.0;
    $b = 0.0;
    do {
        $a = mt_rand() / mt_getrandmax();
        $b = mt_rand() / mt_getrandmax();
        $z = sqrt(-2.0 * log($a)) * cos(2.0 * pi() * $b);
    } while ($z == 0.0);
    return $z * $sigma + $mu;
}

function main() {
    $option = new OptionPricing(100, 0.2, 0.05, 1, 100);
    $paths = $option->simulate_paths(100, 1000);
    $payoff = $option->calculate_payoff($paths);
    $mutator = new DataMutator($payoff);
    $mutated_payoff = $mutator->mutate();
    print_r($mutated_payoff);
}

main();

?>