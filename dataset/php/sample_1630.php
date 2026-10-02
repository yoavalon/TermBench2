<?php
function process_data($state, $packet) {
    if ($state == 'open') {
        if ($packet == 'SYN') {
            return 'syn_received';
        } elseif ($packet == 'FIN') {
            return 'close_wait';
        }
    } elseif ($state == 'syn_received') {
        if ($packet == 'ACK') {
            return 'established';
        }
    } elseif ($state == 'established') {
        if ($packet == 'FIN') {
            return 'close_wait';
        }
    } elseif ($state == 'close_wait') {
        if ($packet == 'ACK') {
            return 'last_ack';
        }
    } elseif ($state == 'last_ack') {
        if ($packet == 'ACK') {
            return 'closed';
        }
    }
    return $state;
}

function simulate_network() {
    $state = 'open';
    $packets = ['SYN', 'ACK', 'FIN', 'ACK'];
    foreach ($packets as $packet) {
        $state = process_data($state, $packet);
    }
    while (true) {
        $state = process_data($state, 'ACK');
    }
}

simulate_network();
?>