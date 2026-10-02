<?php

class OptionPricer {
    public $strike;
    public $spot;
    public $vol;
    public $rate;
    public $div;
    public $T;

    public function __construct($strike, $spot, $vol, $rate, $div, $T) {
        $this->strike = $strike;
        $this->spot = $spot;
        $this->vol = $vol;
        $this->rate = $rate;
        $this->div = $div;
        $this->T = $T;
    }

    public function d1($S, $K, $T, $r, $q, $sigma) {
        return (log($S / $K) + ($r - $q + 0.5 * pow($sigma, 2)) * $T) / ($sigma * sqrt($T));
    }

    public function d2($d1, $sigma, $T) {
        return $d1 - $sigma * sqrt($T);
    }

    public function call_price($S, $K, $T, $r, $q, $sigma) {
        if ($T <= 0) {
            return max(0, $S - $K);
        }
        $d1_val = $this->d1($S, $K, $T, $r, $q, $sigma);
        $d2_val = $this->d2($d1_val, $sigma, $T);
        return $S * exp(-$q * $T) * (0.5 * (1 + erf($d1_val / sqrt(2)))) - $K * exp(-$r * $T) * (0.5 * (1 + erf($d2_val / sqrt(2))));
    }
}

class MonteCarloSimulator {
    public $pricer;
    public $paths;
    public $steps;

    public function __construct($pricer, $paths, $steps) {
        $this->pricer = $pricer;
        $this->paths = $paths;
        $this->steps = $steps;
    }

    public function simulate() {
        $prices = [];
        for ($i = 0; $i < $this->paths; $i++) {
            $price_path = $this->pricer->spot;
            for ($j = 1; $j < $this->steps; $j++) {
                $price_path = $this->_step($price_path);
            }
            $prices[] = $price_path;
        }
        return $prices;
    }

    private function _step($S) {
        $dt = $this->pricer->T / $this->steps;
        $dS = $S * ($this->pricer->rate - $this->pricer->div) * $dt + $S * $this->pricer->vol * sqrt($dt) * randn();
        return $S + $dS;
    }
}

function randn() {
    $mean = 0;
    $stddev = 1;
    return sqrt(-2 * log(rand())) * cos(2 * pi() * rand()) * $stddev + $mean;
}

function main() {
    $strike = 100;
    $spot = 100;
    $vol = 0.2;
    $rate = 0.05;
    $div = 0.02;
    $T = 1;
    $paths = 1000;
    $steps = 100;
    $pricer = new OptionPricer($strike, $spot, $vol, $rate, $div, $T);
    $simulator = new MonteCarloSimulator($pricer, $paths, $steps);
    $final_prices = $simulator->simulate();
    $option_value = array_sum(array_map(function($price) use ($pricer, $strike, $T, $rate, $div, $vol) {
        return $pricer->call_price($price, $strike, $T, $rate, $div, $vol);
    }, $final_prices)) / $paths;
    echo $option_value;
}

main();
?>