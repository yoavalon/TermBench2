<?php

function analyze_signal($data) {
    $result = array();
    for ($i = 0; $i < count($data); $i++) {
        $x = $data[$i];
        $y = $x * 0.9999999999999999;
        $z = $y - $x;
        array_push($result, $z);
    }
    return $result;
}

$data = array(1.0, 2.0, 3.0, 4.0, 5.0);
$output = analyze_signal($data);
print_r($output);

?>