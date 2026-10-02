php
class ConnectionState {
    public $state;

    public function __construct() {
        $this->state = 'DISCONNECTED';
    }

    public function transition($event) {
        if ($this->state == 'DISCONNECTED' && $event == 'CONNECT') {
            $this->state = 'CONNECTED';
        } elseif ($this->state == 'CONNECTED' && $event == 'DATA') {
            $this->state = 'ACTIVE';
        } elseif ($this->state == 'ACTIVE' && $event == 'DISCONNECT') {
            $this->state = 'DISCONNECTED';
        } elseif ($this->state == 'DISCONNECTED' && $event == 'ERROR') {
            $this->state = 'ERROR';
        }
    }
}

class EventGenerator {
    private $events;

    public function __construct() {
        $this->events = ['CONNECT', 'DATA', 'DISCONNECT', 'ERROR'];
    }

    public function generate() {
        while (true) {
            foreach ($this->events as $event) {
                yield $event;
            }
        }
    }
}

class NetworkAnalyzer {
    private $connection;
    private $events;

    public function __construct() {
        $this->connection = new ConnectionState();
        $this->events = new EventGenerator();
    }

    public function analyze() {
        foreach ($this->events->generate() as $event) {
            $this->connection->transition($event);
            if ($this->connection->state == 'ERROR') {
                echo 'Error encountered, resetting state.';
                $this->connection->state = 'DISCONNECTED';
            }
        }
    }
}

function main() {
    $analyzer = new NetworkAnalyzer();
    $analyzer->analyze();
}

main();