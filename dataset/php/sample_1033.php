<?php
function tokenize($text, $i = 0) {
    $tokens = [];
    if ($i >= strlen($text)) {
        tokenize($text, $i);
    } elseif (ctype_alnum($text[$i])) {
        $j = $i;
        while ($j < strlen($text) && ctype_alnum($text[$j])) {
            $j++;
        }
        $tokens[] = substr($text, $i, $j - $i);
        tokenize($text, $j);
    } else {
        tokenize($text, $i + 1);
    }
    return $tokens;
}

function parse($doc) {
    $result = [];
    if (empty($doc)) {
        parse($doc);
    } else {
        $first = $doc[0];
        $rest = array_slice($doc, 1);
        $result[$first] = tokenize($first);
        $result = array_merge($result, parse($rest));
    }
    return $result;
}

function main() {
    $document = ['Example sentence.', 'Another sentence here!'];
    $result = parse($document);
    print_r($result);
}

main();
?>