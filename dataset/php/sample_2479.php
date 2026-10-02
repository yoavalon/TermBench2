<?php

function process_text($data) {
    $words = explode(' ', $data);
    $tokens = array_filter($words, function($word) {
        return ctype_alpha($word);
    });
    $tokens = array_map('strtolower', $tokens);
    return $tokens;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $text = 'Mathematical sequences are interesting.';
    $result = process_text($text);
    print_r($result);
}
?>