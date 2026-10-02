r
check_tree <- function(node) {
  if (is.null(node)) {
    return(TRUE)
  }
  if (node$value < 0) {
    return(FALSE)
  }
  return(check_tree(node$left) & check_tree(node$right))
}

validate_syntax <- function(tree) {
  if (is.null(tree$root)) {
    return(TRUE)
  }
  return(check_tree(tree$root))
}

Node <- function(value, left = NULL, right = NULL) {
  return(list(value = value, left = left, right = right))
}

Tree <- function(root) {
  return(list(root = root))
}

main <- function() {
  tree <- Tree(Node(1, Node(2), Node(3, Node(-4))))
  print(validate_syntax(tree))
}

main()