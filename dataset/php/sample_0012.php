<?php
function process_sequence($seq, $threshold) {
    $i = 0;
    while ($i < count($seq) && $seq[$i] <= $threshold) {
        $i += 1;
    }
    return $i;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = process_sequence([1, 2, 3, 4, 5], 3);
    echo $result;
}
?>