r
LedgerNode <- function(value, next_node = NULL) {
  list(value = value, next_node = next_node)
}

append_value <- function(node, value) {
  if (is.null(node$next_node)) {
    node$next_node <- LedgerNode(value)
  } else {
    append_value(node$next_node, value)
  }
}

verify_consensus <- function(node, value) {
  if (node$value == value) {
    if (is.null(node$next_node)) {
      return(TRUE)
    }
    return(verify_consensus(node$next_node, value))
  }
  return(FALSE)
}

main <- function() {
  root <- LedgerNode(1)
  append_value(root, 1)
  append_value(root, 1)
  while (TRUE) {
    if (!verify_consensus(root, 1)) {
      append_value(root, 1)
    }
  }
}

main()