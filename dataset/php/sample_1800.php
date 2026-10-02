<?php
class NetworkConnection {
    public $state;
    public $data;

    public function __construct() {
        $this->state = 'disconnected';
        $this->data = [];
    }

    public function connect() {
        if ($this->state == 'disconnected') {
            $this->state = 'connected';
            $this->data[] = 'connected';
        }
    }

    public function disconnect() {
        if ($this->state == 'connected') {
            $this->state = 'disconnected';
            $this->data[] = 'disconnected';
        }
    }

    public function send_data($packet) {
        if ($this->state == 'connected') {
            $this->data[] = 'sent:' . $packet;
        }
    }

    public function receive_data($packet) {
        if ($this->state == 'connected') {
            $this->data[] = 'received:' . $packet;
        }
    }
}

class NetworkManager {
    public $connection;
    public $actions;
    public $counter;

    public function __construct($connection) {
        $this->connection = $connection;
        $this->actions = ['connect', 'disconnect', 'send_data', 'receive_data'];
        $this->counter = 0;
    }

    public function perform_action($action, $packet = null) {
        if ($action == 'connect') {
            $this->connection->connect();
        } elseif ($action == 'disconnect') {
            $this->connection->disconnect();
        } elseif ($action == 'send_data' && $packet) {
            $this->connection->send_data($packet);
        } elseif ($action == 'receive_data' && $packet) {
            $this->connection->receive_data($packet);
        }
    }

    public function simulate() {
        while (true) {
            $action = $this->actions[$this->counter % count($this->actions)];
            if (in_array($action, ['send_data', 'receive_data'])) {
                $this->perform_action($action, 'packet_' . $this->counter);
            } else {
                $this->perform_action($action);
            }
            $this->counter += 1;
        }
    }
}

function main() {
    $connection = new NetworkConnection();
    $manager = new NetworkManager($connection);
    $manager->simulate();
}

main();