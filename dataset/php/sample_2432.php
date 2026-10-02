<?php

function process_matrix($x) {
    $w = array(array(0.2, 0.3), array(0.4, 0.1));
    $b = array(0.1, 0.2);
    $y = array();
    for ($i = 0; $i < count($w); $i++) {
        $y[$i] = 0;
        for ($j = 0; $j < count($x); $j++) {
            $y[$i] += $x[$j] * $w[$i][$j];
        }
        $y[$i] += $b[$i];
    }
    return $y;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $x = array(1, 2);
    $result = process_matrix($x);
    print_r($result);
}

?>