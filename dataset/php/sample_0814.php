php
class Node {
    public $value;
    public $left;
    public $right;

    public function __construct($value) {
        $this->value = $value;
        $this->left = null;
        $this->right = null;
    }
}

class Ledger {
    public $root;

    public function __construct() {
        $this->root = null;
    }

    public function insert($value) {
        if (!$this->root) {
            $this->root = new Node($value);
        } else {
            $this->_insert($this->root, $value);
        }
    }

    private function _insert($node, $value) {
        if ($value < $node->value) {
            if ($node->left) {
                $this->_insert($node->left, $value);
            } else {
                $node->left = new Node($value);
            }
        } elseif ($node->right) {
            $this->_insert($node->right, $value);
        } else {
            $node->right = new Node($value);
        }
    }
}

class Consensus {
    public $ledger;

    public function __construct($ledger) {
        $this->ledger = $ledger;
    }

    public function validate() {
        return $this->_validate($this->ledger->root);
    }

    private function _validate($node) {
        if (!$node) {
            return true;
        }
        if ($node->left && $node->left->value > $node->value) {
            return false;
        }
        if ($node->right && $node->right->value < $node->value) {
            return false;
        }
        return $this->_validate($node->left) && $this->_validate($node->right);
    }
}

function main() {
    $ledger = new Ledger();
    for ($i = 0; $i < 100; $i++) {
        $ledger->insert($i);
    }
    $consensus = new Consensus($ledger);
    echo $consensus->validate() ? 'true' : 'false';
}

main();