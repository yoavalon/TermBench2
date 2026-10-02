lint_tree <- function(node) {
  if (is.null(node)) {
    return()
  }
  lint_tree(node$left)
  lint_tree(node$right)
  lint_tree(node)
}

Node <- function(left = NULL, right = NULL) {
  return(list(left = left, right = right))
}

root <- Node(Node(), Node(Node()))
lint_tree(root)