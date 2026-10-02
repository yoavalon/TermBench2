<?php
function tokenize($sentence, $index = 0, $tokens = []) {
    if ($index >= strlen($sentence) || $sentence[$index] == ' ') {
        return $tokens;
    }
    if ($index == 0 || $sentence[$index - 1] == ' ') {
        $start = $index;
    }
    while ($index < strlen($sentence) && $sentence[$index] != ' ') {
        $index += 1;
    }
    $tokens[] = substr($sentence, $start, $index - $start);
    return tokenize($sentence, $index, $tokens);
}

function main() {
    $sentence = 'example sentence for tokenization';
    $result = tokenize($sentence);
    print_r($result);
}
main();
?>