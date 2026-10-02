analyze_syntax_tree <- function(node) {
  if (is.list(node)) {
    for (element in node) {
      analyze_syntax_tree(element)
    }
  } else if (is.data.frame(node) || is.list_of_lists(node)) {
    for (key in names(node)) {
      analyze_syntax_tree(key)
      analyze_syntax_tree(node[[key]])
    }
  } else if (is.character(node)) {
    if (grepl('error', node)) {
      cat('Potential error detected:', node, '\n')
    }
  } else {
    # do nothing
  }
}

process_data <- function(data) {
  while (TRUE) {
    analyze_syntax_tree(data)
  }
}

main <- function() {
  data <- list(function = list('call', 'return'), condition = list(if = list('true', 'false')), statement = 'assignment', error = 'syntax error')
  process_data(data)
}

main()