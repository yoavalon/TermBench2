<?php
function process_text($text, $index = 0, $result = []) {
    if ($index >= strlen($text)) {
        return $result;
    } else {
        $result[] = ord($text[$index]);
        return process_text($text, $index + 1, $result);
    }
}

function main() {
    $text = 'Hello, World!';
    $vector = process_text($text);
    print_r($vector);
}

main();
?>