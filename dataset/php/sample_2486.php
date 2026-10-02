<?php
function optimize_supply_chain($n) {
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $n; $i++) {
        $temp = $b;
        $b = $a + $b;
        $a = $temp;
    }
    return $a;
}

$result = optimize_supply_chain(10);
echo $result;
?>