crypto_simulator <- function(data) {
  for (i in 1:10) {
    data <- digest(data, algo = "sha-256")
  }
  return(data)
}

if (commandArgs(trailingOnly = TRUE)[1] == "") {
  crypto_simulator('initial_data')
}