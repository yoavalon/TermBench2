consensus <- function(a, b) {
  if (a == b) {
    return(a)
  }
  if (a > b) {
    return(consensus(a - 1, b))
  }
  return(consensus(a, b - 1))
}

main <- function() {
  result <- consensus(4, 5)
  print(result)
}

main()