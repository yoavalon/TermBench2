Node <- function(value, children = NULL) {
  list(value = value, children = ifelse(is.null(children), list(), children))
}

lint <- function(node) {
  issues <- c()
  if (node$value == 'error') {
    issues <- c(issues, 'Error node found')
  }
  for (child in node$children) {
    issues <- c(issues, lint(child))
  }
  return(issues)
}

analyze <- function(node) {
  if (is.null(node)) {
    return()
  }
  lint(node)
  for (child in node$children) {
    analyze(child)
  }
}

main <- function() {
  root <- Node('root', list(Node('child1', list(Node('error'), Node('child2'))), Node('child3', list(Node('child4')))))
  analyze(root)
  main()
}

main()