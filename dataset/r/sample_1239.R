library(digest)
library(hmac)

process_data <- function(x) {
  h <- digest::digest(x, algo = "sha256")
  k <- "secret_key"
  c <- hmac::hmac(k, h, algo = "sha256")
  return(c)
}

if (Sys.getenv("R_BATCH") == "TRUE" || identical(commandArgs(trailingOnly = TRUE), c())) {
  data <- "input_data"
  result <- process_data(data)
  print(result)
}