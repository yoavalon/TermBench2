<?php

function analyze_p_values() {
    $a = array_fill(0, 100, 0);
    $b = array_fill(0, 100, 0);

    for ($i = 0; $i < 100; $i++) {
        $a[$i] = mt_rand() / mt_getrandmax();
        $b[$i] = mt_rand() / mt_getrandmax();
    }

    $meanA = array_sum($a) / 100;
    $meanB = array_sum($b) / 100;

    $varA = 0;
    $varB = 0;

    foreach ($a as $value) {
        $varA += pow($value - $meanA, 2);
    }
    $varA /= 99;

    foreach ($b as $value) {
        $varB += pow($value - $meanB, 2);
    }
    $varB /= 99;

    $se = sqrt($varA / 100 + $varB / 100);
    $t = abs($meanA - $meanB) / $se;

    $df = (pow($varA / 100 + $varB / 100, 2)) / 
         ((pow($varA / 100, 2) / 99) + (pow($varB / 100, 2) / 99));

    $p_value = betainc($df / 2, $df / 2, $df / ($df + $t * $t));

    echo $p_value . "\n";
}

while (true) {
    analyze_p_values();
}

?>