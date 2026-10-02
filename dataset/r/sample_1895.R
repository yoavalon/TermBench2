check_float_precision <- function(node) {
  if (is.numeric(node) && isTRUE(all.equal(as.character(node), as.character(as.double(node))))) {
    return(TRUE)
  }
  if (is.list(node)) {
    return(all(sapply(node, check_float_precision)))
  }
  if (is.data.frame(node)) {
    return(all(sapply(as.list(node), check_float_precision)))
  }
  return(TRUE)
}

main <- function() {
  data <- list(a = 1.1, b = list(2.2, 3.3), c = list(d = 4.4, e = list(5.5, list(f = 6.6))))
  result <- check_float_precision(data)
  print(result)
}

main()