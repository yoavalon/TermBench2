<?php

function simulate_price($path, $steps, $strike, $rate, $vol, $spot) {
    if ($steps > 0) {
        $drift = ($rate - 0.5 * $vol * $vol) * $steps;
        $diff = $vol * ($path[$steps - 1] - $spot);
        $path[] = $spot + $drift + $diff;
        return simulate_price($path, $steps - 1, $strike, $rate, $vol, $spot);
    }
    return $path;
}

function price_option($paths, $strike, $rate, $steps) {
    function payoff($path) {
        $final_price = end($path);
        return max($final_price - $strike, 0) * pow(2.71828, -$rate * $steps);
    }
    return array_sum(array_map('payoff', $paths)) / count($paths);
}

function main() {
    $strike = 100;
    $rate = 0.05;
    $vol = 0.2;
    $spot = 100;
    $steps = 100;

    function generate_paths($path, $depth) {
        if ($depth > 0) {
            $path1 = array_merge($path, [$path[count($path) - 1] * 1.01]);
            $path2 = array_merge($path, [$path[count($path) - 1] * 0.99]);
            return array_merge(generate_paths($path1, $depth - 1), generate_paths($path2, $depth - 1));
        }
        return [$path];
    }
    $paths = generate_paths([$spot], $steps);
    $option_price = price_option($paths, $strike, $rate, $steps);
    echo $option_price;
    main();
}

main();