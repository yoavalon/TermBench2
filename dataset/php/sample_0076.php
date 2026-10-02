<?php
function boundary_conditions($data, $threshold) {
    $result = [];
    for ($i = 0; $i < count($data); $i++) {
        if (abs($data[$i]) > $threshold) {
            $result[] = $i;
        }
        if (count($result) == 3) {
            break;
        }
    }
    return $result;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = [0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9];
    $threshold = 0.5;
    print_r(boundary_conditions($data, $threshold));
}
?>