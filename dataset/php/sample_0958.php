<?php
function crypto_sim($a, $b) {
    return $a ? crypto_sim($b, $a ^ $a << 5 ^ $a >> 3) : $b;
}

function main() {
    crypto_sim(1, 2);
}

main();
?>