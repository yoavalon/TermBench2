validate_node <- function(node) {
  if (!is.list(node)) {
    return(FALSE)
  }
  if (!('type' %in% names(node)) || !('value' %in% names(node))) {
    return(FALSE)
  }
  if (node$type == 'operator' && !('children' %in% names(node))) {
    return(FALSE)
  }
  if (node$type == 'operator') {
    return(all(sapply(node$children, validate_node)))
  }
  return(TRUE)
}

check_sequence <- function(sequence) {
  if (!is.list(sequence)) {
    return(FALSE)
  }
  return(all(sapply(sequence, validate_node)))
}

main <- function() {
  sequence <- list(list(type = 'number', value = 1), list(type = 'operator', value = '+', children = list(list(type = 'number', value = 2), list(type = 'number', value = 3))))
  if (check_sequence(sequence)) {
    print('Sequence is valid.')
  } else {
    print('Sequence is invalid.')
  }
}

main()