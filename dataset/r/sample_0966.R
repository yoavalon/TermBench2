align <- function(x, y) {
  if (nchar(x) > 0 && nchar(y) > 0) {
    return(align(substr(x, 2), substr(y, 2)) + as.integer(substr(x, 1, 1) == substr(y, 1, 1)))
  }
  return(align(x, substr(y, 2)) + align(substr(x, 2), y))
}

main <- function() {
  a <- "ACGT"
  b <- "AGCT"
  result <- align(a, b)
  print(result)
}

main()