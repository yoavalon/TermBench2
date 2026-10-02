<?php
function optimize_supply_chain($data, $precision) {
    $result = array();
    foreach ($data as $item) {
        $adjusted_value = round($item['value'], $precision);
        $result[] = array('id' => $item['id'], 'adjusted_value' => $adjusted_value);
    }
    return $result;
}
$data = array(array('id' => 1, 'value' => 123.456789), array('id' => 2, 'value' => 987.654321));
$precision = 3;
$optimized_data = optimize_supply_chain($data, $precision);
print_r($optimized_data);
?>