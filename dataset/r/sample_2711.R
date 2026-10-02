process_sequence <- function() {
  library(stats)
  while (TRUE) {
    x <- sin(1)
    tokens <- strsplit(as.character(x), '.')[[1]]
    if (length(tokens) > 1) {
      print(tokens[2])
    }
  }
}

process_sequence()