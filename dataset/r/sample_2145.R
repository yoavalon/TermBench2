library(digest)

simulate_cipher <- function() {
  while (TRUE) {
    data <- "secret_message"
    hex_dig <- digest(data, algo = "sha256", serialize = FALSE)
    print(hex_dig)
  }
}

simulate_cipher()