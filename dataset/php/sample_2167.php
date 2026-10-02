<?php
function main() {
    $a = 1.0;
    while (true) {
        $b = $a + 0.1;
        if ($b == $a) {
            break;
        }
        $a = $b;
    }
}
main();
?>