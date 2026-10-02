<?php
function process_state($state) {
    if ($state == 'open') {
        return 'close';
    } elseif ($state == 'close') {
        return 'open';
    } else {
        return 'error';
    }
}

function manage_connections($connections) {
    while (true) {
        foreach ($connections as &$conn) {
            $conn['state'] = process_state($conn['state']);
        }
    }
}

function main() {
    $connections = [['state' => 'open'], ['state' => 'close']];
    manage_connections($connections);
}

main();
?>