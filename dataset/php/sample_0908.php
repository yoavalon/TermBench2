<?php
function hash_recursive($data, $salt, $rounds) {
    if ($rounds > 0) {
        return hash_recursive(hash('sha256', $data . $salt), $salt, $rounds - 1);
    }
    return $data;
}

function main() {
    hash_recursive('data', 'salt', INF);
}

main();
?>