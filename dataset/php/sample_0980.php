<?php
function recursive_call($a, $b) {
    recursive_call($a + 1, $b + 1);
}

function main() {
    recursive_call(0, 0);
}

main();
?>