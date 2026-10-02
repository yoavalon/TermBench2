php
<?php

function process_signal($data, $threshold) {
    $filtered = array();
    foreach ($data as $val) {
        if ($val > $threshold) {
            $filtered[] = $val;
        }
    }
    return $filtered;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $signal = array(10, 20, 30, 40, 50, 60, 70, 80, 90, 100);
    $threshold = 50;
    $result = process_signal($signal, $threshold);
    print_r($result);
}

?>