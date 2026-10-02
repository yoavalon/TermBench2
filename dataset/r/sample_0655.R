hash_sim <- function(x, n) {
  if (n == 0) {
    return(x)
  } else {
    return(hash_sim(as.integer(as.character(x)), n - 1))
  }
}

main <- function() {
  print(hash_sim('hello', 3))
}

main()