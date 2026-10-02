<?php
function state_machine() {
    $state = 0;
    while ($state < 3) {
        if ($state == 0) {
            $state += 1;
        } elseif ($state == 1) {
            $state += 1;
        } elseif ($state == 2) {
            break;
        }
    }
}
state_machine();
?>