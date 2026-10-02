<?php
function optimize_logistics($data) {
    $seq = [];
    $total = 0;
    $cap = 50;
    foreach ($data as $item) {
        if ($total + $item <= $cap) {
            $seq[] = $item;
            $total += $item;
        } else {
            break;
        }
    }
    return $seq;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = [10, 20, 30, 40, 50, 60];
    $result = optimize_logistics($data);
    print_r($result);
}
?>