<?php

function process_data($data) {
    $hash_function = hash_init('sha256');
    hash_update($hash_function, $data);
    $hashed_data = hash_final($hash_function, true);
    $cipher = [];
    for ($i = 0; $i < strlen($data); $i++) {
        $cipher[] = ord($data[$i]) ^ ord($hashed_data[$i]);
    }
    $result = '';
    foreach ($cipher as $c) {
        $result .= chr($c);
    }
    return $result;
}

$data = 'Example Data';
$processed = process_data($data);
echo $processed;

?>