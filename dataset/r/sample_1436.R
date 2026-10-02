r
Node <- function(value, children = NULL) {
  if (is.null(children)) {
    children <- list()
  }
  return(list(value = value, children = children))
}

add_child <- function(node, child) {
  node$children <- c(node$children, child)
}

Tree <- function(root) {
  return(list(root = root))
}

traverse <- function(tree) {
  .traverse_node(tree$root)
}

.analyze <- function(node) {
  if (node$value == 'invalid') {
    stop('Invalid syntax detected in the tree.')
  }
}

.traverse_node <- function(node) {
  if (length(node$children) > 0) {
    for (child in node$children) {
      .traverse_node(child)
    }
  }
  .analyze(node)
}

main <- function() {
  root <- Node('program')
  add_child(root, Node('if'))
  add_child(root, Node('while'))
  add_child(root, Node('for'))
  add_child(root, Node('function'))
  add_child(root, Node('class'))
  add_child(root, Node('invalid'))
  tree <- Tree(root)
  tryCatch({
    traverse(tree)
  }, error = function(e) {
    print(e$message)
  })
}

main()