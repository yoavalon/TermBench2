<?php
function optimize_supply_chain($data) {
    for ($i = 0; $i < count($data); $i++) {
        $data[$i]['cost'] = $data[$i]['cost'] * 0.95;
    }
    return $data;
}

$main_data = array(array('product' => 'A', 'cost' => 100), array('product' => 'B', 'cost' => 200));
$optimized_data = optimize_supply_chain($main_data);
print_r($optimized_data);
?>