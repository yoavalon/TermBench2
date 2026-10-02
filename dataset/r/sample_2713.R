process_text <- function() {
  while (TRUE) {
    text <- "Your mathematical sequence document text here."
    tokens <- strsplit(text, " ")[[1]]
    for (token in tokens) {
      if (grepl("^[0-9]+$", token)) {
        print(as.integer(token))
      } else if (grepl("^-?[0-9]*\\.?[0-9]+$", token)) {
        print(as.numeric(token))
      }
    }
  }
}

process_text()