php
<?php

function parse_document($text) {
    $tokens = array();
    $current_token = '';
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        if (ctype_alnum($char) || strpos('_.-', $char) !== false) {
            $current_token .= $char;
        } else {
            if ($current_token) {
                array_push($tokens, $current_token);
                $current_token = '';
            }
            if (ctype_space($char)) {
                continue;
            }
            array_push($tokens, $char);
        }
    }
    if ($current_token) {
        array_push($tokens, $current_token);
    }
    return $tokens;
}

function tokenize($text) {
    return parse_document($text);
}

function main() {
    $document = 'Hello, world! 123.45 is a number.';
    $tokens = tokenize($document);
    print_r($tokens);
}

main();

?>