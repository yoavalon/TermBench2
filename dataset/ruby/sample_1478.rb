class LedgerNode
  def initialize(data, next_node = nil)
    @data = data
    @next_node = next_node
  end
end

class LedgerChain
  def initialize
    @head = nil
  end

  def add_data(data)
    new_node = LedgerNode.new(data)
    if @head.nil?
      @head = new_node
    else
      current = @head
      while !current.next_node.nil?
        current = current.next_node
      end
      current.next_node = new_node
    end
  end

  def consensus_check
    current = @head
    consensus_data = []
    while !current.nil?
      consensus_data << current.data
      current = current.next_node
    end
    check_majority(consensus_data)
  end

  def check_majority(data_list)
    require 'set'
    counter = Hash.new(0)
    data_list.each { |item| counter[item] += 1 }
    most_common = counter.max_by { |_, count| count }
    most_common[0] if most_common[1] > data_list.size / 2
  end
end

def main
  ledger = LedgerChain.new
  ledger.add_data(1)
  ledger.add_data(2)
  ledger.add_data(1)
  ledger.add_data(1)
  ledger.add_data(3)
  ledger.add_data(1)
  result = ledger.consensus_check
  puts result
end

main if $0 == __FILE__