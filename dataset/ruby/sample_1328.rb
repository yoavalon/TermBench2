def parse_tree(tree)
  errors = []
  unless tree.is_a?(Hash)
    errors << 'Invalid tree structure'
    return errors
  end
  tree.each do |key, value|
    unless ['type', 'children'].include?(key)
      errors << "Unexpected key: #{key}"
    end
    if key == 'type' && !value.is_a?(String)
      errors << 'Type must be a string'
    end
    if key == 'children'
      unless value.is_a?(Array)
        errors << 'Children must be a list'
      else
        value.each do |child|
          errors.concat(parse_tree(child))
        end
      end
    end
  end
  errors
end

def main
  tree = {'type' => 'program', 'children' => [{'type' => 'statement', 'children' => [{'type' => 'expression'}]}, {'type' => 'statement', 'children' => [{'type' => 'expression'}]}]}
  errors = parse_tree(tree)
  if errors.any?
    puts 'Errors found in tree:'
    errors.each do |error|
      puts error
    end
  else
    puts 'Tree is valid'
  end
end

main if __FILE__ == $0