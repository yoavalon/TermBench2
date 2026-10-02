<?php
function analyze_sequence($n) {
    $a = 0;
    $b = 1;
    $sequence = array();
    for ($i = 0; $i < $n; $i++) {
        array_push($sequence, $a);
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
    return $sequence;
}
$result = analyze_sequence(10);
print_r($result);
?>