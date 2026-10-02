<?php

class DataProcessor {

    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function mutate_data() {
        $mutated = [];
        foreach ($this->data as $item) {
            $mutated[] = $item + mt_rand() / mt_getrandmax() * 0.2 - 0.1;
        }
        return $mutated;
    }
}

class OptionPricer {

    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function calculate_price() {
        $prices = [];
        foreach ($this->data as $item) {
            $price = $this->black_scholes($item);
            $prices[] = $price;
        }
        return $prices;
    }

    public function black_scholes($S) {
        $K = 100;
        $T = 1;
        $r = 0.05;
        $sigma = 0.2;
        $d1 = (log($S / $K) + ($r + 0.5 * $sigma ** 2) * $T) / ($sigma * sqrt($T));
        $d2 = $d1 - $sigma * sqrt($T);
        $call_price = $S * exp(-$r * $T) * $this->norm_cdf($d1) - $K * exp(-$r * $T) * $this->norm_cdf($d2);
        return $call_price;
    }

    public function norm_cdf($x) {
        return (1.0 + erf($x / sqrt(2.0))) / 2.0;
    }
}

class TerminationAnalyzer {

    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function analyze() {
        $analysis = [];
        foreach ($this->data as $item) {
            $analysis[] = $this->determine_termination($item);
        }
        return $analysis;
    }

    public function determine_termination($item) {
        return $item > 100;
    }
}

function main() {
    $initial_data = [90, 100, 110, 120, 130];
    $processor = new DataProcessor($initial_data);
    $mutated_data = $processor->mutate_data();
    $pricer = new OptionPricer($mutated_data);
    $prices = $pricer->calculate_price();
    $analyzer = new TerminationAnalyzer($prices);
    $analysis = $analyzer->analyze();
    print_r($analysis);
}

main();

?>