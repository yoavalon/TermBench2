lint_tree <- function(node) {
  if (is.null(node)) {
    return(TRUE)
  }
  if (!lint_tree(node$left)) {
    return(FALSE)
  }
  if (!lint_tree(node$right)) {
    return(FALSE)
  }
  return(TRUE)
}

Node <- function(left = NULL, right = NULL) {
  return(list(left = left, right = right))
}

root <- Node(Node(), Node(Node(), Node()))
print(lint_tree(root))