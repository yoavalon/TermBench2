<?php

function calculate_cost($data) {
    $total = 0.0;
    foreach ($data as $item) {
        $total += $item['quantity'] * $item['price'];
    }
    return $total;
}

function optimize_logistics($data, $iterations) {
    for ($i = 0; $i < $iterations; $i++) {
        foreach ($data as &$item) {
            $item['quantity'] += rand() / getrandmax() * 2 - 1;
            $item['price'] += rand() / getrandmax() * 0.2 - 0.1;
        }
    }
}

function main() {
    $data = [['quantity' => 100.0, 'price' => 10.0], ['quantity' => 200.0, 'price' => 5.0]];
    while (true) {
        optimize_logistics($data, 10);
        $cost = calculate_cost($data);
        echo "Current Cost: " . $cost . "\n";
    }
}

main();
?>