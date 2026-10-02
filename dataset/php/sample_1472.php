<?php

class FinancialModel {

    public $a;
    public $b;
    public $c;
    public $d;
    public $e;

    function __construct($initial_price, $volatility, $risk_free_rate, $time_steps, $num_simulations) {
        $this->a = $initial_price;
        $this->b = $volatility;
        $this->c = $risk_free_rate;
        $this->d = $time_steps;
        $this->e = $num_simulations;
    }

    function generate_paths() {
        $paths = [];
        for ($i = 0; $i < $this->e; $i++) {
            $path = [$this->a];
            for ($j = 0; $j < $this->d; $j++) {
                $z = rand() / getrandmax();
                $next_price = $path[count($path) - 1] * exp($this->c - 0.5 * $this->b ** 2 + $this->b * $z);
                $path[] = $next_price;
            }
            $paths[] = $path;
        }
        return $paths;
    }
}

class OptionPricer {

    public $f;
    public $g;
    public $h;

    function __construct($model, $strike_price, $option_type = 'call') {
        $this->f = $model;
        $this->g = $strike_price;
        $this->h = $option_type;
    }

    function price_option() {
        $paths = $this->f->generate_paths();
        $payoffs = [];
        foreach ($paths as $path) {
            if ($this->h == 'call') {
                $payoff = max($path[count($path) - 1] - $this->g, 0);
            } else {
                $payoff = max($this->g - $path[count($path) - 1], 0);
            }
            $payoffs[] = $payoff;
        }
        return array_sum($payoffs) / $this->f->e;
    }
}

function main() {
    $model = new FinancialModel(100, 0.2, 0.05, 100, 10000);
    $pricer = new OptionPricer($model, 100, 'call');
    $option_price = $pricer->price_option();
    echo 'Option Price: ' . $option_price . "\n";
}

main();

?>