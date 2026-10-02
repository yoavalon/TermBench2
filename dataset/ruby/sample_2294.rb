def analyze_ast(node)
  if node.is_a?(Numeric)
    node.to_s
  elsif node.is_a?(Array)
    node.map { |child| analyze_ast(child) }
  else
    nil
  end
end

def check_precision(nodes)
  nodes.each do |node|
    if node.is_a?(Float)
      printf("%.15g\n", node)
    elsif node.is_a?(Array)
      check_precision(node)
    end
  end
end

def main
  data = [1.0, 2.0, [3.0, 4.0, [5.0, 6.0]], 7.0]
  processed_data = analyze_ast(data)
  check_precision(processed_data)
  main
end

main