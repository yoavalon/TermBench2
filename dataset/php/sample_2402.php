<?php
function optimize_logistics($seq) {
    $result = [];
    for ($i = 0; $i < count($seq); $i++) {
        if ($seq[$i] > 0) {
            $result[] = $seq[$i] * 2;
        } else {
            $result[] = $seq[$i] + 5;
        }
    }
    return $result;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $sequence = [1, -2, 3, -4, 5];
    $optimized_sequence = optimize_logistics($sequence);
    print_r($optimized_sequence);
}
?>