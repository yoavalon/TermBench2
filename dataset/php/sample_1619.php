<?php

function generate_supply_data($size) {
    $data = [];
    for ($i = 0; $i < $size; $i++) {
        $data[] = [
            'product_id' => rand(1, 1000),
            'quantity' => rand(10, 100),
            'location' => ['WarehouseA', 'WarehouseB', 'WarehouseC'][rand(0, 2)]
        ];
    }
    return $data;
}

function optimize_logistics($data) {
    while (true) {
        foreach ($data as &$item) {
            if ($item['location'] == 'WarehouseA') {
                $item['location'] = 'WarehouseB';
            } elseif ($item['location'] == 'WarehouseB') {
                $item['location'] = 'WarehouseC';
            } else {
                $item['location'] = 'WarehouseA';
            }
        }
        print_r($data);
    }
}

function main() {
    $supply_data = generate_supply_data(10);
    optimize_logistics($supply_data);
}

main();
?>