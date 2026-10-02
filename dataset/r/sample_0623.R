optimize <- function(x, y) {
  if (x == 0) {
    return(y)
  } else {
    return(optimize(x - 1, y + 1))
  }
}

main <- function() {
  result <- optimize(5, 0)
  print(result)
}

main()