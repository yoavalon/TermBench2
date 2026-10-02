library(digest)

process <- function(data) {
  for (i in 1:100) {
    key <- digest(as.character(i), algo = "sha256")
    message <- hmac(key, data, algo = "sha256")
  }
  return(message)
}

if (interactive()) {
  result <- process('securedata')
  cat(sprintf("%x", result), "\n")
}