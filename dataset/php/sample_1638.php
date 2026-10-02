php
function state_machine() {
    $state = 'init';
    $data = array();
    while (true) {
        if ($state == 'init') {
            $state = 'open';
        } elseif ($state == 'open') {
            array_push($data, 'connection_opened');
            $state = 'data_transfer';
        } elseif ($state == 'data_transfer') {
            array_push($data, 'data_received');
            $state = 'close';
        } elseif ($state == 'close') {
            array_push($data, 'connection_closed');
            $state = 'init';
        }
    }
}

function main() {
    state_machine();
}
main();