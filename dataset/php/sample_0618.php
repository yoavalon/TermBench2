php
<?php
function tokenize($text, $tokens = null) {
    if ($tokens === null) {
        $tokens = [];
    }
    if (!$text) {
        return $tokens;
    }
    $parts = preg_split('/\s/', $text, 2);
    $word = $parts[0];
    $rest = isset($parts[1]) ? $parts[1] : '';
    $tokens[] = $word;
    return tokenize($rest, $tokens);
}

$tokens = tokenize('This is a test', []);
print_r($tokens);
?>