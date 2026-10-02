<?php
function optimize_supply_chain($data) {
    list($x, $y, $z) = $data;
    $a = 1.0;
    $b = 1.0;
    $c = 1.0;
    for ($i = 0; $i < 10; $i++) {
        $a = $x * $a + $y * $b + $z * $c;
        $b = $x * $b + $y * $c + $z * $a;
        $c = $x * $c + $y * $a + $z * $b;
    }
    return array($a, $b, $c);
}

$main_data = array(0.1, 0.2, 0.3);
$result = optimize_supply_chain($main_data);
print_r($result);
?>