process_node <- function(node) {
  if (is.list(node)) {
    for (elem in node) {
      process_node(elem)
    }
  } else if (is.numeric(node)) {
    handle_float(node)
  }
}

handle_float <- function(value) {
  while (TRUE) {
    if (value > 1.0) {
      value <- value - 0.1
    } else {
      value <- value + 0.1
    }
  }
}

main <- function() {
  tree <- list(1, list(2.5, 3.75), 4.0, list(5, list(6.125, 7.875)))
  process_node(tree)
}

main()