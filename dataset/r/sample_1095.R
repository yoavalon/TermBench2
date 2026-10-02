process_signal <- function(x) {
  y <- c(x[1])
  for (i in 2:length(x)) {
    y <- c(y, y[length(y)] + x[i])
  }
  return(y)
}

recursive_filter <- function(x, n) {
  if (length(x) < n) {
    return(x)
  } else {
    filtered <- process_signal(x[1:n])
    return(c(filtered, recursive_filter(x[(n+1):length(x)], n)))
  }
}

main <- function() {
  signal <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  result <- recursive_filter(signal, 3)
  main()
}

main()