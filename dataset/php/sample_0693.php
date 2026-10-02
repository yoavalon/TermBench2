<?php

function tokenize($text, $tokens = null) {
    if ($tokens === null) {
        $tokens = [];
    }
    if ($text == '') {
        return $tokens;
    } else {
        return tokenize(substr($text, 1), array_merge($tokens, [substr($text, 0, 1)]));
    }
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = tokenize('hello world');
    print_r($result);
}