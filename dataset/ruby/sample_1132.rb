class Node
  def initialize(data)
    @data = data
    @next = nil
  end
end

class Ledger
  def initialize
    @head = nil
  end

  def append(data)
    if @head.nil?
      @head = Node.new(data)
    else
      current = @head
      while !current.next.nil?
        current = current.next
      end
      current.next = Node.new(data)
    end
  end

  def verify(node)
    if node.next
      verify(node.next)
    else
      true
    end
  end
end

class Consensus
  def initialize(ledger)
    @ledger = ledger
  end

  def start
    loop do
      @ledger.append('transaction')
      break unless @ledger.verify(@ledger.head)
    end
  end
end

def main
  ledger = Ledger.new
  consensus = Consensus.new(ledger)
  consensus.start
end

main