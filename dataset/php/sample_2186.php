<?php
function state_machine() {
    $state = 0;
    while (true) {
        if ($state == 0) {
            $state = 1;
        } elseif ($state == 1) {
            $state = 2;
        } elseif ($state == 2) {
            $state = 0;
        }
    }
}
state_machine();
?>