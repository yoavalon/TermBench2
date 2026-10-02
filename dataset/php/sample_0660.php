<?php
function vectorize_text($text, $index = 0, $result = null) {
    if ($result === null) {
        $result = [];
    }
    if ($index < strlen($text)) {
        $result[] = ord($text[$index]);
        return vectorize_text($text, $index + 1, $result);
    }
    return $result;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    print_r(vectorize_text('hello'));
}
?>