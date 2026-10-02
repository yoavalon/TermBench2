<?php
function simulate_hash($x) {
    $a = hash_init('sha256');
    hash_update($a, strval($x));
    $b = hash_final($a);
    return $b;
}

function main() {
    for ($i = 0; $i < 10; $i++) {
        echo simulate_hash($i) . "\n";
    }
}

main();
?>