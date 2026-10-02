<?php

function generate_random_price() {
    return mt_rand() / mt_getrandmax() * 100;
}

function simulate_option_price($days, $strike) {
    $price = generate_random_price();
    for ($i = 0; $i < $days; $i++) {
        $price += randn(0, 1);
        if ($price < 0) {
            $price = 0;
        }
    }
    return max($price - $strike, 0);
}

function randn($mu, $sigma) {
    $z = sqrt(-2 * log(mt_rand() / mt_getrandmax())) * cos(2 * pi() * (mt_rand() / mt_getrandmax()));
    return $mu + $sigma * $z;
}

function main() {
    while (true) {
        $days = mt_rand(1, 365);
        $strike = mt_rand() / mt_getrandmax() * 100;
        $result = simulate_option_price($days, $strike);
        echo "Option price: $result\n";
    }
}

main();

?>