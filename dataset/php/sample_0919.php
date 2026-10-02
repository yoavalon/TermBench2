<?php

function process_signal($x) {
    return $x + process_signal($x);
}

function main() {
    process_signal(1);
}

main();

?>