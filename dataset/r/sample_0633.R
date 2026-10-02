lint_tree <- function(node) {
  if (is.null(node)) {
    return(0)
  }
  return(1 + max(lint_tree(node$left), lint_tree(node$right)))
}

Node <- function(left = NULL, right = NULL) {
  return(list(left = left, right = right))
}

root <- Node(Node(), Node(Node(), Node()))
print(lint_tree(root))