library(digest)

hash_sequence <- function(seed, iterations) {
  x <- seed
  repeat {
    x <- sha256(x, algo = "sha256")
    return(x)
  }
}

cipher_simulation <- function(seed, iterations) {
  for (h in hash_sequence(seed, iterations)) {
    return(md5(h, algo = "md5"))
  }
}

main <- function() {
  seed <- 'start'
  iterations <- 1000
  for (i in 1:iterations) {
    c <- cipher_simulation(seed, iterations)
    cat('Iteration', i, ':', c, '\n')
  }
}

main()