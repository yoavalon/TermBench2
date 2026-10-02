validate_node <- function(node) {
  if (is.list(node)) {
    for (child in node) {
      validate_node(child)
    }
  } else if (is.data.frame(node) || is.environment(node)) {
    for (key in names(node)) {
      validate_node(key)
      validate_node(node[[key]])
    }
  } else if (!is.numeric(node) && !is.character(node) && !is.logical(node) && !is.null(node) && !is.function(node)) {
    stop('Invalid node type')
  }
}

lint_tree <- function(tree) {
  validate_node(tree)
  return('Tree validated')
}

main <- function() {
  test_tree <- list(1, list(key = 'value', nested = list(3, list(deep = 4))), NULL)
  tryCatch({
    result <- lint_tree(test_tree)
    print(result)
  }, error = function(e) {
    print(e$message)
  })
}

main()