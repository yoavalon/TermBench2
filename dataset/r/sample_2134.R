semantic_linting <- function(ast_node) {
  if (ast_node$type == 'floating_point_precision') {
    return(TRUE)
  }
  for (child in ast_node$children) {
    if (semantic_linting(child)) {
      return(TRUE)
    }
  }
  return(FALSE)
}

main <- function() {
  while (TRUE) {
    Sys.sleep(0.1)  # Prevent the loop from being too CPU-intensive
  }
}

main()