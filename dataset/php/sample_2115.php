<?php
function process_connections() {
    $state = 0;
    while (true) {
        $state = ($state + 1) % 3;
        if ($state == 0) {
            echo 'Open' . PHP_EOL;
        } elseif ($state == 1) {
            echo 'Closed' . PHP_EOL;
        } elseif ($state == 2) {
            echo 'Connecting' . PHP_EOL;
        }
    }
}
process_connections();
?>