<?php

class DataMutation {

    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function apply_mutation($mutation_function) {
        $this->data = $mutation_function($this->data);
        return $this->data;
    }
}

class FinancialModel {

    public $initial_price;
    public $volatility;
    public $risk_free_rate;
    public $time_steps;
    public $simulations;

    public function __construct($initial_price, $volatility, $risk_free_rate, $time_steps, $simulations) {
        $this->initial_price = $initial_price;
        $this->volatility = $volatility;
        $this->risk_free_rate = $risk_free_rate;
        $this->time_steps = $time_steps;
        $this->simulations = $simulations;
    }

    public function simulate_paths() {
        $dt = 1 / $this->time_steps;
        $drift = ($this->risk_free_rate - 0.5 * pow($this->volatility, 2)) * $dt;
        $diffusion = $this->volatility * sqrt($dt);
        $paths = array_fill(0, $this->time_steps + 1, array_fill(0, $this->simulations, 0));
        $paths[0] = $this->initial_price;
        for ($t = 1; $t <= $this->time_steps; $t++) {
            $rand = array_map(function($x) { return mt_rand() / mt_getrandmax(); }, range(0, $this->simulations - 1));
            for ($i = 0; $i < $this->simulations; $i++) {
                $paths[$t][$i] = $paths[$t - 1][$i] * exp($drift + $diffusion * $rand[$i]);
            }
        }
        return $paths;
    }

    public function calculate_payoff($strike_price, $option_type = 'call') {
        $paths = $this->simulate_paths();
        if ($option_type == 'call') {
            $payoff = array_map(function($x) use ($strike_price) { return max($x - $strike_price, 0); }, $paths[$this->time_steps]);
        } elseif ($option_type == 'put') {
            $payoff = array_map(function($x) use ($strike_price) { return max($strike_price - $x, 0); }, $paths[$this->time_steps]);
        }
        return $payoff;
    }

    public function price_option($strike_price, $option_type = 'call') {
        $payoff = $this->calculate_payoff($strike_price, $option_type);
        $option_price = exp(-$this->risk_free_rate * $this->time_steps) * array_sum($payoff) / count($payoff);
        return $option_price;
    }
}

function main() {
    $data = array_map(function($x) { return mt_rand() / mt_getrandmax(); }, range(0, 99));
    $data_mutator = new DataMutation($data);
    $mutated_data = $data_mutator->apply_mutation(function($x) { return $x * 2; });
    $financial_model = new FinancialModel($mutated_data[0], 0.2, 0.05, 252, 10000);
    $option_price = $financial_model->price_option(100, 'call');
    echo $option_price;
}

main();

?>