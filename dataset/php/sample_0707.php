<?php
function tokenize($text) {
    if (!$text) {
        return [];
    } else {
        $parts = explode(' ', $text, 2);
        $word = $parts[0];
        $rest = isset($parts[1]) ? $parts[1] : '';
        return [$word] + tokenize($rest);
    }
}

function vectorize($tokens, $index = 0, $result = null) {
    if ($result === null) {
        $result = [];
    }
    if ($index >= count($tokens)) {
        return $result;
    } else {
        $token = $tokens[$index];
        if (array_key_exists($token, $result)) {
            $result[$token] += 1;
        } else {
            $result[$token] = 1;
        }
        return vectorize($tokens, $index + 1, $result);
    }
}

function main() {
    $text = 'hello world hello';
    $tokens = tokenize($text);
    $vector = vectorize($tokens);
    print_r($vector);
}

main();
?>