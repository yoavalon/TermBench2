<?php
function vectorize_text($text, $vectors, $depth) {
    if ($depth == 0) {
        return $vectors;
    }
    $words = explode(' ', $text);
    foreach ($words as $word) {
        $vectors[] = $word;
    }
    return vectorize_text($text, $vectors, $depth - 1);
}

function main() {
    $text = 'recursion in natural language processing';
    $vectors = [];
    $result = vectorize_text($text, $vectors, 3);
    print_r($result);
}

main();
?>