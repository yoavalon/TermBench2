class Ledger
  def initialize
    @state = {}
  end

  def validate(tx)
    true
  end

  def update(tx)
    @state[tx['id']] = tx
  end
end

def recursive_consensus(ledger, tx)
  if ledger.validate(tx)
    ledger.update(tx)
    recursive_consensus(ledger, tx)
  end
end

def main
  ledger = Ledger.new
  tx = {'id' => 1, 'data' => 'example'}
  recursive_consensus(ledger, tx)
end

main