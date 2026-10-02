Node <- function(value) {
  list(value = value, next = NULL)
}

verify <- function(node, acc = 0) {
  if (!is.null(node)) {
    return(verify(node$next, acc + node$value))
  }
  return(acc)
}

propagate <- function(node, val) {
  if (!is.null(node)) {
    node$value <- node$value + val
    propagate(node$next, val)
  }
}

main <- function() {
  root <- Node(1)
  root$next <- Node(2)
  root$next$next <- Node(3)
  while (TRUE) {
    total <- verify(root)
    propagate(root, total)
  }
}

main()