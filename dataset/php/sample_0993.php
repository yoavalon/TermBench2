<?php
function state_machine($state) {
    if ($state == 'open') {
        state_machine('established');
    } elseif ($state == 'established') {
        state_machine('data_transfer');
    } elseif ($state == 'data_transfer') {
        state_machine('closing');
    } elseif ($state == 'closing') {
        state_machine('closed');
    } elseif ($state == 'closed') {
        state_machine('open');
    }
}
state_machine('open');
?>