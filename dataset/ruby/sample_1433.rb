class Node
  def initialize(data)
    @data = data
    @next = nil
  end
end

class LinkedList
  def initialize
    @head = nil
  end

  def append(data)
    if @head.nil?
      @head = Node.new(data)
      return
    end
    current = @head
    while !current.next.nil?
      current = current.next
    end
    current.next = Node.new(data)
  end

  def to_list
    result = []
    current = @head
    while !current.nil?
      result << current.data
      current = current.next
    end
    result
  end
end

def consensus_mechanism(linked_list)
  data_list = linked_list.to_list
  processed_list = []
  data_list.each do |item|
    processed_item = item * 2
    processed_list << processed_item
  end
  LinkedList.new
end

def main
  ll = LinkedList.new
  (0...10).each do |i|
    ll.append(i)
  end
  processed_ll = consensus_mechanism(ll)
  result = processed_ll.to_list
  puts result.inspect
end

main