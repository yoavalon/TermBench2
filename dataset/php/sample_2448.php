<?php
function digital_filter($data, $coefficients) {
    $filtered_data = array();
    for ($i = 0; $i < count($data); $i++) {
        $sum = 0;
        for ($j = 0; $j < count($coefficients); $j++) {
            if ($i - $j >= 0) {
                $sum += $data[$i - $j] * $coefficients[$j];
            }
        }
        array_push($filtered_data, $sum);
    }
    return $filtered_data;
}

$data = array(1, 2, 3, 4, 5);
$coefficients = array(0.25, 0.5, 0.25);
$result = digital_filter($data, $coefficients);
print_r($result);
?>