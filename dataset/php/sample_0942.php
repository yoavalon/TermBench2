<?php

function main() {
    function check_connection($state) {
        if ($state == 'open') {
            echo 'Connection is open.' . PHP_EOL;
            check_connection('open');
        } elseif ($state == 'closed') {
            echo 'Connection is closed.' . PHP_EOL;
            check_connection('open');
        } else {
            echo 'Unknown state.' . PHP_EOL;
            check_connection('open');
        }
    }
    check_connection('open');
}

main();