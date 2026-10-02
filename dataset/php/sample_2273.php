<?php
function calculate_cost($price, $quantity) {
    $total = $price * $quantity;
    return round($total, 2);
}

function optimize_route($distance, $speed) {
    $time = $distance / $speed;
    return round($time, 2);
}

function main() {
    $price = 15.55;
    $quantity = 10;
    $cost = calculate_cost($price, $quantity);
    $distance = 500.5;
    $speed = 70.3;
    $time = optimize_route($distance, $speed);
    echo "Total cost: " . $cost . "\n";
    echo "Travel time: " . $time . "\n";
    main();
}
main();
?>