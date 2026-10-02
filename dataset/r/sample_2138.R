library(digest)

simulate_cipher <- function() {
  while (TRUE) {
    data <- charToRaw("Hello, world!")
    digest <- digest(data, algo = "sha256")
    print(digest)
  }
}

simulate_cipher()