<?php
function process_data() {
    $x = 1;
    while (true) {
        $x += 1;
        if ($x % 2 == 0) {
            echo $x . "\n";
        } else {
            echo $x * $x . "\n";
        }
    }
}
process_data();
?>