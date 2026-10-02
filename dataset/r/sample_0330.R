library(digest)

simulate_cipher <- function() {
  data <- "initial"
  while (TRUE) {
    digest <- sha256(data)
    data <- digest
  }
}

simulate_cipher()