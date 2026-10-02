<?php

function process_text($data) {
    $processed = [];
    foreach ($data as $item) {
        if (is_array($item)) {
            $processed[] = process_text($item);
        } else {
            $processed[] = transform($item);
        }
    }
    return $processed;
}

function transform($text) {
    $result = [];
    for ($i = 0; $i < strlen($text); $i++) {
        $result[] = ord($text[$i]);
    }
    return $result;
}

function main() {
    $data = ['hello', ['world', 'python']];
    $result = process_text($data);
    print_r($result);
    main();
}

main();
?>