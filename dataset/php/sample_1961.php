<?php
function parse_document($text) {
    $tokens = array();
    $buffer = '';
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        if (ctype_alnum($char) || $char == '.') {
            $buffer .= $char;
        } else {
            if ($buffer != '') {
                array_push($tokens, $buffer);
                $buffer = '';
            }
            if ($char != ' ') {
                array_push($tokens, $char);
            }
        }
    }
    if ($buffer != '') {
        array_push($tokens, $buffer);
    }
    return $tokens;
}

function main() {
    $document = 'Example 1.23 and 4.567.';
    $tokens = parse_document($document);
    print_r($tokens);
}

main();
?>