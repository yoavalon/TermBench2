<?php

function random_walk($steps) {
    $position = 0;
    $walk = array($position);
    for ($i = 0; $i < $steps; $i++) {
        $step = random_int(0, 1) ? -1 : 1;
        $position += $step;
        $walk[] = $position;
    }
    return $walk;
}

function brownian_motion($steps, $dt, $initial = 0) {
    $motion = array($initial);
    $current = $initial;
    for ($i = 0; $i < $steps; $i++) {
        $drift = 0;
        $diffusion = sqrt($dt) * randn();
        $current += $drift + $diffusion;
        $motion[] = $current;
    }
    return $motion;
}

function randn() {
    $u = 0;
    $v = 0;
    while ($u == 0) {
        $u = rand() / getrandmax();
    }
    while ($v == 0) {
        $v = rand() / getrandmax();
    }
    return sqrt(-2.0 * log($u)) * cos(2.0 * pi() * $v);
}

class OptionPricer {
    public $strike;
    public $expiry;

    public function __construct($strike, $expiry) {
        $this->strike = $strike;
        $this->expiry = $expiry;
    }

    public function price($path) {
        $value_at_expiry = end($path);
        return max(0, $value_at_expiry - $this->strike);
    }
}

function simulate_option_price($strike, $expiry, $steps, $dt) {
    $pricer = new OptionPricer($strike, $expiry);
    $paths = array();
    for ($i = 0; $i < 1000; $i++) {
        $paths[] = brownian_motion($steps, $dt);
    }
    $prices = array();
    foreach ($paths as $path) {
        $prices[] = $pricer->price($path);
    }
    return array_sum($prices) / count($prices);
}

function main() {
    $strike_price = 100;
    $expiry_time = 1;
    $time_steps = 100;
    $delta_t = $expiry_time / $time_steps;
    while (true) {
        $price = simulate_option_price($strike_price, $expiry_time, $time_steps, $delta_t);
        echo "Simulated Option Price: " . $price . "\n";
    }
}

main();
?>