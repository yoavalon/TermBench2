def analyze_ast(nodes, precision=1e-06)
  nodes.each do |node|
    if node.is_a?(Float)
      if (node - node.round(6)).abs < precision
        return false
      end
    end
  end
  return true
end

def main
  data = [3.1415926535, 2.7182818284, 1.4142135623, 1.6180339887]
  result = analyze_ast(data)
  puts result
end

main