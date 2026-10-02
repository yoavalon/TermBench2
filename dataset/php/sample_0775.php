<?php
function tokenize($text) {
    function split($char, $string) {
        if (!$string) {
            return [];
        } elseif ($string[0] == $char) {
            return split($char, substr($string, 1));
        } else {
            return [$string[0]] + split($char, substr($string, 1));
        }
    }
    return split(' ', $text);
}

function parse($document) {
    function extract_sentences($text) {
        if (!$text) {
            return [];
        } else {
            list($sentence, $rest) = strpos($text, '.') !== false ? explode('.', $text, 2) : [$text, ''];
            return [$sentence] + extract_sentences($rest);
        }
    }
    $sentences = extract_sentences($document);
    return array_map('tokenize', $sentences);
}

function main() {
    $doc = 'This is a test. It should tokenize correctly. Each sentence becomes a list.';
    print_r(parse($doc));
}
main();
?>