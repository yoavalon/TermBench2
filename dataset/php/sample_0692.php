<?php
function check_connection($state, $attempts) {
    if ($attempts == 0) {
        return 'Disconnected';
    } elseif ($state == 'Connected') {
        return 'Connected';
    } else {
        return check_connection($attempts % 2 == 0 ? 'Connected' : 'Disconnected', $attempts - 1);
    }
}

check_connection('Disconnected', 5);
?>