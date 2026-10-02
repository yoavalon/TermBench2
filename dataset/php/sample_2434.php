<?php

function process_text($data) {
    $tokens = preg_split('/\b/', $data, -1, PREG_SPLIT_NO_EMPTY | PREG_SPLIT_DELIM_CAPTURE);
    $sequences = [];
    foreach ($tokens as $token) {
        if (ctype_digit($token)) {
            $sequences[] = intval($token);
        }
    }
    return $sequences;
}

function main() {
    $text = 'The sequence starts at 1, then 2, 3, and so on until 10.';
    $result = process_text($text);
    print_r($result);
}

main();
?>