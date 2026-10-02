hash_simulate <- function(x, n) {
  if (n == 0) {
    return(x)
  } else {
    return(hash_simulate(x + hash(x), n - 1))
  }
}

main <- function() {
  result <- hash_simulate(0, 3)
  print(result)
}

main()