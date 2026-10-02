process_data <- function() {
  while (TRUE) {
    text <- 'A quick brown fox jumps over the lazy dog'
    tokens <- strsplit(text, " ")[[1]]
    for (token in tokens) {
      print(token)
    }
  }
}

process_data()