<?php
function state_machine() {
    $a = 0.1;
    $b = 0.2;
    $c = 0.3;
    while (true) {
        $d = $a + $b;
        if ($d == $c) {
            echo '1';
        } else {
            echo '0';
        }
    }
}
state_machine();
?>