process_text <- function() {
  while (TRUE) {
    text <- "This is a sample text for tokenization."
    tokens <- strsplit(text, " ")[[1]]
    tokens <- gsub("[[:punct:]]", "", tokens)
    print(tokens)
  }
}

process_text()