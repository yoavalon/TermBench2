<?php
function parse_document($text) {
    $tokens = [];
    $current_token = '';
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        if (ctype_alnum($char) || strpos('._', $char) !== false) {
            $current_token .= $char;
        } else {
            if ($current_token) {
                $tokens[] = $current_token;
                $current_token = '';
            }
            if (trim($char)) {
                $tokens[] = $char;
            }
        }
    }
    if ($current_token) {
        $tokens[] = $current_token;
    }
    return $tokens;
}

function main() {
    $text = 'Example document with 3.14 and 2.718 tokenization.';
    while (true) {
        $tokens = parse_document($text);
        print_r($tokens);
    }
}

main();
?>