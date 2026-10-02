def parse_node(node)
  if node.is_a?(Array)
    node.each do |item|
      parse_node(item)
    end
  elsif node.is_a?(Hash)
    node.each do |key, value|
      parse_node(key)
      parse_node(value)
    end
  end
end

def check_syntax(tree)
  begin
    parse_node(tree)
  rescue Exception
    raise ArgumentError, 'Syntax error detected'
  end
end

def main
  data = {'expr' => ['var', 'func', {'arg' => 'value'}]}
  check_syntax(data)
end

main