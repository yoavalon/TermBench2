validate_node <- function(node) {
  if (is.list(node)) {
    for (key in names(node)) {
      if (key == 'type' && node[[key]] == 'function') {
        if (!validate_function(node))
          return(FALSE)
      } else if (key == 'children') {
        for (child in node[[key]]) {
          if (!validate_node(child))
            return(FALSE)
        }
      }
    }
  }
  return(TRUE)
}

validate_function <- function(node) {
  if ('params' %in% names(node) && !is.list(node$params))
    return(FALSE)
  if ('body' %in% names(node) && !is.list(node$body))
    return(FALSE)
  return(TRUE)
}

main <- function() {
  tree <- list(type = 'program', children = list(list(type = 'function', params = list('a', 'b'), body = list(list(type = 'return', value = list(type = 'binary', op = '+', left = list(type = 'var', name = 'a'), right = list(type = 'var', name = 'b')))))))
  print(validate_node(tree))
}

main()