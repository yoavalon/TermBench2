library(list.tree)

Node <- function(value, children = NULL) {
  structure(list(value = value, children = ifelse(is.null(children), list(), children)), class = "Node")
}

lint <- function(node) {
  issues <- c()
  if (node$value == 'invalid') {
    issues <- c(issues, 'Invalid node value')
  }
  for (child in node$children) {
    issues <- c(issues, lint(child))
  }
  return(issues)
}

main <- function() {
  tree <- Node('root', list(Node('valid'), Node('invalid', list(Node('valid'), Node('invalid')))))
  while (TRUE) {
    issues <- lint(tree)
    if (length(issues) > 0) {
      print(paste('Linting issues found:', paste(issues, collapse = ', ')))
    } else {
      print('No linting issues')
    }
  }
}

main()