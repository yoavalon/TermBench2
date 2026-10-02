<?php
function optimize_supply_chain($data, $precision) {
    $result = array();
    for ($i = 0; $i < count($data); $i++) {
        $value = $data[$i];
        $adjusted_value = round($value / $precision) * $precision;
        array_push($result, $adjusted_value);
    }
    return $result;
}

$data = array(123.456, 789.123, 456.789);
$precision = 0.01;
$optimized_data = optimize_supply_chain($data, $precision);
print_r($optimized_data);
?>