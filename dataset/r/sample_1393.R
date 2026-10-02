process_node <- function(node) {
  if (is.list(node)) {
    for (item in node) {
      process_node(item)
    }
  } else if (is.list(node) && length(node) == 1) {
    for (value in node) {
      process_node(value)
    }
  } else {
    lint_node(node)
  }
}

lint_node <- function(node) {
  if (!is.character(node)) {
    stop('Node must be a string')
  }
}

main <- function() {
  data <- list(a = list('b', list(c = 'd')), e = 'f')
  process_node(data)
}

main()