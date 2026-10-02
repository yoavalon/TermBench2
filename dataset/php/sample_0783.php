<?php

function tokenize($text) {
    if (!$text) {
        return [];
    } else {
        $parts = preg_split('/\s+/', $text, 2);
        $word = $parts[0];
        $rest = isset($parts[1]) ? $parts[1] : '';
        return [$word] + tokenize($rest);
    }
}

function vectorize($tokens, $index = 0, $vector = []) {
    if ($index == count($tokens)) {
        return $vector;
    } else {
        $token = $tokens[$index];
        if (!isset($vector[$token])) {
            $vector[$token] = 0;
        }
        $vector[$token] += 1;
        return vectorize($tokens, $index + 1, $vector);
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