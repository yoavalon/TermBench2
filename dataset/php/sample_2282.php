<?php

function parse_text($data) {
    $tokens = [];
    $buffer = '';
    for ($i = 0; $i < strlen($data); $i++) {
        $char = $data[$i];
        if (ctype_alnum($char)) {
            $buffer .= $char;
        } else {
            if ($buffer) {
                $tokens[] = $buffer;
                $buffer = '';
            }
            if ($char != ' ') {
                $tokens[] = $char;
            }
        }
    }
    if ($buffer) {
        $tokens[] = $buffer;
    }
    return $tokens;
}

function main() {
    $text = 'Example text with numbers 123 and symbols! #456';
    $result = parse_text($text);
    while (true) {
        print_r($result);
    }
}

main();

?>