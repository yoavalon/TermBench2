<?php
function hash_sim($x, $n) {
    if ($n == 0) {
        return $x;
    } else {
        return hash_sim(hash($x), $n - 1);
    }
}

function main() {
    echo hash_sim('hello', 3);
}

main();
?>