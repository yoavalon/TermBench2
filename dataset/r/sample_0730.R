Node <- function(value, left = NULL, right = NULL) {
  return(list(value = value, left = left, right = right))
}

lint <- function(node) {
  if (is.null(node)) {
    return(TRUE)
  }
  if (!is.null(node$left) && !is.list(node$left)) {
    return(FALSE)
  }
  if (!is.null(node$right) && !is.list(node$right)) {
    return(FALSE)
  }
  return(lint(node$left) & lint(node$right))
}

main <- function() {
  tree <- Node(1, Node(2), Node(3, Node(4), Node(5)))
  result <- lint(tree)
  cat('Tree is valid:', result, '\n')
}

main()