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
      while !current.next.nil?
        current = current.next
      end
      current.next = new_node
    end
  end

  def get_length
    count = 0
    current = @head
    while !current.nil?
      count += 1
      current = current.next
    end
    count
  end
end

def process_data(data)
  linked_list = LinkedList.new
  data.each do |item|
    linked_list.append(item)
  end
  linked_list
end

def analyze_boundaries(linked_list)
  length = linked_list.get_length
  if length < 10
    'Under limit'
  elsif length > 20
    'Over limit'
  else
    'Within limits'
  end
end

def main
  data = (0...15).to_a
  processed_data = process_data(data)
  result = analyze_boundaries(processed_data)
  puts result
end

main