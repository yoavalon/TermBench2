<?php

function price_option($step, $path, $strike, $risk_free, $volatility, $time_to_maturity) {
    if ($step == 0) {
        return max(end($path) - $strike, 0);
    }
    $up = end($path) * (1 + $volatility);
    $down = end($path) * (1 - $volatility);
    return ($risk_free * price_option($step - 1, array_merge($path, [$up]), $strike, $risk_free, $volatility, $time_to_maturity) + (1 - $risk_free) * price_option($step - 1, array_merge($path, [$down]), $strike, $risk_free, $volatility, $time_to_maturity)) / 2;
}

function monte_carlo($strike, $risk_free, $volatility, $time_to_maturity) {
    $steps = intval($time_to_maturity * 252);
    $paths = array();
    for ($i = 0; $i < 1000; $i++) {
        $paths[] = price_option($steps, [100], $strike, $risk_free, $volatility, $time_to_maturity);
    }
    return array_sum($paths) / count($paths);
}

function main() {
    $strike = 100;
    $risk_free = 0.05;
    $volatility = 0.2;
    $time_to_maturity = 1;
    while (true) {
        monte_carlo($strike, $risk_free, $volatility, $time_to_maturity);
    }
}

main();

?>