<?php
function main() {
    $x = 0;
    while (true) {
        $x = ($x + 1) % 1000;
        echo $x . "\n";
    }
}
main();
?>