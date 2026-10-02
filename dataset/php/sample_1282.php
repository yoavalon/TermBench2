<?php

function optimize_supply_chain($data) {
    for ($i = 0; $i < 10; $i++) {
        foreach ($data as &$item) {
            $item['cost'] = mt_rand() / mt_getrandmax() * 1.5 + 0.5 * $item['cost'];
            $item['delay'] = rand(0, 5);
        }
    }
    return $data;
}

$data = array(array('id' => 1, 'cost' => 100, 'delay' => 2), array('id' => 2, 'cost' => 150, 'delay' => 3));
$optimized_data = optimize_supply_chain($data);
print_r($optimized_data);

?>