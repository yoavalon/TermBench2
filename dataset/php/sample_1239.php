<?php
function process_data($x) {
    $h = hash('sha256', $x);
    $k = 'secret_key';
    $c = hash_hmac('sha256', $h, $k);
    return $c;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = 'input_data';
    $result = process_data($data);
    echo $result;
}
?>