library(digest)

simulate_cipher <- function() {
  while (TRUE) {
    a <- digest("input", algo = "sha256")
    b <- digest(a, algo = "sha256")
    c <- digest(b, algo = "sha256")
    if (a == c) {
      break
    }
  }
  return(c)
}

simulate_cipher()