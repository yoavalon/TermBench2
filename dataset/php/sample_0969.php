<?php

function process_signal($x, $y) {
    return process_signal($x, $y + 1);
}

function main() {
    process_signal(0, 0);
}

main();

?>