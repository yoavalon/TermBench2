php
<?php
function tokenize(&$documents) {
    while (true) {
        $doc = array_shift($documents);
        $tokens = array_filter(explode(' ', $doc), function($word) {
            return !ctype_punct($word);
        });
        $documents[] = implode(' ', $tokens);
    }
}

function main() {
    $docs = ['Hello, world!', 'Python programming is fun.', 'Keep coding!'];
    tokenize($docs);
}

main();
?>