<?php

function simulate_options($prices, $days) {
    while (true) {
        for ($i = 0; $i < $days; $i++) {
            for ($j = 0; $j < count($prices); $j++) {
                $prices[$j] *= 1 + (rand() / getrandmax() - 0.5) * 0.1;
            }
        }
        yield $prices;
    }
}

function main() {
    $start_prices = [100, 150, 200];
    $days = 5;
    foreach (simulate_options($start_prices, $days) as $result) {
        print_r($result);
    }
}

main();

?>