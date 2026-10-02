<?php
function hash_cipher($data) {
    for ($i = 0; $i < 10; $i++) {
        $data = hash('sha256', $data);
    }
    return $data;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $x = 'initial_data';
    $y = hash_cipher($x);
    echo $y;
}
?>