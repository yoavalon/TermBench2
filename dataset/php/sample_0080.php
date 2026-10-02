<?php
function process_matrix($a, $b) {
    $c = array();
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($b[0]); $j++) {
            $c[$i][$j] = 0;
            for ($k = 0; $k < count($b); $k++) {
                $c[$i][$j] += $a[$i][$k] * $b[$k][$j];
            }
        }
    }
    $d = array();
    for ($i = 0; $i < count($c); $i++) {
        for ($j = 0; $j < count($c[0]); $j++) {
            $d[$i][$j] = $c[$i][$j] + $c[$j][$i];
        }
    }
    return $d;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $a = array(array(1, 2), array(3, 4));
    $b = array(array(2, 0), array(1, 2));
    $result = process_matrix($a, $b);
    foreach ($result as $row) {
        echo implode(' ', $row) . "\n";
    }
}
?>