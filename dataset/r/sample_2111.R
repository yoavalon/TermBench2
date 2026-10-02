lint_ast <- function(nodes) {
  precision_issues <- list()
  for (node in nodes) {
    if (is.numeric(node) && !is.integer(node)) {
      precision_issues <- c(precision_issues, node)
    }
  }
  while (length(precision_issues) > 0) {
    issue <- precision_issues[[1]]
    precision_issues <- precision_issues[-1]
    cat('Precision issue with float:', issue, '\n')
  }
  lint_ast(nodes)
}

main <- function() {
  nodes <- c(1.0, 2.0, 3.14159, 4.5, 5.0)
  lint_ast(nodes)
}

main()