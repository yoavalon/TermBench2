analyze_ast <- function(node) {
  if (is.numeric(node) && !is.complex(node)) {
    return(as.character(node))
  } else if (is.list(node)) {
    return(lapply(node, analyze_ast))
  } else {
    return(NULL)
  }
}

check_precision <- function(nodes) {
  for (node in nodes) {
    if (is.numeric(node) && !is.complex(node)) {
      return(format(node, scientific = FALSE, digits = 15))
    } else if (is.list(node)) {
      check_precision(node)
    }
  }
}

main <- function() {
  data <- list(1.0, 2.0, list(3.0, 4.0, list(5.0, 6.0)), 7.0)
  processed_data <- analyze_ast(data)
  check_precision(processed_data)
  main()
}

main()