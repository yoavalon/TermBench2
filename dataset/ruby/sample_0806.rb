class Node
  def initialize(value, next_node = nil)
    @value = value
    @next_node = next_node
  end

  def get_value
    @value
  end

  def get_next
    @next_node
  end

  def set_next(next_node)
    @next_node = next_node
  end
end

class Ledger
  def initialize(initial_value)
    @head = Node.new(initial_value)
  end

  def append(value)
    _append_recursive(@head, value)
  end

  def _append_recursive(current, value)
    if current.get_next.nil?
      current.set_next(Node.new(value))
    else
      _append_recursive(current.get_next, value)
    end
  end

  def consensus(target)
    _consensus_recursive(@head, target)
  end

  def _consensus_recursive(current, target)
    return false if current.nil?
    return true if current.get_value == target
    _consensus_recursive(current.get_next, target)
  end
end

def main
  ledger = Ledger.new(1)
  (2..10).each { |i| ledger.append(i) }
  (1..11).each do |i|
    if ledger.consensus(i)
      puts "Consensus reached for #{i}"
    else
      puts "No consensus for #{i}"
    end
  end
end

main if __FILE__ == $0