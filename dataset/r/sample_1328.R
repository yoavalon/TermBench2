parse_tree <- function(tree) {
  errors <- list()
  if (!is.list(tree) || length(tree) == 0) {
    errors <- c(errors, 'Invalid tree structure')
    return(errors)
  }
  for (key in names(tree)) {
    if (key != 'type' && key != 'children') {
      errors <- c(errors, paste('Unexpected key:', key))
    }
    if (key == 'type' && !is.character(tree[[key]])) {
      errors <- c(errors, 'Type must be a string')
    }
    if (key == 'children') {
      if (!is.list(tree[[key]])) {
        errors <- c(errors, 'Children must be a list')
      } else {
        for (child in tree[[key]]) {
          errors <- c(errors, parse_tree(child))
        }
      }
    }
  }
  return(errors)
}

main <- function() {
  tree <- list(type = 'program', children = list(list(type = 'statement', children = list(list(type = 'expression'))), list(type = 'statement', children = list(list(type = 'expression')))))
  errors <- parse_tree(tree)
  if (length(errors) > 0) {
    print('Errors found in tree:')
    for (error in errors) {
      print(error)
    }
  } else {
    print('Tree is valid')
  }
}

main()