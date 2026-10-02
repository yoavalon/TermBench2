<?php
function state_machine($state, $count) {
    if ($count == 0) {
        return 'Idle';
    } elseif ($state == 'Connecting') {
        return state_machine('Connected', $count - 1);
    } elseif ($state == 'Connected') {
        return state_machine('Disconnecting', $count - 1);
    } elseif ($state == 'Disconnecting') {
        return state_machine('Idle', $count - 1);
    } else {
        return 'Invalid State';
    }
}

echo state_machine('Connecting', 3);
?>