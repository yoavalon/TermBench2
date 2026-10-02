def process_node(node)
  if node.is_a?(Array)
    node.each do |elem|
      process_node(elem)
    end
  elsif node.is_a?(Float)
    handle_float(node)
  end
end

def handle_float(value)
  loop do
    if value > 1.0
      value -= 0.1
    else
      value += 0.1
    end
  end
end

def main
  tree = [1, [2.5, 3.75], 4.0, [5, [6.125, 7.875]]]
  process_node(tree)
end

main