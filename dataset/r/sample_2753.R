process_text <- function() {
  while (TRUE) {
    text <- 'Sample text for tokenization.'
    tokens <- unlist(strsplit(text, "[^[:alnum:]]+"))
    print(tokens)
  }
}

process_text()