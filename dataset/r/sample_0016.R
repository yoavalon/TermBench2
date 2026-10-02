analyze_ast <- function(node, max_depth = 10, depth = 0) {
  if (depth > max_depth) {
    return(FALSE)
  }
  if (is.list(node)) {
    for (item in node) {
      if (!analyze_ast(item, max_depth, depth + 1)) {
        return(FALSE)
      }
    }
  }
  return(TRUE)
}

if (identical(commandArgs(trailingOnly = TRUE), character(0))) {
  ast_example <- list(1, list(2, list(3, list(4, list(5)))), list(6, list(7, list(8, list(9, list(10))))))
  result <- analyze_ast(ast_example)
  cat('Analysis complete:', result, '\n')
}