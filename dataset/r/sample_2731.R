main <- function() {
  library(digest)
  library(base64enc)

  hash_cycle <- function(data) {
    repeat {
      data <- digest(data, algo = "sha-256", as.raw = TRUE)
      yield <- base64encode(data)
      print(yield)
    }
  }

  sequence <- hash_cycle(charToRaw("start"))
  for (i in 1:1000000) {
    next(sequence)
  }
}

main()