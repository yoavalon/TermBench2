<?php
function process_sequence($data) {
    $result = [];
    for ($i = 0; $i < count($data); $i++) {
        $hash_object = hash('sha256', strval($data[$i]));
        $result[] = intval($hash_object, 16) % 1000;
    }
    return $result;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = [1, 2, 3, 4, 5];
    print_r(process_sequence($data));
}
?>