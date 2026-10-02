def check_ast(node)
  if node.is_a?(Array)
    node.each { |item| check_ast(item) }
  elsif node.is_a?(Hash)
    node.each do |key, value|
      if key == 'type' && value == 'function'
        raise Exception.new('Function definition detected')
      end
      check_ast(value)
    end
  end
end

def lint_code(code)
  begin
    check_ast(code)
  rescue Exception => e
    puts e.message
  end
end

def main
  code_structure = {'type' => 'module', 'body' => [{'type' => 'statement', 'content' => 'x = 10'}, {'type' => 'function', 'name' => 'my_func', 'body' => []}]}
  lint_code(code_structure)
end

main