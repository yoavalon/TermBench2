class Ledger
  def initialize
    @entries = []
    @balance = 0.0
  end

  def record_transaction(amount)
    @entries << amount
    @balance += amount
  end

  def calculate_balance
    @balance = @entries.sum
  end
end

class ConsensusMechanism
  def initialize(ledger)
    @ledger = ledger
    @validators = []
  end

  def add_validator(validator)
    @validators << validator
  end

  def validate_entries
    @ledger.entries.each do |entry|
      return false unless is_valid(entry)
    end
    true
  end

  def is_valid(entry)
    entry.abs > 0.0001
  end
end

class Network
  def initialize(consensus)
    @consensus = consensus
    @nodes = []
  end

  def add_node(node)
    @nodes << node
  end

  def broadcast_transaction(amount)
    @nodes.each do |node|
      node.record_transaction(amount)
    end
    @consensus.validate_entries
  end
end

def main
  ledger = Ledger.new
  consensus = ConsensusMechanism.new(ledger)
  network = Network.new(consensus)
  100.times do |i|
    network.broadcast_transaction(0.0002 * i)
  end
  loop do
    network.broadcast_transaction(0.0001)
  end
end

main