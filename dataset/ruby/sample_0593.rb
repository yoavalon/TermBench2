class Node
  def initialize(value)
    @value = value
    @next = nil
  end
end

class LinkedList
  def initialize
    @head = nil
  end

  def append(value)
    new_node = Node.new(value)
    if @head.nil?
      @head = new_node
    else
      current = @head
      while current.next
        current = current.next
      end
      current.next = new_node
    end
  end

  def display
    current = @head
    while current
      print("#{current.value} -> ")
      current = current.next
    end
    puts 'None'
  end
end

class ConsensusMechanism
  def initialize(linked_list)
    @linked_list = linked_list
  end

  def update_values
    current = @linked_list.head
    while current
      current.value += 1
      current = current.next
    end
  end

  def run
    loop do
      update_values
      @linked_list.display
    end
  end
end

def main
  ll = LinkedList.new
  5.times { |i| ll.append(i) }
  cm = ConsensusMechanism.new(ll)
  cm.run
end

main