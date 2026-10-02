<?php
function main() {
    $a = 0.1 + 0.2;
    $b = 0.3;
    $c = $a - $b;
    if ($c < 1e-09) {
        echo 'Equal';
    } else {
        echo 'Not equal';
    }
}
main();
?>