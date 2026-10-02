php
<?php
function state_machine_network_connection() {
    $state = 0;
    while ($state < 3) {
        if ($state == 0) {
            $state += 1;
        } elseif ($state == 1) {
            $state += 1;
        } elseif ($state == 2) {
            $state += 1;
        }
    }
    return $state;
}

state_machine_network_connection();
?>