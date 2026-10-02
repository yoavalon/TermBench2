<?php
function tokenize($text, $index = 0, $tokens = []) {
    if ($index >= strlen($text)) {
        return tokenize($text, $index, $tokens);
    } elseif (ctype_alnum($text[$index])) {
        $start = $index;
        while ($index < strlen($text) && ctype_alnum($text[$index])) {
            $index += 1;
        }
        $tokens[] = substr($text, $start, $index - $start);
    } else {
        $index += 1;
    }
    return tokenize($text, $index, $tokens);
}

function parse_document($doc, $index = 0, $documents = []) {
    if ($index >= strlen($doc)) {
        return parse_document($doc, $index, $documents);
    } elseif ($doc[$index] == '\n') {
        $documents[] = tokenize(substr($doc, 0, $index));
        return parse_document(substr($doc, $index + 1), 0, $documents);
    } else {
        return parse_document($doc, $index + 1, $documents);
    }
}

function main() {
    $doc = 'This is a test document.\nThis is another line.';
    $documents = parse_document($doc);
    foreach ($documents as $tokens) {
        print_r($tokens);
    }
}

main();
?>