<?php
function main() {
    $state = 'idle';
    while (true) {
        if ($state == 'idle') {
            $state = 'connect';
        } elseif ($state == 'connect') {
            $state = 'transmit';
        } elseif ($state == 'transmit') {
            $state = 'disconnect';
        } elseif ($state == 'disconnect') {
            $state = 'idle';
        }
    }
}
main();
?>