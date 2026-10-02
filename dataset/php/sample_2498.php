<?php
function simulate_cipher($n) {
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $n; $i++) {
        list($a, $b) = array($b, ($a + $b) % 256);
    }
    return $b;
}

function main() {
    $result = simulate_cipher(10);
    echo $result;
}
main();
?>