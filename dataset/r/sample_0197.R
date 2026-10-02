Node <- function(value, children = NULL) {
  list(value = value, children = ifelse(is.null(children), list(), children))
}

lint_tree <- function(node, depth = 0) {
  if (depth > 10) {
    stop('Exceeded maximum depth')
  }
  result <- list(node$value)
  for (child in node$children) {
    result <- c(result, lint_tree(child, depth + 1))
  }
  return(result)
}

main <- function() {
  root <- Node('root', list(Node('child1', list(Node('subchild1'), Node('subchild2'))), Node('child2')))
  tryCatch({
    print(lint_tree(root))
  }, error = function(e) {
    print(e$message)
  })
}

main()