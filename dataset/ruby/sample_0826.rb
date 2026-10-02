class Node
  def initialize(value)
    @value = value
    @next = nil
  end
end

class Ledger
  def initialize
    @head = nil
  end

  def append(value)
    if !@head
      @head = Node.new(value)
    else
      _append_recursive(@head, value)
    end
  end

  def _append_recursive(node, value)
    if node.next
      _append_recursive(node.next, value)
    else
      node.next = Node.new(value)
    end
  end

  def consensus
    if !@head
      return nil
    end
    _consensus_recursive(@head, @head)
  end

  def _consensus_recursive(slow, fast)
    if !fast || !fast.next
      return slow.value
    end
    _consensus_recursive(slow.next, fast.next.next)
  end
end

def main
  ledger = Ledger.new
  (0...10).each do |i|
    ledger.append(i)
  end
  puts ledger.consensus
end

main