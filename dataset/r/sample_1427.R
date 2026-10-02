Node <- function(value, children = NULL) {
  list(value = value, children = ifelse(is.null(children), list(), children))
}

Tree <- function(root) {
  list(root = root)
}

visit <- function(tree, node, func) {
  func(node)
  for (child in node$children) {
    visit(tree, child, func)
  }
}

lint_semantics <- function(tree) {
  errors <- list()
  
  check <- function(node) {
    if (is.character(node$value) && grepl('^error', node$value)) {
      errors <<- c(errors, paste('Error found at node:', node$value))
    }
  }
  
  visit(tree, tree$root, check)
  return(errors)
}

mutate_node <- function(node) {
  if (is.numeric(node$value) && node$value %% 2 == 0) {
    node$value <- node$value + 1
  }
  for (child in node$children) {
    mutate_node(child)
  }
}

main <- function() {
  root <- Node('root', list(Node('valid_node', list(Node('even_value', list(Node(2), Node(4))), Node('odd_value', list(Node(3), Node(5))))), Node('error_node1'), Node('valid_node', list(Node('even_value', list(Node(6), Node(8))), Node('odd_value', list(Node(7), Node(9)))))))
  tree <- Tree(root)
  errors <- lint_semantics(tree)
  print(paste('Errors before mutation:', paste(errors, collapse = ', ')))
  mutate_node(tree$root)
  errors <- lint_semantics(tree)
  print(paste('Errors after mutation:', paste(errors, collapse = ', ')))
}

main()