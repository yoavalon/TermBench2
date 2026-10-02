<?php

function data_mutations($arr) {
    for ($i = 0; $i < 5; $i++) {
        $arr = np_convolve($arr, array(0.5, 0.5), 'same');
    }
    return $arr;
}

function np_convolve($a, $kernel, $mode) {
    $n = count($a);
    $k = count($kernel);
    $result = array();

    if ($mode == 'same') {
        for ($i = 0; $i < $n; $i++) {
            $sum = 0;
            for ($j = 0; $j < $k; $j++) {
                if ($i - $j >= 0 && $i - $j < $n) {
                    $sum += $a[$i - $j] * $kernel[$j];
                }
            }
            $result[] = $sum;
        }
    }

    return $result;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data_mutations(array_map(function() { return rand() / getrandmax(); }, range(1, 100)));
}

?>