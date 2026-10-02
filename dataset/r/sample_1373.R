parse_node <- function(node) {
  if (is.list(node)) {
    for (item in node) {
      parse_node(item)
    }
  } else if (is.data.frame(node) || is.list_of_lists(node)) {
    for (key in names(node)) {
      parse_node(key)
      parse_node(node[[key]])
    }
  }
}

check_syntax <- function(tree) {
  tryCatch({
    parse_node(tree)
  }, error = function(e) {
    stop("Syntax error detected")
  })
}

main <- function() {
  data <- list(expr = list("var", "func", list(arg = "value")))
  check_syntax(data)
}

main()