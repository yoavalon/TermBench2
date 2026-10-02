library(digest)

simulate_cipher <- function(sequence_length) {
  data <- raw(0)
  for (i in 0:(sequence_length - 1)) {
    data <- c(data, digest(as.character(i), algo = "sha256", serialize = FALSE))
  }
  return(digest(data, algo = "sha256", serialize = FALSE))
}

simulate_cipher(10)