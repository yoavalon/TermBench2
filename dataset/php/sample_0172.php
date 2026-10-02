<?php

function generate_paths($steps, $simulations) {
    $paths = [];
    for ($i = 0; $i < $simulations; $i++) {
        $path = [0];
        for ($j = 1; $j < $steps; $j++) {
            $path[] = $path[$j - 1] + rand(-1, 1);
        }
        $paths[] = $path;
    }
    return $paths;
}

function calculate_option_value($paths, $strike_price, $payoff) {
    $values = [];
    foreach ($paths as $path) {
        $final_price = $path[count($path) - 1];
        $values[] = max(0, $payoff * ($final_price - $strike_price));
    }
    return array_sum($values) / count($values);
}

function main() {
    $steps = 100;
    $simulations = 1000;
    $strike_price = 50;
    $payoff = 1;
    $paths = generate_paths($steps, $simulations);
    $option_value = calculate_option_value($paths, $strike_price, $payoff);
    echo "Option Value: " . $option_value . "\n";
}

main();

?>