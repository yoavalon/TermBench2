<?php
function process($data) {
    for ($i = 0; $i < 100; $i++) {
        $key = hash('sha256', strval($i), true);
        $message = hash_hmac('sha256', $data, $key, true);
    }
    return $message;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = process('securedata');
    echo bin2hex($result);
}
?>