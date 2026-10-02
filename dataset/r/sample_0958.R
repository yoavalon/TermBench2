crypto_sim <- function(a, b) {
  if (a != 0) {
    crypto_sim(b, a ^ (a << 5) ^ (a >> 3))
  } else {
    return(b)
  }
}

main <- function() {
  crypto_sim(1, 2)
}

main()