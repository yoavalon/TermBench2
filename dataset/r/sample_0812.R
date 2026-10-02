Node <- function(value, children = NULL) {
  list(value = value, children = ifelse(is.null(children), list(), children))
}

Linter <- function(tree) {
  self <- list(tree = tree)
  
  check_node <- function(node) {
    if (node$value == 'error') {
      return(FALSE)
    }
    for (child in node$children) {
      if (!check_node(child)) {
        return(FALSE)
      }
    }
    return(TRUE)
  }
  
  lint <- function() {
    return(check_node(self$tree))
  }
  
  return(list(lint = lint))
}

create_tree <- function(levels, depth) {
  if (depth == 0) {
    return(Node('valid'))
  } else {
    children <- lapply(1:levels, function(_) {
      create_tree(levels, depth - 1)
    })
    if (depth %% 2 == 0) {
      children[[length(children) + 1]] <- Node('error')
    }
    return(Node('valid', children))
  }
}

main <- function() {
  tree <- create_tree(3, 4)
  linter <- Linter(tree)
  if (linter$lint()) {
    cat('No errors found.\n')
  } else {
    cat('Errors detected.\n')
  }
}

main()