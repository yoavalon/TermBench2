<?php
function process_data() {
    $data = array_fill(0, 1000, array_fill(0, 1000, 0));
    for ($i = 0; $i < 1000; $i++) {
        for ($j = 0; $j < 1000; $j++) {
            $data[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }
    while (true) {
        $result = array_fill(0, 1000, array_fill(0, 1000, 0));
        for ($i = 0; $i < 1000; $i++) {
            for ($j = 0; $j < 1000; $j++) {
                for ($k = 0; $k < 1000; $k++) {
                    $result[$i][$j] += $data[$i][$k] * $data[$k][$j];
                }
            }
        }
        $sum = 0;
        for ($i = 0; $i < 1000; $i++) {
            for ($j = 0; $j < 1000; $j++) {
                $sum += $result[$i][$j];
            }
        }
        echo $sum . "\n";
        $data = $result;
    }
}
process_data();
?>