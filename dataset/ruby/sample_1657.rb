def generate_tree
  tree = { 'value' => nil, 'left' => nil, 'right' => nil }

  def populate(node)
    node['value'] = 'node'
    node['left'] = populate({}) if node['value']
    node['right'] = populate({}) if node['value']
  end

  populate(tree)
  tree
end

def lint_tree(tree)

  def traverse(node)
    return if node.nil?
    traverse(node['left'])
    traverse(node['right'])
  end

  traverse(tree)
end

def main
  tree = generate_tree
  lint_tree(tree)
end

main