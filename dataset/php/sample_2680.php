<?php

function generate_prices($num_days, $initial_price, $volatility) {
    $prices = [$initial_price];
    for ($i = 0; $i < $num_days - 1; $i++) {
        $change = mt_rand() / mt_getrandmax() * 2 - 1;
        $new_price = $prices[count($prices) - 1] * (1 + $change * $volatility);
        $prices[] = $new_price;
    }
    return $prices;
}

function calculate_payoffs($prices, $strike_price, $call_or_put) {
    $payoffs = [];
    foreach ($prices as $price) {
        if ($call_or_put == 'call') {
            $payoff = max($price - $strike_price, 0);
        } else {
            $payoff = max($strike_price - $price, 0);
        }
        $payoffs[] = $payoff;
    }
    return $payoffs;
}

function monte_carlo_pricing($num_simulations, $num_days, $initial_price, $strike_price, $volatility, $call_or_put, $risk_free_rate, $time_to_maturity) {
    $total_payoff = 0;
    for ($i = 0; $i < $num_simulations; $i++) {
        $prices = generate_prices($num_days, $initial_price, $volatility);
        $payoffs = calculate_payoffs($prices, $strike_price, $call_or_put);
        $discounted_payoff = array_sum($payoffs) / count($payoffs) * pow(1 + $risk_free_rate, -$time_to_maturity);
        $total_payoff += $discounted_payoff;
    }
    return $total_payoff / $num_simulations;
}

function main() {
    $num_simulations = 1000;
    $num_days = 365;
    $initial_price = 100;
    $strike_price = 100;
    $volatility = 0.2;
    $call_or_put = 'call';
    $risk_free_rate = 0.05;
    $time_to_maturity = 1;
    $option_price = monte_carlo_pricing($num_simulations, $num_days, $initial_price, $strike_price, $volatility, $call_or_put, $risk_free_rate, $time_to_maturity);
    echo "Option price: " . $option_price . "\n";
}

main();

?>