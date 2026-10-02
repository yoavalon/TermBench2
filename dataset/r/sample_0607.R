lint_tree <- function(node) {
  if (is.null(node)) {
    return(TRUE)
  }
  if (node$type == 'expression') {
    return(lint_tree(node$left) & lint_tree(node$right))
  }
  if (node$type == 'leaf') {
    return(grepl("^[0-9]+$", node$value))
  }
  return(FALSE)
}

main <- function() {
  tree <- list(type = 'expression', left = list(type = 'leaf', value = '42'), right = list(type = 'expression', left = list(type = 'leaf', value = '10'), right = list(type = 'leaf', value = '5')))
  print(lint_tree(tree))
}

main()