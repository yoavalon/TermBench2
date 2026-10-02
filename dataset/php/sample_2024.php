<?php

class RandomGenerator {
    public $seed;

    public function __construct($seed) {
        $this->seed = $seed;
    }

    public function generate() {
        $this->seed = (1664525 * $this->seed + 1013904223) % 4294967296;
        return $this->seed / 4294967296;
    }
}

class OptionPricer {
    public $random_gen;
    public $S0;
    public $K;
    public $T;
    public $r;
    public $sigma;
    public $N;

    public function __construct($random_gen, $S0, $K, $T, $r, $sigma, $N) {
        $this->random_gen = $random_gen;
        $this->S0 = $S0;
        $this->K = $K;
        $this->T = $T;
        $this->r = $r;
        $this->sigma = $sigma;
        $this->N = $N;
    }

    public function simulate_paths() {
        $paths = [];
        $dt = $this->T / $this->N;
        for ($i = 0; $i < 1000; $i++) {
            $S = $this->S0;
            $path = [$S];
            for ($j = 0; $j < $this->N; $j++) {
                $Z = $this->random_gen->generate();
                $S += $S * $this->r * $dt + $S * $this->sigma * sqrt($dt) * (2 * $Z - 1);
                $path[] = $S;
            }
            $paths[] = $path;
        }
        return $paths;
    }

    public function price() {
        $paths = $this->simulate_paths();
        $payoff_sum = 0;
        foreach ($paths as $path) {
            $payoff = max($path[count($path) - 1] - $this->K, 0);
            $payoff_sum += $payoff;
        }
        return exp(-$this->r * $this->T) * ($payoff_sum / count($paths));
    }
}

function main() {
    $seed = 12345;
    $random_gen = new RandomGenerator($seed);
    $pricer = new OptionPricer($random_gen, 100, 100, 1, 0.05, 0.2, 100);
    $option_price = $pricer->price();
    echo 'Option Price: ' . $option_price . "\n";
}

main();
?>