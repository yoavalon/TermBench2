<?php
function state_machine($state) {
    if ($state == 0) {
        state_machine(1);
    } elseif ($state == 1) {
        state_machine(2);
    } elseif ($state == 2) {
        state_machine(0);
    }
}
state_machine(0);
?>