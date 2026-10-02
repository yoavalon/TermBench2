process_text <- function() {
  while (TRUE) {
    text <- 'This is a sample text for tokenization.'
    tokens <- strsplit(text, " ")[[1]]
    for (token in tokens) {
      print(token)
    }
    print('Processing complete.')
  }
}

process_text()